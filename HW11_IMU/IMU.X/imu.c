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
            core_delay(2);
            NM32_LED1 = 1;
            core_delay(2);
        }
    }

    // Initialize the acceleration sensor
    setPin(IMU_WADD,IMU_CTRL1_XL,0b10000010); // Sample rate 1.66 kHz, 2g sensitivity, 100 Hz filter

    // Initialize gyroscope
    setPin(IMU_WADD,IMU_CTRL2_G,0b10001000);  // Sample rate 1.66 kHz, 1000 dps sensitivity

    // Control register
    setPin(IMU_WADD,IMU_CTRL3_C,0b00000100);  //  IF_INC = 1
    
}

void imu_read(unsigned char reg,signed short *data,int len){
    
    unsigned char raw[14];
    I2C_read_multiple(IMU_WADD,reg,raw,len);
    
    // Convert each high/low 8-bit chars to 16-bit short
    int i = 0;
    for (i = 0; i < 7 ; i+=2){
        data[i] = (raw[(i*2)+1] << 8) | raw[(i*2)];
    }
}