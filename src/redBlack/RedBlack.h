#ifndef REDBLACK_H
#define REDBLACK_H

#include "BST/BST.h" //基于BST实现RedBlack
template <typename T> class RedBlack : public BST<T> { //RedBlack树模板类
protected:
   void solveDoubleRed( BinNodePosi<T> x ); //双红修正
   void solveDoubleBlack( BinNodePosi<T> x ); //双黑修正
public:
   BinNodePosi<T> insert( const T& e ); //插入（重写）
   bool remove( const T& e ); //删除（重写）
// BST::search()等其余接口可直接沿用
};

#include "RedBlack_implementation.h"
#endif
