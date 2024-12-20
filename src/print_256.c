#include <stdio.h>
#include <stdint.h>

int print_256(uint8_t a[]){
    int i;
    for(i=0; i<32; i++){
            printf("%.2x", a[i]);
    }
    return 0;
}