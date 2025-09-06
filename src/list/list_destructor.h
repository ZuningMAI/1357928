#ifndef LIST_DESTRUCTOR_H
#define LIST_DESTRUCTOR_H 

// #include "list.h"
template <typename T> List<T>::~List() //列表析构器
{ clear(); delete head; delete tail; } //清空列表，释放头、尾哨兵节点

#endif