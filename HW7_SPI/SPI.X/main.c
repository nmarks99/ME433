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
    
    unsigned short vmax = 4096; // 12-bit DAC, range between 0 and 2^12 = 4096
    unsigned short v = 0;       // Voltage between 0 and 4096;
    unsigned char c;            // Channel A(0) or B(1)
    unsigned short p;           // Final variable we will send to the DAC
    float delayTime = 1.0;      // Delay between sending data
    
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
    
    /* This function performs the necessary bit manipulation to write the
     correct bits over SPI to the DAC and outputs the unsigned short which we 
     will write using the spi_io() function */
    p = (c << 15);
    p = p|(0b111 << 12);
    p = v|p;
    
    return p;
}