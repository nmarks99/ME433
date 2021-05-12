#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    unsigned short x = 28;
    unsigned short y = 32;
    LCD_clearScreen(BLACK);
    
    char msg[10];
    
    
    
    
    while(1){
        LCD_clearScreen(BLACK);
        sprintf(msg,"HELLO WORLD");
        drawString(x,y,WHITE,msg);
        core_delay(1);
//        loading_bar(x,y,WHITE);
    }
    
    return 0;
}
