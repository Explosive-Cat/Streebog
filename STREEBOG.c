#include "stribog.h"

int main(int argc, uint8_t* argv[]){
    
    uint8_t IV[64];     //_!!Надо_Добавить разные значения в разных режимах
    uint8_t h[64];
    uint8_t N[64];
    uint8_t SUM[64];
    uint8_t m[64];
    uint8_t V_0[64];
    long sizeM;
    int i;
    
    


    //__Этап_1__присваивание_начальных_значений_//
    for(i=0; i<64; i++){                        //
        IV[i]=0;                                //
        h[i]=IV[i];                             //_Шаг_1.1
        N[i]=0;                                 //_Шаг_1.2
        SUM[i]=0;                               //_Шаг_1.3
        V_0[i]=0;                               //
    }//_________________________________________//

    //__Открываем_файл_с_хешируемым_сообщением__//
    FILE* M = fopen(argv[1], "rb");             //
    fseek(M, 0, SEEK_END);                      //_Двигаем_курсор_в_конец_файла
    sizeM = ftell(M);                           //_для_определения_длины_сообщения
    //__________________________________________//


    //__Этап_2__хешируем_блоки_по_512_бит_______//
    while(sizeM>=64){                           //_Шаг_2.1
        fseek(M, -64, SEEK_CUR);                //отступаем_64_байта_назад_от_текущего_положения
                                                //
        for(i=0; i<64; i++){                    //_Шаг_2.2
            m[i]=fgetc(M);                      //
            if(m[i] == EOF) printf("\nEND OF FILE, you, stupid idiot in I=%d, sizeM=%d", i, sizeM); 
        }                                       //
                                                //
        G_512(h, N, m);                         //_Шаг_2.3
        sum_512n(N, 512);                       //_Шаг_2.4
        sum_512(SUM, m);                        //_Шаг_2.5
                                                //
        sizeM-=64;                              //_Шаг_2.6
        fseek(M, -64, SEEK_CUR);                //отбрасываем_курсор_в_состояние_на_начало_итерации_цикла
                                                //
    }//_________________________________________//_Шаг_2.7

    //__Этап_3__Хешируем_последний_неполный_блок//
    if(sizeM>0 && sizeM<64){                    //_Шаг_3.1
        fseek(M, -sizeM, SEEK_CUR);             //
        for(i=0; i<64; i++){                    //
            if(i<63-sizeM){                     //
                m[i]=0;                         //
            }else if(i==63-sizeM){              //
                m[i]=0x01;                      //
            }else {                             //
                m[i]=fgetc(M);                  //
            }                                   //
        }                                       //
    }                                           //
                                                //
    G_512(h, N, m);                             //_Шаг_3.2
    sum_512n(N, sizeM*8);                       //_Шаг_3.3
    sum_512(SUM, m);                            //_Шаг_3.4
    G_512(h, V_0, N);                           //_Шаг_3.5
    G_512(h, V_0, SUM);                         //_Шаг_3.6
    print_512(h);                               //_Шаг_3.7
    //__________________________________________//
    fclose(M);
    return 0;
}