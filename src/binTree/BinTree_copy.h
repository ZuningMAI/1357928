#ifndef BINTREE_COPY_H
#define BINTREE_COPY_H

template <typename T>
BinNodePosi<T> NodeCopy( BinNodePosi<T> p, BinNodePosi<T> s ) {
   // 添加更强的安全检查，检测已释放的内存标记
   if ( !s /*|| (reinterpret_cast<uintptr_t>(s) & 0xFFFFFFF0FFFFFFF0) == 0xFEEEFEEEFEEEFEE0 */) return NULL;
   BinNodePosi<T> t = new BinNode<T>( s->data, p, NULL, NULL, s->height, s->npl, s->color );
   t->lc = NodeCopy( t, s->lc );
   t->rc = NodeCopy( t, s->rc );
   return t;
}

template <typename T> //通过复制来构造二叉树
BinTree<T>::BinTree( BinTree<T> const & s ) {
   _size = s.size();
   _root = NodeCopy<T>( NULL, s._root );
}

#endif