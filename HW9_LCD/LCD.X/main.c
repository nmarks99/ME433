#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    unsigned char x = 90;
    unsigned char y = 120;
    LCD_clearScreen(BLACK);
    
    char msg[10];
    sprintf(msg,"Hello World!");
    drawString(x,y,WHITE,msg);
    // drawChar(x,y,WHITE,'B');
            
    return 0;
}
