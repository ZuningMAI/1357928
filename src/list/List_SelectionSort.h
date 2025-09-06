#ifndef LIST_SELECTION_SORT_H
#define LIST_SELECTION_SORT_H 

#include "list.h"


template <typename T> //对列表中起始于位置p、宽度为n的区间做选择排序
void List<T>::selectionSort( ListNodePosi<T> p, Rank n ) { // valid(p) && Rank(p) + n <= size
   /*DSA*///printf ( "SelectionSort ...\n" );
   ListNodePosi<T> h = p->pred; //待排序区间为(h, t)
   ListNodePosi<T> t = p; 
   for ( Rank i = 0; i < n; i++ ) t = t->succ;
   while ( 1 < n ) { //在至少还剩两个节点之前，在待排序区间内
      ListNodePosi<T> max = selectMax ( h->succ, n ); //找出最大者（歧义时后者优先）
      insert( remove( max ), t ); //将其移至无序区间末尾（作为有序区间新的首元素）
      /*DSA*///swap(tail->pred->data, selectMax( head->succ, n )->data );
      t = t->pred; n--;
   }
}
#endif