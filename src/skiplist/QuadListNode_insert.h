#ifndef QUADLISTNODE_INSERT_H
#define QUADLISTNODE_INSERT_H

template <typename T> QNodePosi<T> //将e作为当前节点的后继、b的上邻插入Quadlist
QNode<T>::insert( T const& e, QNodePosi<T> b ) {
   QNodePosi<T> x = new QNode<T>( e, this, succ, NULL, b ); //创建新节点
   succ->pred = x; succ = x; //设置水平逆向链接
   if ( b ) b->above = x; //设置垂直逆向链接
   return x; //返回新节点的位置
}
#endif
