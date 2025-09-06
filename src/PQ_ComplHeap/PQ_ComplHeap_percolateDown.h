#ifndef PQ_COMPLHEAP_PERCOLATEDOWN_H
#define PQ_COMPLHEAP_PERCOLATEDOWN_H

#include "PQ_ComplHeap_macro.h"
//对向量前n个词条中的第i个实施下滤，i < n
template <typename T> Rank percolateDown( T* A, Rank n, Rank i ) {
   Rank j; // i及其（至多两个）孩子中，堪为父者
   while ( i != ( j = ProperParent( A, n, i ) ) ) //只要i非j，则
      swap( A[i], A[j] ), i = j; //二者换位，并继续考查下降后的i
   return i; //返回下滤抵达的位置（亦i亦j）
}
#endif
