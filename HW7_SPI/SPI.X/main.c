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
    
    unsigned short v1;          // Voltage between 0 and 4096;
    unsigned char c;            // Channel A(0) or B(1)
    unsigned short pt;          // Short to send to DAC for triangle wave
    unsigned short ps;          // Short to send to DAC for sine wave
    float delayTime = 0.01;     // Delay between sending data (seconds)
    
    /* Lookup tables for sine and triangle waves are generated in the python code
     I wrote that is also in this folder in my repo called makeLookupTables.ipynb */
    unsigned short sinTable[37] ={ 1999, 2347, 2684, 2999, 3285, 3532, 3732, 3879, 3969, 4000,
    3969, 3879, 3732, 3532, 3285, 3000, 2684, 2347, 2000, 1652, 1315, 1000, 714, 467, 267, 120,
    30, 0, 30, 120, 267, 467, 714, 999, 1315, 1652, 1999}; 
    
    unsigned short tri[37] = {1999, 2222, 2444, 2666, 2888, 3111, 3333, 3555, 3777, 4000, 3777, 3555,
    3333, 3111, 2888, 2666, 2444, 2222, 2000, 1777, 1555, 1333, 1111, 888, 666, 444, 222, 0, 222, 444,
    666, 888, 1111, 1333, 1555, 1777, 1999};
    
    int len = sizeof(tri)/2;
    int i;
    
    while(1){
        
        for (i=1; i < len; i++){
            // Write i'th value from the sin table
            ps = bit_manip(ps,sinTable[i],0);
            // Write 1 bit over SPI
            LATAbits.LATA0 = 0; // Bring CS low
            spi_io(ps >> 8);    
            spi_io(ps);
            LATAbits.LATA0 = 1; // Bring CS high
            core_delay(delayTime);  // Delay for 0.01 s
            
            // Write the i'th value from the triangle table 
            pt = bit_manip(pt,tri[i],1);
            LATAbits.LATA0 = 0; // Bring CS low
            spi_io(pt >> 8);    
            spi_io(pt);
            LATAbits.LATA0 = 1; // Bring CS high
            core_delay(delayTime);  // Delay for 0.01 s
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