#ifndef LIST_REVERSE1_H
#define LIST_REVERSE1_H

// #include "list.h"

template <typename T> void List<T>::reverse() { //前后倒置
   ListNodePosi<T> p = head; ListNodePosi<T> q = tail; //头、尾节点
   for ( Rank i = 1; i < _size; i += 2 ) //（从首、末节点开始）由外而内，捉对地
      swap( ( p = p->succ )->data, ( q = q->pred )->data ); //交换对称节点的数据项
}
#endif