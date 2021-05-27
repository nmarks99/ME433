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
    unsigned short L = 100;
    unsigned short H = 15;
    int i;
    int j;
    float t0 = 0;
    float tf = 0;
    float fps;
    
    while(1){
        


        for (i = 0; i < L; i++){
            
            sprintf(msg,"Hello World %d",i);
            _CP0_SET_COUNT(0);
//            core_delay(0.1);
            drawString(28,23,WHITE,msg);
            tf = _CP0_GET_COUNT();
            
            fps = CORE_TICKS/tf;
            sprintf(msg,"FPS = %.2f",fps);
            drawString(28,75,WHITE,msg);
            
            core_delay(0.05);
            
            if (i < L/2){
                progress_bar(28,42,L,H,i,RED);
            }
            else{
                progress_bar(28,42,L,H,i,GREEN);
            }
            
            // Clear loading bar
            if (i == (L-1)){
                drawBlock(28,30+L,42,42+H,BLUE);
            }
            drawBlock(85,120,20,41,BLUE);   // Clear previous count
            drawBlock(55,100,75,100,BLUE);  // Clear previous FPS 
            
        }
    }
    
    return 0;
}
