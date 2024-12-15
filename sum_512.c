#include "striborg.h"

int sum_512(uint8_t a[], uint8_t b[]){
    uint16_t c, C_flag=0;
    int i;
    for(i=0; i<64; i++){
        c=(uint16_t)a[63-i]+(uint16_t)b[63-i]+C_flag;
        a[63-i]=c%256;
        C_flag=c/256;
    }

    return 0;
}