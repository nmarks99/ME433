#include "NM32.h"

int main(void){
    NM32_Startup();
    
    while(1){
        NM32_LED1 = 1;;
        core_delay(0.5);
        NM32_LED1 = 0;
        core_delay(0.5);
    }
    
    
    return 0;
    
}