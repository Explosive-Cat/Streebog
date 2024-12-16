#include <stdio.h>
#include <stdint.h>

int print_512(uint8_t a[]){
    int i;
    for(i=0; i<64; i++){
            if(i%8==0) printf(" ");
            printf("%.2x", a[i]);
    }
    return 0;
}