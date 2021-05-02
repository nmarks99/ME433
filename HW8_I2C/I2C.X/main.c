#include "NM32.h"
#include "i2c_master_noint.h"

int main(void){
    
    NM32_Startup();
    i2c_master_setup();
    unsigned char Wadd = 0b01000000;    // Write address
    unsigned char recv;
    
    /* 
    Initialize pins:
     GPA7 is output, make all the A pins output, IODIRA = 0x00 
     register = 0x00, value = 0x00
    
     GBB0 is input, make all B pins input, IODIRB = 0xFF 
     register = 0x01, value = 0xFF
     
     We have set A0 = A1 = A2 = 0, so the address to the IO expander is 
     0b01000000 for writing
     0b01000001 for reading
     */
    
    setPin(Wadd,0x00,0x00);   // Make A pins output
    setPin(Wadd,0x01,0xFF);   // Make B pins input
//    setPin(Wadd,0x14,0xFF);   // Turn on A pins  
    
    unsigned char buff[100];
    unsigned char f;   // Flag to tell if the button is pushed
    
    while(1){
        
        f = readPin(Wadd, 0x13);    // Read b pins
        f = f << 7; 
        if (f == 0){  // If button is pushed, f == 0;
            setPin(Wadd,0x14,0xFF);
        }
        else{
            setPin(Wadd,0x14,0x00);
        }
        
        NM32_LED1 = 1;     // Turn on LED 
        core_delay(0.1);   // Delay for 0.25 sec
        NM32_LED1 = 0;     // Turn off LED
        core_delay(0.1);   // Delay for 0.25 sec
    }
}