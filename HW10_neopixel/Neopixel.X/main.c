#include "NM32.h"
#include"ws2812b.h"

int main(void){

    NM32_Startup(); // Setup PIC32
    ws2812b_setup();// Setup timer and output pin
    
    wsColor colors[4];
    float rainbow[4] = {0,90,180,270};
   
    int i;
    int numLED = 4;
    int inc = 10;
    
    while(1){ 
        
        colors[0] = HSBtoRGB(rainbow[0],1,0.5);
        colors[1] = HSBtoRGB(rainbow[1],1,0.5);
        colors[2] = HSBtoRGB(rainbow[2],1,0.5);
        colors[3] = HSBtoRGB(rainbow[3],1,0.5);
        
        ws2812b_setColor(colors,numLED);    // Set the color of each neopixel 
            
        // Increment the colors accordingly 
        for (i = 0; i < 4; i++){
            if ((rainbow[i] >= 360)){
                rainbow[i] = 0;
            }
            else{
                rainbow[i] += inc;
            }
        }
        core_delay(0.01);   // Wait for 0.01 seconds 
    }
    return 0;
}
