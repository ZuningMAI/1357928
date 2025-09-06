#ifndef CHECKORDER_LIST_H
#define CHECKORDER_LIST_H

#include "list/list.h"

template <typename T> void checkOrder ( List<T> & L ) { //判断向量是否整体有序
   int nInv = 0; //逆序计数器
   CheckOrder<T> checker(nInv,L.first()->data);
   L.traverse ( checker );
   // V.traverse ( CheckOrder<T> ( unsorted, V[0] ) ); //进行遍历
   if ( 0 < nInv )
      printf ( "Unsorted with %d adjacent inversion(s)\n", nInv );
   else
      printf ( "Sorted\n" );
}
#endif
