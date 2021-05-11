#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    LATBbits.LATB15 = !LATBbits.LATB15; 
    
    unsigned short color = 20000;
    unsigned char x = 10;
    unsigned char y = 10;
    
    drawChar(x,y,color,'A');
            
    int i = 0;
    
    while(1){

//        if (i < 60000){
//            LCD_clearScreen(i);
//            core_delay(0.1);
//        }
//        else{
//            i = 0;
//        }
//        i += 1000;
//            
        NM32_LED1 = 1;
        core_delay(0.5);
        NM32_LED1 = 0;
        core_delay(0.5);
    }

    return 0;
}
