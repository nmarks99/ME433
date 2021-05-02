#include "NM32.h"
#include "i2c_master_noint.h"

int main(void){
    //
    
    
    /*
     GPA7 is output, make all the A pins output, IODIRA = 0x00 
     * Address = 0b01000000, register = 0x00, value = 0x00
     
     GBB0 is input make all B pins input, IODIRB = 0xFF 
     * Address = 0b01000001, register = ?, value = 0xFF
     */
    
    while(1){
        
        NM32_LED1 = 1;      // Turn on LED 
        core_delay(0.25);   // Delay for 0.25 sec
        NM32_LED1 = 0;      // Turn off LED
        core_delay(0.25);   // Delay for 0.25 sec
    }
}