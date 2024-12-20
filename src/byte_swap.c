#include "streebog.h"

//ГОСТ 34.11-2018  Пункт 5.3 Перестановка байт

uint8_t byte_swap(uint8_t input_S_64){
    
    // I Реализация подстановки с помощью массива значений.
	/*unsigned char t[] = {
    0, 8,  16, 24, 32, 40, 48, 56, 1, 9,  17, 25, 33, 41, 49, 57,
    2, 10, 18, 26, 34, 42, 50, 58, 3, 11, 19, 27, 35, 43, 51, 59,
    4, 12, 20, 28, 36, 44, 52, 60, 5, 13, 21, 29, 37, 45, 53, 61,
    6, 14, 22, 30, 38, 46, 54, 62, 7, 15, 23, 31, 39, 47, 55, 63
    };

    return t[input_S_64%64];*/
    
    // II Реализация подстановки с помощью формулы
     return  ((input_S_64%64)/8+((input_S_64%64)%8)*8)%64;
}