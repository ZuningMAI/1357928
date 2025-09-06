#ifndef BST_INSERT_H
#define BST_INSERT_H

template <typename T> BinNodePosi<T> BST<T>::insert( const T& e ) { //将关键码e插入BST树中
   BinNodePosi<T>& x = search( e ); //通过查找
   if ( x ) return x; //确认目标不存在，并设置_hot
   x = new BinNode<T>( e, this->_hot ); //在x处创建新节点，以_hot为父
   this->_size++; x->updateHeightAbove(); //更新全树规模，以及历代祖先的高度
   return x; //新插入的节点，必为叶子
} //无论e是否存在于原树中，返回时总有x->data == e

#endif