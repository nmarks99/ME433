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
            NM32_LED1 = 1;
        }
    }

    // Initialize the acceleration sensor
    setPin(IMU_WADD,IMU_CTRL1_XL,0b10000010); // Sample rate 1.66 kHz, 2g sensitivity, 100 Hz filter

    // Initialize gyroscope
    setPin(IMU_WADD,IMU_CTRL2_G,0b10001000);  // Sample rate 1.66 kHz, 1000 dps sensitivity

    // Control register
    setPin(IMU_WADD,IMU_CTRL3_C,0b00000100);  //  IF_INC = 1
    
}