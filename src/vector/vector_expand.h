#ifndef VECTOR_EXPAND_H
#define VECTOR_EXPAND_H 

// #include "vector.h"

template <typename T> 
void Vector<T>::expand() { //向量空间不足时扩容
   if ( _size < _capacity ) return; //尚未满员时，不必扩容
   T* oldElem = _elem; copyFrom( oldElem, 0, _capacity ); //容量加倍
   /*DSA*/ //printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n", oldElem, _size, _capacity/2, _elem, _size, _capacity);
   delete [] oldElem; //释放原空间
}



#endif