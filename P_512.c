#include "stribog.h"

//ГОСТ 34.11-2018 Пункт 6 преобразование P(a)
//Принимает на вход массив из 64 8-битных чисел и переставляет байты в соответствии с подстановкой byte_swap

int P_512(uint8_t  a[]){
    uint8_t step, remainder, index;
    uint8_t k;

    //_______________________________________________Перестановка байт в соответствии с подстановкой byte_swap
    for(step=0; step<8; step++){                            //Если представить индекс массива index в виде step*8+remainder,
        for(remainder=step+1; remainder<8; remainder++){    //то элемент массива с таким индексом должен переставиться
            index = step*8 + remainder;                     //с элементом с индексом step+remainder*8 который дает функция
            k = a[byte_swap(index)];                        // byte_swap( index ) 
            a[byte_swap(index)] = a[index];                 //p.s. текущая функция не универсальна и написана под конкретную подстановку byte_swap и
            a[index] = k;                                   //при смене подстановки требуется переписать функцию
        }
    }
    return 0;
}