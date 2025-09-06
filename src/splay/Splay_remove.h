#ifndef SPLAY_REMOVE_H
#define SPLAY_REMOVE_H

template <typename T> bool Splay<T>::remove( const T& e ) { //从伸展树中删除关键码e
   if ( !this->_root || ( e != search( e )->data ) ) return false; //若目标存在，则伸展至根
   BinNodePosi<T> L = this->_root->lc, R = this->_root->rc; delete this->_root; //记下左、右子树L、R后，释放之
   if ( !R ) { //若R空，则
      if ( L ) L->parent = NULL; this->_root = L; //L即是余树
   } else { //否则
      this->_root = R; R->parent = NULL; search( e ); //查找必败，但R的最小节点必伸展至根，且无左孩子
      this->_root->attachLc( L ); //故可令其以L作为左子树
   }
   if ( --this->_size ) this->_root->updateHeight(); return true; //更新规模及树高，报告删除成功
}

#endif