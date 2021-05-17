#include "NM32.h"
#include "i2c_master_noint.h"

int main(void){
    NM32_Startup(); // Initialize the PIC32
    i2c_master_setup(); // Initialize I2C



    return 0;
}