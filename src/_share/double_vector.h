#ifndef DOUBLE_VECTOR_H
#define DOUBLE_VECTOR_H

#include "vector/vector.h"
template <typename T> void double( Vector<T> & V ) //统一加倍向量中的各元素
   { Double<T> a;V.traverse( a ); }; //以Double<T>()为基本操作进行遍历

#endif
