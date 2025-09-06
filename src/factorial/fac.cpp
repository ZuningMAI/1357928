
#include "fac.h"
uint64_t facR ( int n ){
    return n < 1 ? (uint64_t) 1 :(uint64_t) n * facR(n-1);
}

uint64_t facI ( int n){
    uint64_t f = 1;
    while(n > 1){f *= n--;}
    return f;
}



