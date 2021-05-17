#include "imu.h"
#include "NM32.h"
#include "i2c_master_noint.h"


void imu_setup(void){

    unsigned char who;
    // Check that we are talking with the IMU correctly
    who = readPin(IMU_WADD, IMU_WHOAMI);
    if (who != 0b1101001){
        while(1){
            // Turn off LED and hang here
            NM32_LED1 = 0;
        }
    }

    // Initialize the acceleration sensor


}