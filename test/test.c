#include <stdio.h>

int main(void){

    short i;
    
    int a = 0b01000000;
    int b = a | 0b01000001;
    printf("%d",b);

    return 0;

}