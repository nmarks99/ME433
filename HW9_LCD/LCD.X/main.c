#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    
    while(1){
        NM32_LED1 = 1;
        core_delay(0.5);
        NM32_LED1 = 0;
        core_delay(0.5);
    }

    return 0;
}