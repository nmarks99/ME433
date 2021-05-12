#include "NM32.h"
#include"ws2812b.h"

int main(void){

    NM32_Startup(); // Setup PIC32
    ws2812b_setup();// Setup timer and output pin
    
    wsColor colors[4];
    float c[4] = {0,90,180,270};  // Initial colors of each neopixel
   
    int i;
    int numLED = 4;
    int inc = 10;
    
    while(1){ 
        
        // Convert degrees (hue) to unsigned char (RGB) 
        for (i = 0;i < 4;i++){
            colors[i] = HSBtoRGB(c[i],1,0.5);
        }

        // Set the color of each neopixel 
        ws2812b_setColor(colors,numLED);    
            
        // Increment the colors accordingly 
        for (i = 0; i < 4; i++){
            if ((c[i] >= 360)){
                c[i] = 0;
            }
            else{
                c[i] += inc;
            }
        }
        core_delay(0.01);   // Wait for 0.01 seconds 
    }
    return 0;
}
