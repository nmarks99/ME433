#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    unsigned char x = 65;
    unsigned char y = 120;
    LCD_clearScreen(BLACK);
    
    char msg[10];
    sprintf(msg,"HELLO WORLD");
    drawString(x,y,WHITE,msg);
        
    while(1){
        NM32_LED1 = 1;
        core_delay(0.5);
        NM32_LED1 = 0;
        core_delay(0.5);
    }
    
    return 0;
}
