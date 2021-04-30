#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){

    float vf[4096];
    int len = sizeof(vf)/2;  // Short is 2 bytes
    int i;


    // Make an array of values 1:4095
    for (i=0; i <= len; i+=25){ 
        vf[i] =  (float)i+1;
        // printf("%.2f\n",vf[i]);
        if (vf[i] > (4094-25) ){
            break;
        } 
    }

    float sinv[4096];
    // Compute sin + 1 for all the values
    for (i=0;i <= len; i++){
        sinv[i] = (sin(vf[i]));
        
    }
    printf("%.5f\n",sin(sinv[100]));
   

    return 0;
}