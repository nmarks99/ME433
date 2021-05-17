#include <stdio.h>
#include <string.h>

int main(void){
    
    unsigned char x = 0b1101010;
    x = (x << 1) | 0b1;

    printf("%d",x);
    

    return 0;
}