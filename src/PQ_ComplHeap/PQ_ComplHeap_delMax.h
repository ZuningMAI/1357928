#ifndef PQ_COMPLHEAP_DELMAX_H
#define PQ_COMPLHEAP_DELMAX_H

template <typename T> T PQ_ComplHeap<T>::delMax() { //取出最大词条
   swap( this->_elem[0], this->_elem[--this->_size] ); //堆顶、堆尾互换（_size的递减，不致引发shrink()）
   percolateDown( this->_elem, this->_size, 0 ); //新堆顶下滤
   return this->_elem[this->_size]; //返回原堆顶
}

#endif