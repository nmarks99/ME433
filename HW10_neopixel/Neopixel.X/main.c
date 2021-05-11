#include "NM32.h"
#include"ws2812b.h"

int main(void){

    NM32_Startup(); // Setup PIC32
    ws2812b_setup();// Setup timer and output pin
    
    wsColor colors[4];

    colors[0] = HSBtoRGB(270,1,1);
    colors[1] = HSBtoRGB(180,1,1);
    colors[2] = HSBtoRGB(90,1,1);
    colors[3] = HSBtoRGB(0,1,1);
    
    while(1){ 
        ws2812b_setColor(colors,4);
    }
    return 0;
}
