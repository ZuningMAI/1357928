#ifndef PRINT_SKIPLIST_H
#define PRINT_SKIPLIST_H

/******************************************************************************************
 * Skiplist
 ******************************************************************************************/

template <typename K, typename V> //元素value
void UniPrint::p ( Skiplist<K, V>& s ) { //引用
   printf ( "%s[%p]*%d*%d:\n", typeid ( s ).name(), (void*) &s, s.height(), s.size() ); //基本信息
   s.traverse ( print ); //通过print()遍历打印各层
   printf ( "\n" );
}

#endif
