#ifndef PQ_COMPLHEAP_INSERT_H
#define PQ_COMPLHEAP_INSERT_H

template <typename T> void PQ_ComplHeap<T>::insert( T e ) { //将词条插入完全二叉堆中
   Vector<T>::insert( e ); //将新词条接至向量末尾
   percolateUp( this->_elem, this->_size - 1 ); //再对该词条实施上滤调整
}

#endif
