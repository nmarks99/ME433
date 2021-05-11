#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

// void drawChar(unsigned short x,unsigned short y,unsigned short color,unsigned char letter);

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
   
    
    LCD_drawPixel(100,100,100);

    while(1){
        NM32_LED1 = 1;
        core_delay(0.5);
        NM32_LED1 = 0;
        core_delay(0.5);
    }

    return 0;
}

// void drawChar(unsigned short x,unsigned short y,unsigned short color,unsigned char letter){
//     // Code
// }