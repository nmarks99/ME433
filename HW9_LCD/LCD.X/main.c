#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
//    LATBbits.LATB15 = !LATBbits.LATB15; 
    
    unsigned char x = 100;
    unsigned char y = 100;
    LCD_clearScreen(BLUE);
    int i = 0;
    
//    for (i=0;i<8;i++){
//        LCD_drawPixel(x,y+(i),WHITE);
//    }
    
    drawChar(x,y,WHITE,'B');
            
    
    
    while(1){
        NM32_LED1 = 1;
        core_delay(0.5);
        NM32_LED1 = 0;
        core_delay(0.5);
    }
    return 0;
}
