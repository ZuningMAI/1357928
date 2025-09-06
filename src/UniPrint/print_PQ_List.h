#ifndef PRINT_PQ_LIST_H
#define PRINT_PQ_LIST_H

/******************************************************************************************
 * 打印输出PQ_List
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p ( PQ_List<T> & pq ) { //引用
   printf ( "%s*%d:\n", typeid ( pq ).name(), pq.size() ); //基本信息
   p ( ( List<T> & ) pq ); printf ( "\n" );
}

#endif
