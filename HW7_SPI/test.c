#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){

     unsigned short sinTable[37] ={ 1999, 2347, 2684, 2999, 3285, 3532, 3732, 3879, 3969, 4000,
      3969, 3879, 3732, 3532, 3285, 3000, 2684, 2347, 2000, 1652, 1315, 1000, 714, 467, 267, 120,
       30, 0, 30, 120, 267, 467, 714, 999, 1315, 1652, 1999};

    int i;
    for (i = 0; i < 37; i++){
        printf("%hu\n",sinTable[i]);
    }
    int lenst = sizeof(sinTable)/2;
    printf("\nLength = %d",lenst);

    // float vf[4096];
    // int len = sizeof(vf)/2;  // Short is 2 bytes
    // int i;


    // // Make an array of values 1:4095
    // for (i=0; i <= len; i+=25){ 
    //     vf[i] =  (float)i+1;
    //     // printf("%.2f\n",vf[i]);
    //     if (vf[i] > (4094-25) ){
    //         break;
    //     } 
    // }

    // float sinv[4096];
    // // Compute sin + 1 for all the values
    // for (i=0;i <= len; i++){
    //     sinv[i] = (sin(vf[i]));
        
    // }
    // printf("%.5f\n",sin(sinv[100]));
   

    return 0;
}



unsigned short tri[37] = {1999, 2222, 2444, 2666, 2888, 3111, 3333, 3555, 3777, 4000, 3777, 3555,
3333, 3111, 2888, 2666, 2444, 2222, 2000, 1777, 1555, 1333, 1111, 888, 666, 444, 222, 0, 222, 444,
666, 888, 1111, 1333, 1555, 1777, 1999};