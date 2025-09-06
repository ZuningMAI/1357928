#ifndef BINTREE_REMOVE_H
#define BINTREE_REMOVE_H

template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
Rank BinTree<T>::remove( BinNodePosi<T> x ) { // assert: x为二叉树中的合法位置
    FromParentTo( x ) = NULL;
    x->parent->updateHeightAbove();
   /*
   if (  x && x->parent ) {
   FromParentTo( x ) = NULL; //切断来自父节点的指针
   try {
         x->parent->updateHeightAbove(); //更新祖先高度
      } catch (...) {
         // 忽略任何可能的异常
      }
   }else{FromParentTo( x ) = NULL;}
   */
   Rank n = removeAt( x ); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数
}
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
static Rank removeAt( BinNodePosi<T> x ) { // assert: x为二叉树中的合法位置
   if ( !x ) return 0; //递归基：空树
   Rank n = 1 + removeAt( x->lc ) + removeAt( x->rc ); //递归释放左、右子树
   delete x; return n; //释放被摘除节点，并返回删除节点总数
}



#endif
