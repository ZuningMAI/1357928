#ifndef PQ_LEFTHEAP_GETMAX_H
#define PQ_LEFTHEAP_GETMAX_H

template <typename T> T & PQ_LeftHeap<T>::getMax() { return this->_root->data; } //堆顶即是最大词条

#endif