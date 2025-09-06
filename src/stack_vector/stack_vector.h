#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

// 添加宏定义检查，防止与其他Stack定义冲突
#ifdef DSA_STACK_VECTOR

#include "vector/vector.h"

template <typename T> class Stack: public Vector<T> { //将向量的首/末端作为栈底/顶
public: //原有接口一并沿用
   void push ( T const& e ) { this->insert ( e ); } //入栈，等效于将新元素作为向量的末元素插入
   T pop() { return this->remove ( this->size() - 1 ); } //出栈，等效于删除向量的末元素
   T& top() { return ( *this ) [this->size() - 1]; } //取顶，直接返回向量的末元素
};

#endif // DSA_STACK_VECTOR

#endif // STACK_VECTOR_H