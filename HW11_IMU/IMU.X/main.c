#include "NM32.h"
#include "i2c_master_noint.h"
#include "imu.h"

int main(void){

    NM32_Startup();     // Initialize the PIC32
    i2c_master_setup(); // Initialize I2C
    imu_setup();        // Make sure we are talking to the IMU properly
    
    char buff[20];
    unsigned char w;
    while(1){
        
        // Heartbeat
        NM32_LED1 = 1;
        core_delay(0.1);
        NM32_LED1 = 0;
        core_delay(0.1);
    }
    
    return 0;
}