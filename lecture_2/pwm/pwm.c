#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"


bool is_prim(uint64_t number) {
    if (number < 2) return false;

    for (uint64_t i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main(void) {
    stdio_init_all();

    // TODO: Implement the PWM signal generation

    // Uncomment the following four lines to enable the computationally expensive operation
    // while (1) {
    //     const bool result = is_prim(1997);
    //     printf("Is prim?: %d\n", result);
    // }

    return 0;
}