# Inertial measurement unit (IMU)
## CTRL1_XL (0x10) - Acceleration sensor:
Set the sample rate to 1.66 kHz, with 2g sensitivity, and 100 Hz filter:  
[ ODR_XL3, ODR_XL2, ODR_XL1, ODR_XL0, FS_XL1, FS_XL0, BW_XL1, BW_XL0 ] = 0b10000010

## CTRL2_G (0x11) - Gyroscope sensor:
Set the sample rate to 1.66 kHz, with 1000 dps sensitivity:  
[ ODR_G3, ODR_G2, ODR_G1, ODR_G0, FS_G1, FS_G0, FS_125, 0(1) ] = 0b10001000

## CTRL3_C (0x12) - Control register
Enable IF_INC, all the reset defaults  
0b00000100