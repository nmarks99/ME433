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
        
        // Draw x line
        if (data[5] > 0){
            for(i = 0; i < data[5]/25;i++){
                LCD_drawPixel(home+i,home,WHITE);
            }
        }  
        else{
            for(i = 0; i < abs(data[5])/25;i++){
                LCD_drawPixel(home-i,home,WHITE);
            } 
        }

        // Draw y line
        if (data[4] > 0){
            for (i = 0; i < data[4]/25;i++){
                LCD_drawPixel(home,home+i,WHITE);
            }
        }
        else{
            for(i = 0;i < abs(data[4]/25);i++){
                LCD_drawPixel(home,home-i,WHITE);
            }
        }

        core_delay(0.015);

        // Clear xline
        if (data[5] > 0){
            for(i = 0; i < data[5]/25;i++){
                LCD_drawPixel(home+i,home,BLUE);
            }
        }  
        else{
            for(i = 0; i < abs(data[5])/25;i++){
                LCD_drawPixel(home-i,home,BLUE);    
            } 
        }
        
        // Clear y line
        if (data[4] > 0){
            for (i = 0; i < data[4]/25;i++){
                LCD_drawPixel(home,home+i,BLUE);
            }
        }
        else{
            for(i = 0;i < abs(data[4]/25);i++){
                LCD_drawPixel(home,home-i,BLUE);
            }
        }
        
        NM32_LED1 = !NM32_LED1;
    }

    return 0;
}
