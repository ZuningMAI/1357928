#ifndef DEPQ_SMMH_DELMAX_H
#define DEPQ_SMMH_DELMAX_H

#include "DEPQ_SMMH.h"

template <typename T> T SMMH<T>::delMax() { //delMax from a non-empty SMMH
   if ( this->_size < 4 ) return this->_elem[--this->_size]; //trivial cases
   T maxElem = this->_elem[2]; Rank k = 2; this->_elem[k] = this->_elem[--this->_size]; //initialization
   while (1) { //percolate down
      Rank x = k;
      Rank i = rc(k); if ( (i < this->_size) && (this->_elem[i] > this->_elem[x]) ) x = i;
      Rank j = rn(k); if ( (j < this->_size) && (this->_elem[j] > this->_elem[x]) ) x = j;
      if ( x == k ) break;
      swap(this->_elem[k], this->_elem[x]); k = x; //Property #2
      if ( this->_elem[k-1] > this->_elem[k] ) swap( this->_elem[k-1], this->_elem[k]); //Property #0
   }
   return maxElem;
} //delMax

#endif