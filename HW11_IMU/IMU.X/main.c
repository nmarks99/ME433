#include "NM32.h"
#include "i2c_master_noint.h"

int main(void){
    NM32_Startup(); // Initialize the PIC32
    i2c_master_setup(); // Initialize I2C
    
    char buff[20];
    int f;
    while(1){
        
        
        f = readPin(IMU_WADD, IMU_WHOAMI);
        sprintf(buff,"I am %d\r\n",f);
        writeUART1(buff);
        
        NM32_LED1 = 1;
        core_delay(0.1);
        NM32_LED1 = 0;
        core_delay(0.1);
    }
    return 0;
}