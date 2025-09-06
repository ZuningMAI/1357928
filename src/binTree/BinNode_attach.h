#ifndef BINNODE_ATTACH_H
#define BINNODE_ATTACH_H

template <typename T> void BinNode<T>::attachLc( BinNodePosi<T> x )
   { lc = x; if ( x ) x->parent = this; } //接入左子树

template <typename T> void BinNode<T>::attachRc( BinNodePosi<T> x )
   { rc = x; if ( x ) x->parent = this ; } //接入右子树

#endif
