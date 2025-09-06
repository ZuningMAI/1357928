#ifndef CHECKORDER_VECTOR_H
#define CHECKORDER_VECTOR_H

#include "vector/vector.h"

template <typename T> void checkOrder ( Vector<T> & V ) { //判断向量是否整体有序
   int unsorted = 0; //逆序计数器
   CheckOrder<T> checker(unsorted,V[0]);
   V.traverse ( checker );
   // V.traverse ( CheckOrder<T> ( unsorted, V[0] ) ); //进行遍历
   if ( 0 < unsorted )
      printf ( "Unsorted with %d adjacent inversion(s)\n", unsorted );
   else
      printf ( "Sorted\n" );
}

#endif
