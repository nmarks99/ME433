#include "NM32.h"
#include "i2c_master_noint.h"

int main(void){
    //
    
    while(1){
        
        NM32_LED1 = 1;      // Turn on LED 
        core_delay(0.25);   // Delay for 0.25 sec
        NM32_LED1 = 0;      // Turn off LED
        core_delay(0.25);   // Delay for 0.25 sec
    }
}