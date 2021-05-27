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
    
    LCD_clearScreen(BLUE);
    char buff[100];      
    signed short data[7];
    unsigned short home = 120; // Center of LCD at (120,120) 
    int i;
    while(1){

        imu_read(IMU_OUT_TEMP_L,data,14); // read the IMU temp, gyro, and acceleration
        
        sprintf(buff,"g: %d, %d, %d\r\n",data[1],data[2],data[3]);
        drawString(20,30,WHITE,buff);
        sprintf(buff,"a: %d, %d, %d",data[4],data[5],data[6]);
        drawString(20,40,WHITE,buff);
        core_delay(0.05);
        NM32_LED1 = !NM32_LED1;
        drawBlock(30,150,30,100,BLACK);
        
    }
    
    return 0;
}
