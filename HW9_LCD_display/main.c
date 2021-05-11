#include "font.h"
#include "spi.h"
#include "ST7789.h"



int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD 

    return 0;
}