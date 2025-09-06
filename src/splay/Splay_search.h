#ifndef SPLAY_SEARCH_H
#define SPLAY_SEARCH_H

template <typename T> BinNodePosi<T>& Splay<T>::search( const T& e ) { //在伸展树中查找e
   BinNodePosi<T> p = BST<T>::search( e ); //按BST标准算法查找
   this->_root = p ? splay(p) : this->_hot ? splay(this->_hot) : NULL;  //无论成功、失败、树空，被访问的节点将伸展至根
   return this->_root;
} //与其它BST不同，无论如何，_root都指向最后被访问的节点
#endif