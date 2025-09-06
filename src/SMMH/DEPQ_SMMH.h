#ifndef DEPQ_SMMH_H
#define DEPQ_SMMH_H

#include "../vector/vector.h" //借助多重继承机制，基于向量
#include "../DEPQ/DEPQ.h" //按照优先级队列ADT实现的

template <typename T> class SMMH : public DEPQ<T>, public Vector<T> { //Symmetric Min-Max Heap
   /*DSA*/friend class UniPrint; //For test. Just remove this line for real applications
protected:
   //void heapify ( Rank n ); //Floyd's heapification
public:
   SMMH() { this->insert((T) -1); } //initialized with a dummy root
   void insert( T ); //insert an element (duplicates accepted)
   T getMin() { return this->_elem[1]; }
   T & getMax() { return this->_size < 3 ? this->_elem[1] : this->_elem[2]; }
   T delMin();
   T delMax();
}; //SMMH

/*DSA*/#include "DEPQ_SMMH_macro.h"
/*DSA*/#include "DEPQ_SMMH_implementation.h"

#endif