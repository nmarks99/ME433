#include "NM32.h"
#include"ws2812b.h"

int main(void){
    NM32_Startup();
    ws2812b_setup();
    
    wsColor colors[4];
    int ind = 0;
    int i;
    float rainbow[4] = {0,30,60,120};
    char buff[100];
    
    for (i = 0; i <= sizeof(rainbow)/4; i++){
        colors[ind] = HSBtoRGB(rainbow[i], 1.0, 1.0);
        sprintf(buff,"Index %d: ",ind);
        writeUART1(buff);
        sprintf(buff,"%d,%d,%d\r\n",colors[ind].r,colors[ind].g,colors[ind].b);
        writeUART1(buff);
        ind++;
    }
    
    while(1){   
        ws2812b_setColor(colors,4);
    }
    return 0;
}