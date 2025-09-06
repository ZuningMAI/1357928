#ifndef PQ_COMPLHEAP_PERCOLATEUP_H
#define PQ_COMPLHEAP_PERCOLATEUP_H

template <typename T> Rank percolateUp( T* A, Rank i ) { //对词条A[i]做上滤，0 <= i < _size
   while ( 0 < i ) { //在抵达堆顶之前，反复地
      Rank j = Parent( i ); //考查[i]之父亲[j]
      if ( !( A[j] < A[i] ) ) break; //一旦父子顺序，上滤旋即完成；否则
      swap( A[i], A[j] ); i = j; //父子换位，并继续考查上一层
   } //while
   return i; //返回上滤最终抵达的位置
}

#endif
