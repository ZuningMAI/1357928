#ifndef DECREASE_VECTOR_H
#define DECREASE_VECTOR_H

template <typename T> void decrease( Vector<T> & V ) //统一递减向量中的各元素
   { Decrease<T> a;V.traverse( a ); }; //以Decrease<T>()为基本操作进行遍历

#endif
