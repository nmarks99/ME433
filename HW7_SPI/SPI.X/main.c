
#include "NM32.h"
#include "spi.h"
#include "math.h"
#define CORE_TICKS 24000000 // sys clk is 48000000, core timer is half that

int main(void){
    
    NM32_Startup();
    initSPI();
    /*Output SD01 (A1)
      Input SDI1 (B5)
      Clock SCK1 (pin 25) */
    
    unsigned short vmax = 4096;
    unsigned short v1 = 0;  // Voltage I want between 0 and 4096; short is 2 bytes
    unsigned char c1;       // Channel A(0) or B(1)
    unsigned short p1;
    int f = 1;
    // cslow; spi_io(p>>8);spi_io(p)); cshigh;
    while(1){
        
        v1 =  -200; // negative outputs max voltage ???
        
        c1 = 1;
        p1 = (c1 << 15);
        p1 = p1|(0b111 << 12);
        p1 = v1|p1;

        // Write 1 bit over SPI
        LATAbits.LATA0 = 0; // Bring CS low
        spi_io(p1 >> 8);    
        spi_io(p1);
        LATAbits.LATA0 = 1; // Bring CS high

        _CP0_SET_COUNT(0);
        while( _CP0_GET_COUNT() < CORE_TICKS / 8 ){ 
            // 1Hz delay
        }
    }
    return 0;
}