#include "NM32.h"
#include "i2c_master_noint.h"
#include "imu.h"
#include "spi.h"
#include "ST7789.h"

int main(void){

    NM32_Startup();     // Initialize the PIC32
    i2c_master_setup(); // Initialize I2C
    imu_setup();        // Initialize the IMU
    initSPI();          // Initalize SPI
    LCD_init();         // Initialize the LCD
    
    char buff[20];      // Buffer to write over UART 

    while(1){
        
        // Heartbeat
        NM32_LED1 = 1;
        core_delay(0.1);
        NM32_LED1 = 0;
        core_delay(0.1);
    }
    
    return 0;
}