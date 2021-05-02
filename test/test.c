#include <stdio.h>

int main(void){

    unsigned char f = 0b00000000;
    unsigned char recv = 0b10000000;
    f = f | (recv >> 7); // Gets the 0th bit   
    printf("recv = %d, f = %d\r\n",recv,f);

    return 0;

}