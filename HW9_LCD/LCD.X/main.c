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
    float t0;
    float tf;
    float tdiff;
    
    while(1){
        t0 = _CP0_GET_COUNT();
        drawBlock(85,120,32,45,BLACK);  // Clear previous count
        
        sprintf(msg,"Hello World %d",count);
        drawString(28,32,WHITE,msg);
        
        if ( count <= 100 ){
            count ++;
        }
        else{
            count = 0;
        }
        progress_bar(28,42,75,15); //xstart, ystart, length, height
        tf = _CP0_GET_COUNT();
        
        drawBlock(60,120,100,150,BLACK);  // Clear previous time
        tdiff= (t0 - tf)/CORE_TICKS;
        sprintf(msg,"Time = %.3f",tdiff);
        drawString(28,100,WHITE,msg);
    }
    
    return 0;
}
