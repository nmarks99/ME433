#include "NM32.h"
#include "spi.h"
#include "math.h"

unsigned short bit_manip(unsigned short p, unsigned short v1, unsigned char c);

int main(void){
    
    NM32_Startup(); 
    initSPI();
    /*Output SD01 (A1)
      Input SDI1 (B5)
      Clock SCK1 (pin 25) */
    
    unsigned short vmax = 4096; // 12-bit DAC, range between 0 and 2^12 = 4096
    unsigned short v1;          // Voltage between 0 and 4096;
    unsigned char c;            // Channel A(0) or B(1)
    unsigned short p;           // Final variable we will send to the DAC
    unsigned short ps;
    float delayTime = 0.01;     // Delay between sending data (seconds)
    
    
    unsigned short sinTable[37] ={ 1999, 2347, 2684, 2999, 3285, 3532, 3732, 3879, 3969, 4000,
      3969, 3879, 3732, 3532, 3285, 3000, 2684, 2347, 2000, 1652, 1315, 1000, 714, 467, 267, 120,
       30, 0, 30, 120, 267, 467, 714, 999, 1315, 1652, 1999}; 
    
    int len_st = sizeof(sinTable)/2;
    int i;
    
    while(1){
        
        for (i=1; i < len_st; i++){
            ps = bit_manip(ps,sinTable[i],1);
            
            // Write 1 bit over SPI
            LATAbits.LATA0 = 0; // Bring CS low
            spi_io(ps >> 8);    
            spi_io(ps);
            LATAbits.LATA0 = 1; // Bring CS high
            
            core_delay(delayTime);
        }
//        
        for (v1 = 0; v1 < 4095; v1++){
            p = bit_manip(p,v1,0);
            
            // Write 1 bit over SPI
            LATAbits.LATA0 = 0; // Bring CS low
            spi_io(p >> 8);    
            spi_io(p);
            LATAbits.LATA0 = 1; // Bring CS high

            core_delay(delayTime);  // Delay for 1/2 sec
        }
        for (v1 = 4095; v1 > 0; v1-- ){
            p = bit_manip(p,v1,0);
            
            // Write 1 bit over SPI
            LATAbits.LATA0 = 0; // Bring CS low
            spi_io(p >> 8);    
            spi_io(p);
            LATAbits.LATA0 = 1; // Bring CS high

            core_delay(delayTime);  // Delay for 1/2 sec
        }
    }
    return 0;
}

unsigned short bit_manip(unsigned short p, unsigned short v1, unsigned char c){
    
    /* This function performs the necessary bit manipulation to write the
     correct bits over SPI to the DAC and outputs the unsigned short which we 
     will write using the spi_io() function */
    p = (c << 15);
    p = p|(0b111 << 12);
    p = v1|p;
    
    return p;
}