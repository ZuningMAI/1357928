#ifndef PQ_COMPLHEAP_HEAPIFY_NAIVE_H
#define PQ_COMPLHEAP_HEAPIFY_NAIVE_H

template <typename T> void heapify( T* A, const Rank n ) { //蛮力建堆算法，O(nlogn)时间
   for ( Rank i = 1; i < n; i++ ) //自顶而下，依次
      percolateUp( A, i ); //经上滤插入各节点
}

#endif
