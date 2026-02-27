#include <stdio.h>
#include "pico/stdlib.h"

// When this code is running on Pico MCU, and the MCU
// is connected through screen(or Putty), the key you
// pressed on you keyboard will be echo back.
int main(void){ 
    // Enable UART so we can print status output
    stdio_init_all();
    
    while(1){
        
        char input_char = getchar_timeout_us(10000);
        // ASCII code from 32(Dec) to 126 will be echo back
        if(input_char>=32 &&input_char<=126){
            printf("%c",input_char);
            // sleep_ms(1000);
        }else{
            // Uncomment the line below for testing
            // printf("i dont know what you typed:%d.\n", input_char);
        }

    }
}

