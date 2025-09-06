#ifndef AVL_REMOVE_H
#define AVL_REMOVE_H

template <typename T> bool AVL<T>::remove( const T& e ) { //从AVL树中删除关键码e
   BinNodePosi<T>& x = this->search( e ); if ( !x ) return false; //删除失败
   removeAt( x, this->_hot ); this->_size--; //先按BST规则删除之（此后，原节点之父_hot及其祖先均可能失衡）
   for ( BinNodePosi<T> g = this->_hot; g; g->updateHeight(), g = g->parent ) //逐层上溯
      if ( !AvlBalanced( g ) ) //每当发现失衡祖先g，都
         this->rotateAt( tallerChild( tallerChild( g ) ) ); //（采用“3+4”算法）使之复衡
   return true; //删除成功
} //可能需做Omega(logn)次调整

#endif
