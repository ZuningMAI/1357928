#ifndef LIST_TRAVESE_H
#define LIST_TRAVESE_H 

#include "list.h"

template <typename T> void List<T>::traverse( void ( *visit )( T& ) ) //借助函数指针机制遍历
{  for ( ListNodePosi<T> p = head->succ; p != tail; p = p->succ ) visit ( p->data );  }

template <typename T> template <typename VST> //元素类型、操作器
void List<T>::traverse( VST& visit ) //借助函数对象机制遍历
{  for ( ListNodePosi<T> p = head->succ; p != tail; p = p->succ ) visit ( p->data );  }


#endif