
#include "NM32.h"
#include "spi.h"
#define CORE_TICKS 24000000 // sys clk is 48000000, core timer is half that

int main(void){
    
    NM32_Startup();
    initSPI();  
    
    unsigned char i = 0;
    while(1){
        // Write 1 bit over SPI
        LATAbits.LATA0 = 0; // Bring CS low
        spi_io(i);          // Write the byte
        LATAbits.LATA0 = 1; // Bring CS high
        
        i++;
        if (i == 100){
            i = 0;
        }
    
        _CP0_SET_COUNT(0);
        while( _CP0_GET_COUNT() < CORE_TICKS / 2 ){ 
            // 1Hz delay
        }     
    }
    
    return 0;
}
