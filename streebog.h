#ifndef STDINT.H
#define STDINT.H
#include <stdint.h>
#endif

#ifndef STDIO.H
#define STDIO.H
#include <stdio.h>
#endif

#ifndef ERRNO.H
#define ERRNO.H
#include <errno.h>
#endif

#ifndef STRING.H
#define STRING.H
#include <string.h>
#endif

int print_uint64(uint64_t b);
int print_512(uint8_t a[]);
int print_256(uint8_t a[]);
int X_512(uint8_t K[],  uint8_t m[]);
int S_512(uint8_t  a[]);
int P_512(uint8_t  a[]);
int L_512(uint8_t  a[]);
int LPSX(uint8_t K[], uint8_t m[]);
int E_512( uint8_t h[], uint8_t N[], uint8_t m[]);
int G_512(uint8_t h[], uint8_t N[], uint8_t m[]);
int sum_512(uint8_t a[], uint8_t b[]);
int sum_512n(uint8_t a[], uint16_t n);
int linear_trans(uint8_t a_in[]);
int uint64_8(uint64_t A, uint8_t a_in[]);
uint8_t pi_reflection(uint8_t input_V_8);
uint8_t byte_swap(uint8_t input_S_64);
uint64_t uint8_64(uint8_t a_in[]);