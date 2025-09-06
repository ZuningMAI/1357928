#ifndef REDBLACK_UPDATEHEIGHT_H
#define REDBLACK_UPDATEHEIGHT_H

template <typename T> Rank BinNode<T>::updateHeight() { //更新节点高度
   return height = color + max( stature( lc ), stature( rc ) ); //孩子黑高度通常相等，除非出现双黑
   /*DSA*/// 红黑树中各节点左、右孩子的黑高度通常相等
   /*DSA*/// 这里之所以取更大值，是便于在删除节点后的平衡调整过程中，正确更新被删除节点父亲的黑高度
   /*DSA*/// 否则，rotateAt()会根据被删除节点的替代者（高度小一）设置父节点的黑高度
}

template <typename T> void BinNode<T>::updateHeightAbove() //更新当前节点及其祖先的高度
   { for ( BinNodePosi<T> x = this; x; x = x->parent ) x->updateHeight(); } //可优化

#endif
