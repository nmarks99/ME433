#include <stdio.h>
#include <string.h>

int main(void){

    int x = 0b11010100;
    int y = 0b00000001;
    int z = x | y;
    printf("%d",z);

    return 0;
}