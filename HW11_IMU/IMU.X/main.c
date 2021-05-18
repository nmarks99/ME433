#include "NM32.h"
#include "i2c_master_noint.h"
#include "imu.h"
#include "spi.h"
#include "ST7789.h"

void recon_data(unsigned char *raw, signed short *data);
int main(void){

    NM32_Startup();     // Initialize the PIC32
    i2c_master_setup(); // Initialize I2C
    imu_setup();        // Initialize the IMU
    initSPI();          // Initalize SPI
    LCD_init();         // Initialize the LCD
    
    char buff[100];      // Buffer
    signed short data[7];
    int i;
    
    while(1){
        

        imu_read(IMU_OUT_TEMP_L,data,14); // read the IMU temp, gyro, and acceleration
        
        sprintf(buff,"%hi, %hi, %hi, %hi, %hi, %hi, %hi \r\n",data[0],data[1],data[2],data[3],data[4],data[5],data[6]);
        writeUART1(buff);
        core_delay(0.05);
        NM32_LED1 = !NM32_LED1;
    }
    
    return 0;
}