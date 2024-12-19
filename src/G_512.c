#include "streebog.h"

int G_512(uint8_t h[], uint8_t N[], uint8_t m[]){

    int i;
    uint8_t TEMP[64];

    for(i=0; i<64; i++) TEMP[i]=m[i];   //Копируем кусок сообщения в локальный массив для обработки

    E_512(h, N, TEMP);
    X_512(TEMP, h);
    X_512(m, h);

    return 0;
}