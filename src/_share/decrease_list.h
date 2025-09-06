#ifndef DECREASE_LIST_H
#define DECREASE_LIST_H

template <typename T> void decrease( List<T> & L ) //统一递减向量中的各元素
   { Decrease<T> a;L.traverse( a ); }; //以Decrease<T>()为基本操作进行遍历

#endif
