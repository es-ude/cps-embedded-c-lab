#include <stdio.h>
#include "pico/stdlib.h"

int main(void) {
    // Enable UART so we can print status output
    stdio_init_all();

    // Red LED
    gpio_init(18);
    gpio_set_dir(18, GPIO_OUT);
    gpio_put(18, 1);

    // Green LED
    gpio_init(19);
    gpio_set_dir(19, GPIO_OUT);
    gpio_put(19, 1);

    // Blue LED
    gpio_init(20);
    gpio_set_dir(20, GPIO_OUT);
    gpio_put(20, 1);

    while (1)
    {
        gpio_put(18, 0); // red on
        sleep_ms(500);
        gpio_put(18, 1); // red off
        sleep_ms(500);

        gpio_put(19, 0); // green on
        sleep_ms(500);
        gpio_put(19, 1); // green off
        sleep_ms(500);

        gpio_put(20, 0); // blue on
        sleep_ms(500);
        gpio_put(20, 1); // blue off
        sleep_ms(500);
    }
}