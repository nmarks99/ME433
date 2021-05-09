#include "NM32.h"
#include"ws2812b.h"

int main(void){
    NM32_Startup();
    ws2812b_setup();
    
    wsColor colors[10];
    wsColor c =  HSBtoRGB(45.0, 1.0, 1.0);
    colors[0] = c;
    for (i = 0.0; i < 360.0; i += 36)
    
    while(1){   
        ws2812b_setColor(colors, 4);   
//        LATBbits.LATB10 = 1;
//        NM32_LED1 = 1;
//        core_delay(1);
//        LATBbits.LATB10 = 0;
//        NM32_LED1 = 0;
//        core_delay(1);
        
    }
    return 0;
}