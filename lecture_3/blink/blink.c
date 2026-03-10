#include "pico/stdlib.h"

#define LED_PIN 25
#define LED_DELAY_MS 250


void led_init(void) {
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);
}

int main(void) {
    led_init();
    
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(LED_DELAY_MS);
        gpio_put(LED_PIN, 0);
        sleep_ms(LED_DELAY_MS);
    }
}