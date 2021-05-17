#include <stdio.h>
#include <string.h>


void recon_data(unsigned char *raw, signed short *data);

int main(void){
    
    unsigned char raw[14] = {0b000000000,0b00000000};
    signed short data[7];    
    
    recon_data(raw,data);
    int i;
    for (i = 0; i < 1; i++){
        printf("%d\r\n",data[i]);
    }
    return 0;
}

void recon_data(unsigned char *raw, signed short *data){
    int i = 0;
    int j = 1;
    int k = 0;
    for (i = 0; i < sizeof(raw)-1 ; i+=2){
        data[k] = raw[j] | raw [i];
        j+=2;
        k++;
    }
}