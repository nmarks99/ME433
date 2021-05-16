#include "font.h"
#include "spi.h"
#include "ST7789.h"
#include "NM32.h"

int main(void){

    NM32_Startup(); // Initialize the PIC
    initSPI();      // Initalize SPI
    LCD_init();     // Initialize the LCD
    
    LCD_clearScreen(BLUE);  // Clear the screen to start
   
    char msg[50]; 
    int barL = 75;
    int count = 0;
    int i;
    float t0 = 0;
    float tf = 0;
    float fps;
    
    while(1){
        
        t0 = _CP0_GET_COUNT();
        drawBlock(85,120,32,45,BLUE);  // Clear previous count
        
        sprintf(msg,"Hello World %d",count);
        drawString(28,32,WHITE,msg);
        
        tf = _CP0_GET_COUNT();
        fps = CORE_TICKS/(tf - t0);
        sprintf(msg,"FPS = %.3f",fps);
        drawString(28,100,WHITE,msg);
        
        if ( count <= 100 ){
            count ++;
        }
        else{
            count = 0;
        }
       
        progress_bar(28,42,75,15); //xstart, ystart, length, height
        drawBlock(55,120,100,150,BLUE);  // Clear previous time
        
    }
    
    return 0;
}
