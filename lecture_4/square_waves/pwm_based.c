#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "prime_test.h"

#define SIGNAL_PIN 8
#define FREQUENCY 10000


int main(void) {
    stdio_init_all();

    // TODO: Implement the square wave generation

    while (1) {
        // Uncomment the following two lines to enable the computationally expensive operation
        // const bool result = is_prim(1997);
        // printf("Is prim?: %d\n", result);
    }

    return 0;
}