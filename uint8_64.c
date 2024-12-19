#include "stribog.h"

uint64_t uint8_64(uint8_t a_in[]){

    uint64_t A=0;
    int i;
    for(i=0; i<8; i++){
        A<<=8;
        A+=a_in[i];
    }

    return A;
}
