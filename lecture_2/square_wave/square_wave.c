#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "pico/stdlib.h"


bool is_prim(uint64_t number) {
    if (number < 2) return false;

    for (uint64_t i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main(void) {
    stdio_init_all();

    while (1) {
        // Uncomment the following two lines to enable the computationally expensive operation
        // const bool result = is_prim(514229);
        // printf("Is prim?: %d\n", result);
    
        // TODO: Implement square wave generation
    }

    return 0;
}