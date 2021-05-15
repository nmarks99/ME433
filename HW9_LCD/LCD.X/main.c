#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    LCD_clearScreen(BLACK);  // Clear the screen to start
   
    char msg[20]; 
    int barL = 75;
    int count = 0;
    int i;
    while(1){
        drawBlock(85,120,32,45,BLACK);   // Clear previous number 
        sprintf(msg,"Hello World %d",count);
        drawString(28,32,WHITE,msg);
        
        if ( count <= 100 ){
            count ++;
        }
        else{
            count = 0;
        }
        progress_bar(28,42,75);
    }
    
    return 0;
}
