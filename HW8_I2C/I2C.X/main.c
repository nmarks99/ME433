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
    
    
//    setPin(unsigned char 0b01000000, unsigned char 0x00, unsigned char 0x00);
//    setPin(unsigned char 0b01000001, unsigned char 0x01, unsigned char 0xFF);
//    
//    // Turn on A pins?  
//    setPin(unsigned char 0b01000000, unsigned char 0x14, unsigned char 0xFF);
//    
    
    while(1){
        
        NM32_LED1 = 1;      // Turn on LED 
        core_delay(0.125);   // Delay for 0.25 sec
        NM32_LED1 = 0;      // Turn off LED
        core_delay(0.125);   // Delay for 0.25 sec
    }
}