#ifndef AVL_INSERT_H
#define AVL_INSERT_H

template <typename T> BinNodePosi<T> AVL<T>::insert( const T& e ) { //将关键码e插入AVL树中
   BinNodePosi<T>& x = this->search( e ); if ( x ) return x; //插入失败
   BinNodePosi<T> xx = x = new BinNode<T>( e, this->_hot ); this->_size++; //创建新节点x
// 此时，x的父亲_hot若增高，则其祖父有可能失衡
   for ( BinNodePosi<T> g = this->_hot; g; g->updateHeight(), g = g->parent ) //逐层上溯
      if ( !AvlBalanced( g ) ) { //一旦发现失衡祖先g，则
         this->rotateAt( tallerChild( tallerChild( g ) ) ); //（采用“3+4”算法）使之复衡
         break; //并随即终止（局部子树复衡后，高度必然复原；所有祖先亦必复衡）
      }
   return xx; //插入成功
} //至多会做O(1)次调整

#endif