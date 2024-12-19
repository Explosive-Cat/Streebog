#include <stdio.h>
#include <stdint.h>

int print_uint64(uint64_t b){

    uint64_t k;
    int i;

    for (i = 0; i < 8; i++) {
            k=b;
            k >>=8*(7-i);
            printf("%.2x", k%16);
    }

    return 0;
}