#ifndef QUADLIST_INSERT_H
#define QUADLIST_INSERT_H

template <typename T> QNodePosi<T> //将e作为p的后继、b的上邻插入Quadlist
Quadlist<T>::insert( T const& e, QNodePosi<T> p, QNodePosi<T> b )
{ _size++; return p->insert( e, b ); } //返回新节点位置（below = NULL）
#endif
