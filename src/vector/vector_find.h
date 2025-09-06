#ifndef VECTOR_FIND_H
#define VECTOR_FIND_H 

// #include "vector.h"

template <typename T> //在无序向量中顺序查找e：0 <= lo < hi <= _size
Rank Vector<T>::find ( T const& e, Rank lo, Rank hi ) const { //O(hi-lo)
   while ( ( lo < hi-- ) && ( e != _elem[hi] ) ); //从后向前，顺序查找
   return hi; //最靠后的命中者，或lo-1示意失败（lo == 0时呢？）
}

#endif