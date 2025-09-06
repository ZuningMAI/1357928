#ifndef BINNODE_TRAVPREORDER_I1_H
#define BINNODE_TRAVPREORDER_I1_H

#include "stack/stack.h"

// #if defined(DSA_STACK_LIST) || defined(DSA_STACK_VECTOR)
template <typename T, typename VST> //元素类型、操作器
void travPre_I1( BinNodePosi<T> x, VST& visit ) { //二叉树先序遍历算法（迭代版#1）
   Stack<BinNodePosi<T>> S; //辅助栈
   if ( x ) S.push( x ); //根节点入栈
   while ( !S.empty() ) { //在栈变空之前反复循环
      x = S.pop(); visit( x->data ); //弹出并访问当前节点，其非空孩子的入栈次序为先右后左
      if ( x->rc ) S.push( x->rc );
      if ( x->lc ) S.push( x->lc );
   }
}
// #endif

#endif
/*
二叉树T 如下：
 f   *            ┌─ f
 c ! *      ┌─ c !
 e   *      │    │    ┌─ e
 d ! *      │    └─ d !
 a ! *── a !
 b   *      └─ b


| 被访问的节点 | 栈S         |
| ------- | ---------- |
| a       | [c,b]      |
| b       | [c]        |
| c       | [f,e,d]    |
| d       | [f,e]      |
| e       | [f]        |
| f       | [g]        |
| g       | []         |


 */