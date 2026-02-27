/* Copyright 2021 iwatake2222
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <algorithm>
#include "pico/stdlib.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"
#include "micro_features/model.h"
#include "micro_features/yes_micro_features_data.h"
#include "micro_features/no_micro_features_data.h"
#include "micro_features/micro_model_settings.h"
#include "micro_features/model.h"
#include "feature_provider.h"

#include "utility_macro.h"
#include "audio_provider.h"

// MACRO for Debug
#define TAG_SCOPE "main"
#define PRINT(...)   UTILITY_MACRO_PRINT(TAG_SCOPE, __VA_ARGS__)
#define PRINT_E(...) UTILITY_MACRO_PRINT_E(TAG_SCOPE, __VA_ARGS__)

// Global variables
static tflite::MicroErrorReporter micro_error_reporter;
static tflite::ErrorReporter* error_reporter = &micro_error_reporter;

// Interpreter Generation
static tflite::MicroInterpreter* createStaticInterpreter(void)
{
    constexpr int32_t kTensorArenaSize = 1088 + 24 + 5968;
    static uint8_t tensor_arena[kTensorArenaSize];
    const tflite::Model* model = tflite::GetModel(g_model);
    if (model->version() != TFLITE_SCHEMA_VERSION) {
        PRINT_E("Model provided is schema version %d not equal to supported version %d.", model->version(), TFLITE_SCHEMA_VERSION);
        return nullptr;
    }

    static tflite::AllOpsResolver resolver;
    static tflite::MicroInterpreter static_interpreter(model, resolver, tensor_arena, kTensorArenaSize, error_reporter);
    tflite::MicroInterpreter* interpreter = &static_interpreter;
    TfLiteStatus allocate_status = interpreter->AllocateTensors();
    if (allocate_status != kTfLiteOk) {
        PRINT_E("AllocateTensors() failed");
        return nullptr;
    }

    TfLiteTensor* input = interpreter->input(0);
    TfLiteTensor* output = interpreter->output(0);
    if (input->bytes != kFeatureElementCount) {
        PRINT_E("Input size seems wrong: %d\n", static_cast<int32_t>(input->bytes));
        return nullptr;
    }

    if (output->bytes != kCategoryCount) {
        PRINT_E("Output size seems wrong: %d\n", static_cast<int32_t>(output->bytes));
        return nullptr;
    }

    return interpreter;
}

int main(void) {

    stdio_init_all();
    sleep_ms(1000);		// wait until UART connected
    PRINT("Hello, world!\n");

    // Create interpreter
    tflite::MicroInterpreter* interpreter = createStaticInterpreter();
    if (!interpreter) {
        PRINT_E("createStaticInterpreter failed\n");
        // HALT();
    }
    TfLiteTensor* input = interpreter->input(0);
    TfLiteTensor* output = interpreter->output(0);

    // Create feature provider
    static int8_t feature_buffer[kFeatureElementCount];
    static FeatureProvider feature_provider(kFeatureElementCount, feature_buffer);
    static AudioProvider audio_provider;
    audio_provider.Initialize();
    int32_t previous_time = 0;

    while (1) {
        // Generate feature
        audio_provider.DebugWriteData(32);
        const int32_t current_time = audio_provider.GetLatestAudioTimestamp();
        if (current_time < 0 || current_time == previous_time) continue;

        int32_t how_many_new_slices = 0;
        TfLiteStatus feature_status = feature_provider.PopulateFeatureData(&audio_provider, error_reporter, previous_time, current_time, &how_many_new_slices);
        if (feature_status != kTfLiteOk) {
            // It may reach here when underflow happens
            PRINT_E("Feature generation failed\n");
            // HALT();
        }
        previous_time = current_time;
        if (how_many_new_slices == 0) continue;

        // Copy the generated feature data to input tensor buffer
        for (int32_t i = 0; i < kFeatureElementCount; i++) {
            // input->data.int8[i] = g_yes_micro_f2e59fea_nohash_1_data[i];
            // input->data.int8[i] = g_no_micro_f9643d42_nohash_4_data[i];
            input->data.int8[i] = feature_buffer[i];
        }

        // Run inference
        TfLiteStatus invoke_status = interpreter->Invoke();
        if (invoke_status != kTfLiteOk) {
            PRINT_E("Invoke failed\n");
            // HALT();
        }

        // Print the result
        int8_t* y_quantized = output->data.int8;
        std::array<int32_t, kCategoryCount> current_score_list;
        for (int32_t i = 0; i < kCategoryCount; i++) {
            current_score_list[i] = y_quantized[i];
            float y = (y_quantized[i] - output->params.zero_point) * output->params.scale;
			// if it is not silent, then show YES or NO
            if (y > 0.8 && (i == 2 || i == 3)) {
                PRINT("%s: %f\n", kCategoryLabels[i], y);
            }
        }

    }

    return 0;
}