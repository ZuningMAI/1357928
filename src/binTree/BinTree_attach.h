#ifndef BINTREE_ATTACH_H
#define BINTREE_ATTACH_H

template <typename T> //将S当作节点x的左子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attach( BinTree<T> S, BinNodePosi<T> x ) { // x->lc == NULL
   if ( x->lc = S._root ) x->lc->parent = x; //接入
   _size += S._size; x->updateHeightAbove(); //更新全树规模与x所有祖先的高度
   S._root = NULL; S._size = 0; return x; //释放原树，返回接入位置
}

template <typename T> //将S当作节点x的右子树接入二叉树，S本身置空
BinNodePosi<T> BinTree<T>::attach( BinNodePosi<T> x, BinTree<T> S ) { // x->rc == NULL
   if ( x->rc = S._root ) x->rc->parent = x; //接入
   _size += S._size; x->updateHeightAbove(); //更新全树规模与x所有祖先的高度
   S._root = NULL; S._size = 0; return x; //释放原树，返回接入位置
}


#endif
/*
```cpp
BinTree<T> btB( btA );
BinNodePosi<T> p;
p = btB.root(); while (p->lc) p = p->lc; btB.attach( btA, p );
p = btB.root(); while (p->lc) p = p->lc; btB.attach( btA, p );
BinNodePosi<T> q;
q = btB.root(); while (q->rc) q = q->rc; btB.attach( q, btA );
q = btB.root(); while (q->rc) q = q->rc; btB.attach( q, btA );
```
btB = btA
class BinTree<int>[8453436]*5:
   45   *      ┌─   45
   40   *      │    │    ┌─   40
   68   *      │    └─   68
  148   *──  148
   61   *      └─   61

Create a HART by attaching
class BinTree<int>[8453436]*25:
   45   *                              ┌─   45
   40   *                              │    │    ┌─   40
   68   *                              │    └─   68
  148   *                        ┌─  148
   61   *                        │    └─   61
   45   *                  ┌─   45
   40   *                  │    │    ┌─   40
   68   *                  │    └─   68
  148   *            ┌─  148
   61   *            │    └─   61
   45   *      ┌─   45
   40   *      │    │    ┌─   40
   68   *      │    └─   68
  148   *──  148
   61   *      └─   61
   45   *            │    ┌─   45
   40   *            │    │    │    ┌─   40
   68   *            │    │    └─   68
  148   *            └─  148
   61   *                  └─   61
   45   *                        │    ┌─   45
   40   *                        │    │    │    ┌─   40
   68   *                        │    │    └─   68
  148   *                        └─  148
   61   *                              └─   61

*/
