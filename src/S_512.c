#include "streebog.h"

//ГОСТ 34.11-2018 Пункт 6 преобразование S(a)
//Принимает на вход массив из 64 8-битных чисел и отображает каждый байт подстановкой pi_reflection

int S_512(uint8_t  a[]){
    int i;
    for(i=0; i<64; i++){
        a[i]=pi_reflection(a[i]);
    }

    return 0;
}