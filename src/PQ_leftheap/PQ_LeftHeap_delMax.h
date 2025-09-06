#ifndef PQ_LEFTHEAP_DELMAX_H
#define PQ_LEFTHEAP_DELMAX_H

template <typename T> T PQ_LeftHeap<T>::delMax() {
   BinNodePosi<T> lHeap = this->_root->lc; if ( lHeap ) lHeap->parent = NULL; //左子堆
   BinNodePosi<T> rHeap = this->_root->rc; if ( rHeap ) rHeap->parent = NULL; //右子堆
   T e = this->_root->data; delete this->_root; this->_size--; //删除根节点
   this->_root = merge( lHeap, rHeap ); //合并原左、右子堆
   return e; //返回原根节点的数据项
}

#endif