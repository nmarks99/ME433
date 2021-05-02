#ifndef NM32__H__
#define NM32__H__

#include<xc.h>           // Processor SFR definitions
#include<sys/attribs.h>  // __ISR macro
#include <stdio.h>                  
#include <stdlib.h>

#define NM32_LED1 LATAbits.LATA4    // LED1
#define NM32_USER PORTBbits.RB4     // User button
#define CORE_TICKS 24000000         // sys clk is 48MHz, core timer is half 

void NM32_Startup(void);
void readUART1(char * message, int maxLength);
void writeUART1(const char * string);
void core_delay(float seconds);

#endif  // NM32__H__