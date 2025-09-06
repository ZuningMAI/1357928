#ifndef BINNODE_INSERT_H
#define BINNODE_INSERT_H

template <typename T> BinNodePosi<T> BinNode<T>::insertLc( T const& e )
   { return lc = new BinNode<T>( e, this ); } //将e作为当前节点的左孩子插入二叉树

template <typename T> BinNodePosi<T> BinNode<T>::insertRc( T const& e )
   { return rc = new BinNode<T>( e, this ); } //将e作为当前节点的右孩子插入二叉树


   

#endif
