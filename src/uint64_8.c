#include "streebog.h"

int uint64_8(uint64_t A, uint8_t a_in[]){

    int i;
    for(i=8; i>0; i--){
        a_in[i-1]=(uint8_t)A%256;
        A>>=8;
    }

    return 0;
}