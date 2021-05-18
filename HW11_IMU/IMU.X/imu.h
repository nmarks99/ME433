#ifndef IMU__H__
#define IMU__H__

#include<xc.h>              // Processor SFR definitions

#define IMU_WHOAMI 0x0F     // Address for WHOAMI register
#define IMU_WADD 0b11010100 // Write address
#define IMU_RADD 0b11010101 // Read address
#define IMU_CTRL1_XL 0x10   // Acceleration control register
#define IMU_CTRL2_G 0x11    // Gyroscope control register
#define IMU_CTRL3_C 0x12    // Read from multiple registers in a row
#define IMU_OUT_TEMP_L 0x20 // Temperature

void imu_setup(void);
void imu_read(unsigned char reg,signed short *data,int len);

#endif