#ifndef PQ_COMPLHEAP_HEAPIFY_FLOYD_H
#define PQ_COMPLHEAP_HEAPIFY_FLOYD_H

#include "PQ_ComplHeap_percolateDown.h"

template <typename T> void heapify( T* A, const Rank n ) { //Floyd建堆算法，O(n)时间
   for ( Rank i = n / 2 - 1; - 1 != i; i-- ) //自底而上，依次
      percolateDown( A, n, i ); //经下滤合并子堆
}
#endif
