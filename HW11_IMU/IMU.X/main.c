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
    
    char buff[20];      // Buffer to write strings

     LCD_clearScreen(BLUE);
//     sprintf(buff,"Hello");
//     drawString(30,40,WHITE,buff);
    unsigned char raw[14];
    signed short data[7];
    int i;
    
    while(1){
        
        I2C_read_multiple(IMU_WADD,0x20,raw,14);
        recon_data(raw,data);


        sprintf(buff,"G = %hi\r\n",data[5]);
        writeUART1(buff);
//        drawString(28,30,WHITE,buff);
//        core_delay(.1);
//        drawString(28,30,BLUE,buff);

//        // Heartbeat at 10 Hz
//        NM32_LED1 = 1;
//        core_delay(0.1);
//        NM32_LED1 = 0;
//        core_delay(0.1);
    }
    
    return 0;
}

void recon_data(unsigned char *raw, signed short *data){
    int i = 0;
    int j = 1;
    int k = 0;
    for (i = 0; i < sizeof(raw)-1 ; i+=2){
        data[k] = raw[j] << 7 | raw [i]; // FIX
        j+=2;
        k++;
    }
}