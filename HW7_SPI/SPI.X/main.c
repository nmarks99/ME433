
#include "NM32.h"
#include "spi.h"
#include "math.h"

unsigned short bit_manip(unsigned short p, unsigned short v, unsigned char c);

int main(void){
    
    NM32_Startup();
    initSPI();
    /*Output SD01 (A1)
      Input SDI1 (B5)
      Clock SCK1 (pin 25) */
    
    unsigned short vmax = 4096;
    unsigned short v = 0;  // Voltage I want between 0 and 4096; short is 2 bytes
    unsigned char c;       // Channel A(0) or B(1)
    unsigned short p;
    float delayTime = 1.0;
    
    while(1){
        
        //v1 =  -200; negative outputs max voltage ???
        
        v = 4095;
        p = bit_manip(p,v,1);
        
        // Write 1 bit over SPI
        LATAbits.LATA0 = 0; // Bring CS low
        spi_io(p >> 8);    
        spi_io(p);
        LATAbits.LATA0 = 1; // Bring CS high
        
        core_delay(delayTime);  // Delay for 1/2 sec
        
        v = 2048;
        p = bit_manip(p,v,1);
        
        // Write 1 bit over SPI
        LATAbits.LATA0 = 0; // Bring CS low
        spi_io(p >> 8);    
        spi_io(p);
        LATAbits.LATA0 = 1; // Bring CS high
        
        core_delay(delayTime);
    }
    return 0;
}

unsigned short bit_manip(unsigned short p, unsigned short v, unsigned char c){
    p = (c << 15);
    p = p|(0b111 << 12);
    p = v|p;
    
    return p;
}