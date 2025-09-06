#ifndef DEPQ_SMMH_INSERT_H
#define DEPQ_SMMH_INSERT_H

#include "DEPQ_SMMH.h"

template <typename T> void SMMH<T>::insert( T e ) { //insert e into an SMMH
   this->Vector<T>::insert(e); //增加一个单元
   Rank k = this->_size - 1; //从末元素开始
   while (1) { //逐层上滤
      if ( isRC(k) && (this->_elem[k-1] > this->_elem[k]) ) //Property #0
         { this->_elem[k] = this->_elem[k-1]; k--; }
      if ( !hasGP(k) ) break;
      if      ( e < this->_elem[lp(k)] ) //Property #1
         { this->_elem[k] = this->_elem[lp(k)]; k = lp(k); }
      else if ( this->_elem[rp(k)] < e ) //Property #2
         { this->_elem[k] = this->_elem[rp(k)]; k = rp(k); }
      else
         break;
   }
   this->_elem[k] = e; //新元素就位
} //insert

#endif