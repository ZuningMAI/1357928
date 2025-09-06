#ifndef PQ_COMPLHEAP_GETMAX_H
#define PQ_COMPLHEAP_GETMAX_H

template <typename T> T & PQ_ComplHeap<T>::getMax() { return this->_elem[0]; } //取优先级最高的词条

#endif