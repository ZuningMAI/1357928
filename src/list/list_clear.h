#ifndef LIST_CLEAR_H
#define LIST_CLEAR_H 

// #include "list.h"
template <typename T> Rank List<T>::clear() { //清空列表
   Rank oldSize = _size;
   while ( 0 < _size ) remove ( head->succ ); //反复删除首节点，直至列表变空
   return oldSize;
}

#endif