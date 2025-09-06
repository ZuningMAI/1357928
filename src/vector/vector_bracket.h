#ifndef VECTOR_BRACKET_H
#define VECTOR_BRACKET_H 

#include "vector.h"
#include <stdexcept> // 用于std::out_of_range异常

template <typename T> T & Vector<T>::operator[] ( Rank r ) //重载下标操作符
{ 
    if (r >= _size) // 实际的边界检查，修复无符号数比较警告
        throw std::out_of_range("Index out of range in Vector::operator[]");
    return _elem[r]; 
}

template <typename T> const T & Vector<T>::operator[] ( Rank r ) const //仅限于做右值
{ 
    if (r >= _size) // 实际的边界检查，修复无符号数比较警告
        throw std::out_of_range("Index out of range in Vector::operator[] const");
    return _elem[r]; 
}


#endif