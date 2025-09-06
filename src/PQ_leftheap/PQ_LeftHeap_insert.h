#ifndef PQ_LEFTHEAP_INSERT_H
#define PQ_LEFTHEAP_INSERT_H

template <typename T> void PQ_LeftHeap<T>::insert( T e ) {
   this->_root = merge( this->_root, new BinNode<T>( e, NULL ) ); //将e封装为左式堆，与当前左式堆合并
   this->_size++; //更新规模
}
#endif