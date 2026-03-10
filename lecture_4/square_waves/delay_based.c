#include <stdio.h>
#include "pico/stdlib.h"
#include "prime_test.h"

#define SIGNAL_PIN 8
#define FREQUENCY 10000


int main(void) {
    stdio_init_all();

    while (1) {
        // Uncomment the following two lines to enable the computationally expensive operation
        // const bool result = is_prim(1997);
        // printf("Is prim?: %d\n", result);
    
        // TODO: Implement the square wave generation
    }

    return 0;
}