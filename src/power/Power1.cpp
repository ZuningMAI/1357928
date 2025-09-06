#include "stdint.h"
uint64_t power ( uint64_t a, int n ) { //a^n算法：n >= 0
   uint64_t pow = 1; //O(1)
   uint64_t p = a; //O(1)
   while ( 0 < n ) { //O(logn)
      if ( n & 1 ) //O(1)
         pow *= p; //O(1)
      n >>= 1; //O(1)
      p *= p; //O(1)
   }
   return pow; //O(1)
} //power()
