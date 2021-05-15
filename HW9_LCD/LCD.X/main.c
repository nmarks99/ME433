#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    LCD_clearScreen(BLUE);  // Clear the screen to start
   
    char msg[20]; 
    int barL = 75;
    int count = 0;
    while(1){
        int len = sizeof(count);
        sprintf(msg,"Hello World %d!",)
        progress_bar(x,y,75,WHITE);
    }
    
    return 0;
}
