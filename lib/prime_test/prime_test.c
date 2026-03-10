#include "pico/stdlib.h"

bool is_prim(uint64_t number) {
    if (number < 2) return false;

    for (uint64_t i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}