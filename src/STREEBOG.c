#include "stribog.h"

int main(int argc, uint8_t* argv[]){

    uint8_t IV[64];
    uint8_t h[64];
    uint8_t N[64];
    uint8_t SUM[64];
    uint8_t m[64];
    uint8_t V_0[64];
    long sizeM;
    int i;
    char *usage_message = "usage: STREEBOG [no flag| 512 bit mode || -s | 256 bit mode] [file]\n";
    uint8_t s_flag=0x0;

    //______________Обработка_аргументов_коммандной_строки______________//
    switch (argc)                                                       // 
    {                                                                   //
        case 1:                                                         //
            printf("%s", usage_message);                                //
            return 0;                                                   //
                                                                        //
        case 2:                                                         //
            if(argv[1][0] == '-'){                                      //
                printf("%s", usage_message);                            //
                printf("error: no input files\n");                      //
                return 0;                                               //
            }                                                           //
            break;                                                      //
                                                                        //
        case 3:                                                         //
            if(argv[1][0] == '-' && argv[1][1] != 's'){                 //
                printf("unknown option: %s\n", argv[1]);                //
                return 0;                                               //
            }                                                           //
            if(argv[2][0] == '-' ){                                     //
                printf("unknown option: %s\n", argv[2]);                //
                return 0;                                               //
            }                                                           //
            if(argv[1][0] == '-' && argv[1][1] == 's') s_flag = 0x1;    //
            break;                                                      //
        default:                                                        //
            break;                                                      //
    }//_________________________________________________________________//

    //__Этап_1__присваивание_начальных_значений_//
    for(i=0; i<64; i++){                        //
        IV[i]=s_flag;                           //
        h[i]=IV[i];                             //_Шаг_1.1
        N[i]=0;                                 //_Шаг_1.2
        SUM[i]=0;                               //_Шаг_1.3
        V_0[i]=0;                               //
    }//_________________________________________//


    //__Открываем_файл_с_хешируемым_сообщением__//
    FILE* M = fopen(argv[1+s_flag], "rb");      //
    if(M == NULL){                              //
        fprintf(stderr, "%s\n", strerror(errno));//
        return 0;                               //
    }                                           //
    fseek(M, 0, SEEK_END);                      //_Двигаем_курсор_в_конец_файла
    sizeM = ftell(M);                           //_для_определения_длины_сообщения
    //__________________________________________//


    //____Этап_2__хешируем_блоки_по_512_бит_____//
    while(sizeM>=64){                           //_Шаг_2.1
        fseek(M, -64, SEEK_CUR);                //отступаем_64_байта_назад_от_текущего_положения
                                                //
        for(i=0; i<64; i++){                    //_Шаг_2.2
            m[i]=fgetc(M);                      //
            if(m[i] == EOF){                    //
                printf("\nEND OF FILE");        //
                printf("\nUnread message size");//
                printf("sizeM=%d", sizeM-i);    //
            }                                   //
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

    //_Этап_3__Хешируем_последний_неполный_блок_//
    if(sizeM>=0 && sizeM<64){                   //_Шаг_3.1
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
    s_flag ? print_256(h) : print_512(h);       //_Шаг_3.7
    //__________________________________________//
    fclose(M);
    return 0;
}