#include "stribog.h"

int E_512(uint8_t TEMP[], uint8_t h[], uint8_t N[], uint8_t m[]){
    int i;
    uint8_t K[64];

    //______Формирование_начального_значения_К
    for(i=0; i<64; i++){
        K[i]=h[i];
    }
    X_512(K, N);

    return 0;
}