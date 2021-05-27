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
        
        if (data[5] > 0){
            for(i = 0; i < data[5]/30;i++){
                LCD_drawPixel(home+i,home,WHITE);
            }
        }  
        else{
            for(i = 0; i < abs(data[5])/30;i++){
                LCD_drawPixel(home-i,home,WHITE);
            } 
        }

        core_delay(0.01);

        if (data[5] > 0){
            for(i = 0; i < data[5]/30;i++){
                LCD_drawPixel(home+i,home,BLUE);
            }
        }  
        else{
            for(i = 0; i < abs(data[5])/30;i++){
                LCD_drawPixel(home-i,home,BLUE);    
            } 
        }

        // Print data
        // sprintf(buff,"g: %d, %d, %d\r\n",data[1],data[2],data[3]);
        // drawString(20,30,WHITE,buff);
        // sprintf(buff,"a: %d, %d, %d",data[4],data[5],data[6]);
        // drawString(20,40,WHITE,buff);

        // Clear last data 
        // sprintf(buff,"g: %d, %d, %d\r\n",data[1],data[2],data[3]);
        // drawString(20,30,BLUE,buff);
        // sprintf(buff,"a: %d, %d, %d",data[4],data[5],data[6]);
        // drawString(20,40,BLUE,buff);
        
        NM32_LED1 = !NM32_LED1;
        
    }
    
    return 0;
}
