#ifndef QUADLISTNODE_H
#define QUADLISTNODE_H

#include "Entry/Entry.h"
template <typename T> struct QNode;
template <typename T> using QNodePosi = QNode<T>*; //跳转表节点位置
template <typename T> struct QNode { //四联节点
   T entry; //所存词条
   QNodePosi<T> pred, succ, above, below; //前驱、后继、上邻、下邻
   QNode( T e = T(), QNodePosi<T> p = NULL, QNodePosi<T> s = NULL,
          QNodePosi<T> a = NULL, QNodePosi<T> b = NULL ) //构造器
      : entry( e ), pred( p ), succ( s ), above( a ), below( b ) {}
   QNodePosi<T> insert( T const& e, QNodePosi<T> b = NULL ); //将e作为当前节点的后继、b的上邻插入
};

#include "QuadlistNode_implementation.h"
#endif
