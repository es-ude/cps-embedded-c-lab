#include "pico/stdlib.h"

#define BUTTON_PIN 5
#define NUM_LEDS 5
const uint LED_PINS[NUM_LEDS] = {0, 1, 2, 3, 4};

typedef enum {UP, DOWN, PRESS, RELEASE} button_state_t;
button_state_t previous_button_state = UP;


void leds_initialize(void) {
    for (uint8_t led_idx = 0; led_idx < NUM_LEDS; led_idx++) {
        gpio_init(LED_PINS[led_idx]);
        gpio_set_dir(LED_PINS[led_idx], GPIO_OUT);
        gpio_put(LED_PINS[led_idx], 0);
    }
}

void leds_set_index(uint8_t index) {
    for (uint8_t led_idx = 0; led_idx < NUM_LEDS; led_idx++) {
        gpio_put(LED_PINS[led_idx], 0);
    }
    gpio_put(LED_PINS[index], 1);
}

void button_initialize(void) {
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_set_pulls(BUTTON_PIN, 1, 0);
}

button_state_t button_read_up_down(void) {
    return gpio_get(BUTTON_PIN) ? UP : DOWN;
}

button_state_t button_get_state(void) {
    button_state_t current_state = button_read_up_down();

    /*
     * TODO: Implement denoised advanced button state detection algorithm here!
     *       Return UP, DOWN, PRESS or RELEASE depending on the button state.
     */
}

int main(void) {
    leds_initialize();
    button_initialize();

    uint8_t pressed_counter = 0;
    leds_set_index(pressed_counter);

    while (1) {
        if (button_get_state() == PRESS) {
            pressed_counter = (pressed_counter + 1) % NUM_LEDS;
            leds_set_index(pressed_counter);
        }
    }

    return 0;
}