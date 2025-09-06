#ifndef BST_REMOVE_H
#define BST_REMOVE_H

template <typename T> bool BST<T>::remove( const T& e ) { //从BST树中删除关键码e
   BinNodePosi<T>& x = search( e ); if ( !x ) return false; //确认目标存在（留意_hot的设置）
   removeAt( x, this->_hot ); //实施删除
   this->_size--; this->_hot->updateHeightAbove(); //更新全树高度，以及历代祖先的高度
   return true;
} //删除成功与否，由返回值指示

#endif