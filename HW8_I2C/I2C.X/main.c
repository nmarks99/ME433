#include "NM32.h"
#include "i2c_master_noint.h"

int main(void){
    
    NM32_Startup();
    i2c_master_setup();
    
    /* 
    Initialize pins:
     GPA7 is output, make all the A pins output, IODIRA = 0x00 
     address = 0b01000000, register = 0x00, value = 0x00
    
     GBB0 is input make all B pins input, IODIRB = 0xFF 
     address = 0b01000001, register = 0x01, value = 0xFF
     */
    
    setPin(0b01000000,0x00,0x00);   // Make A pins outputs
//    setPin(0b01000001,0x01,0xFF); // Make B pins input?
    
    setPin(0b01000000,0x14,0xFF);   // Turn on A pins  
    
    
    while(1){
        
        NM32_LED1 = 1;      // Turn on LED 
        core_delay(0.2);   // Delay for 0.25 sec
        NM32_LED1 = 0;      // Turn off LED
        core_delay(0.2);   // Delay for 0.25 sec
    }
}