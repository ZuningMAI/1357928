#ifndef PQ_LIST_H
#define PQ_LIST_H

#include "PQ/PQ.h" //引入优先级队列ADT
#include "list/list.h" //引入列表
template <typename T> class PQ_List : public PQ<T>, public List<T> { //基于列表实现的优先级队列
   /*DSA*/friend class UniPrint; //演示输出使用，否则不必设置友类
public:
   PQ_List() { } //默认构造
   PQ_List ( T* E, int n ) { while ( 0 < n-- ) insertFirst ( ( E[n] ) ); } //批量构造
   void insert ( T e ) { List<T>::insertLast ( e ); } //直接将新元素插至队列末尾
   T delMax() { return List<T>::remove( List<T>::selectMax() ); } //删除优先级最高的元素
   T & getMax() { return List<T>::selectMax()->data; } //取出优先级最高的元素
}; //PQ_List

#endif
