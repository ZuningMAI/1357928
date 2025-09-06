#ifndef BST_SEARCH_H
#define BST_SEARCH_H

template <typename T> BinNodePosi<T>& BST<T>::search( const T& e ) { //在BST中查找关键码e
   if ( !this->_root || e == this->_root->data ) { this->_hot = NULL; return this->_root; } //空树，或恰在树根命中
   for ( this->_hot = this->_root;; ) { //否则，自顶而下
      BinNodePosi<T>& v = ( e < this->_hot->data ) ? this->_hot->lc : this->_hot->rc; //确定方向，深入一层
      if ( !v || e == v->data ) return v; this->_hot = v; //一旦命中或抵达叶子，随即返回
   } //返回目标节点位置的引用，以便后续插入、删除操作
} //无论命中或失败，_hot均指向v之父亲（v是根时，hot为NULL）

#endif