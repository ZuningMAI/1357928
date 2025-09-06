#ifndef DEPQ_SMMH_DELMIN_H
#define DEPQ_SMMH_DELMIN_H

#include "DEPQ_SMMH.h"

template <typename T> T SMMH<T>::delMin() { //delMin from a non-empty SMMH
   T minElem = this->_elem[1]; Rank k = 1; this->_elem[k] = this->_elem[--this->_size]; //initialization
   while (1) { //percolate down
      Rank x = k;
      Rank i = lc(k); if ( (i < this->_size) && (this->_elem[i] < this->_elem[x]) ) x = i;
      Rank j = ln(k); if ( (j < this->_size) && (this->_elem[j] < this->_elem[x]) ) x = j;
      if ( x == k ) break;
      swap(this->_elem[k], this->_elem[x]); k = x; //Property #1
      if ( (k+1 < this->_size) && (this->_elem[k] > this->_elem[k+1]) ) swap( this->_elem[k], this->_elem[k+1]); //Property #0
   }
   return minElem;
} //delMin

#endif