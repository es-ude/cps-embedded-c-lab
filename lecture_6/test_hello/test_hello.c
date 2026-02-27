#include <stdio.h>
#include "pico/stdlib.h"

// When this code is running on Pico MCU, and the MCU
// is connected through screen(or Putty), per second
// the MCU will send "hello" to the screen.
int main(void){ 
    // Enable UART so we can print status output
    stdio_init_all();
    
    while(1){
        printf("hello\n");
        sleep_ms(1000);
    }
}
