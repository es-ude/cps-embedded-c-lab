#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

// we want to get a adc measurement
void adc_print_value(){
    
	adc_init();
    adc_gpio_init(27); // pin to the resistor
    adc_select_input(1); // this channel is conneced to pin 27

    uint16_t adc_value = adc_read(); // 12-bit, 0 to (2^12-1)
    float voltage = adc_value*3.3/((1<<12)-1);

    printf("adc read, int value: %d, ", adc_value);
    printf("adc read, float value: %f\n", voltage);
}

int main(void){ 
    // Enable UART so we can print status output
    stdio_init_all();
    
    while(1){
        
        char input_char = getchar_timeout_us(10000);
        if(input_char>=32 &&input_char<=126){
            if(input_char=='t'){
				for(int i=0;i<10;i++){
	                adc_print_value();
				}
            }
        }else{
            // Uncomment the line below for testing
            // printf("i dont know what you typed:%d.\n", input_char);
        }

    }
}