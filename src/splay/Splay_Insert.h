#ifndef SPLAY_INSERT_H
#define SPLAY_INSERT_H

template <typename T> BinNodePosi<T> Splay<T>::insert( const T& e ) { //将关键码e插入伸展树中
   if ( !this->_root ) { this->_size = 1; return this->_root = new BinNode<T>( e ); } //原树为空
   BinNodePosi<T> t = search( e );
   if ( e == t->data ) return t; //目标节点t若存在，伸展至根
   if ( t->data < e ) //在右侧嫁接
      { t->parent = this->_root = new BinNode<T>( e, NULL, t, t->rc ); t->rc = NULL; }
   else //在左侧嫁接
      { t->parent = this->_root = new BinNode<T>( e, NULL, t->lc, t ); t->lc = NULL; }
   this->_size++; t->updateHeightAbove(); return this->_root; //更新规模及高度，报告插入成功
} //无论e是否存在于原树中，返回时总有_root->data == e

#endif