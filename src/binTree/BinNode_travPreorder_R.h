#ifndef BINNODE_TRAVPREORDER_R_H
#define BINNODE_TRAVPREORDER_R_H

template <typename T, typename VST> //元素类型、操作器
void travPre_R( BinNodePosi<T> x, VST& visit ) { //二叉树先序遍历算法（递归版）
   if ( !x ) return;
   visit( x->data );
   travPre_R( x->lc, visit );
   travPre_R( x->rc, visit );
}
// T(n) = O(1) + T(a) + T(n-a-1) = O(n)
#endif
