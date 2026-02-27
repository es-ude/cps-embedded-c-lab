#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware_setup.h"


void adc_measure_N_times(uint16_t times){
    uint16_t buffer[200];
    const float conversion_factor = 3.3f / ((1 << 12)-1);

    adc_init();            // initialize the adc
    adc_gpio_init(27);     // set a GPIO Pin as analogue input function
    adc_select_input(1);   // connect the gpio pin to the ADC input

    // measure
    adc_capture(buffer, times);

    // calculating
    for(int i=0; i<times; i++){
        float adc_float_voltage = buffer[i] * conversion_factor;
        printf("Voltage: %04f\n", adc_float_voltage);
    }

    adc_run(false);
}

int main(void){
    // Enable UART so we can print status output
    stdio_init_all();
    
    while(1){
        
        char input_char = getchar_timeout_us(10000);
        if(input_char>=32 &&input_char<=126){
            if(input_char=='t'){
				for(int i=0;i<10;i++){
	                adc_measure_N_times(10);// need to add a parameter
				}
            }
        }else{
            // Uncomment the line below for testing
            // printf("i dont know what you typed:%d.\n", input_char);
        }
    }
}