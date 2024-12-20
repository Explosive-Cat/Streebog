#include "streebog.h"

int LPSX(uint8_t K[], uint8_t m[]){
    X_512(K, m);
    S_512(m);
    P_512(m);
    L_512(m);
    return 0;
}