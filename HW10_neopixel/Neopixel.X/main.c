#include "NM32.h"
#include"ws2812b.h"

int main(void){

    NM32_Startup(); // Setup PIC32
    ws2812b_setup();// Setup timer and output pin

    float c[4] = {0,90,180,270};  // Initial colors of each neopixel
    
    while(1){ 
        *c = neo_rainbow(c,4,1,0.5); // Function which makes fading colors effect
    }
    return 0;
}

