#include "NM32.h"

#define CORE_TICKS 24000000 // sysclk = 48MHz; CORE_TICKS = sysclk/2 = 24M

/* Function prototypes */
void delay(float waitTime);

int main(){

    NM32_Startup();
    
    int bflag = 0;
    char m[100];
    
    while (1) {
        
        if (!NM32_USER & bflag == 0){
            bflag = 1;  // Set bflag to 1 after detecting a button press
            sprintf(m,"Hello\r\n");
            writeUART1(m);
        }
        if (bflag > 0){ // Pulse light twice after button press
            NM32_LED1 = 1; // LED on
            delay(0.5);         // Delay 0.5s 
            NM32_LED1 = 0;
            delay(0.5);
            NM32_LED1 = 1;
            delay(0.5);
            NM32_LED1 = 0;
            bflag = 0;  // Reset the flag
        }  
    }
}

void delay(float waitTime){
    /* delay(waitTime) uses the core timer to delay for
     the specified amount of time. The input variable "waitTime" is in seconds */
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT() < CORE_TICKS*waitTime){
        // Wait for "waitTime" seconds
    }
}
