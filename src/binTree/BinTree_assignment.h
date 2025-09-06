#ifndef BINTREE_ASSIGNMENT_H
#define BINTREE_ASSIGNMENT_H

template <typename T> BinTree<T> & BinTree<T>::operator= ( BinTree<T> const & s ) { //赋值操作符
   if (this != &s) { //防止自赋值
      if (_root) remove(_root); //先清除原树
      _size = s._size;
      _root = NodeCopy<T>(NULL, s._root);
   }
   return *this;
}
#endif