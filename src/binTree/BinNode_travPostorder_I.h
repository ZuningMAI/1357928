#ifndef BINNODE_TRAVPOSTORDER_I_H
#define BINNODE_TRAVPOSTORDER_I_H

#include "stack/stack.h"

// #if defined(DSA_STACK_LIST) || defined(DSA_STACK_VECTOR)
template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
static void gotoLeftmostLeaf( Stack<BinNodePosi<T>>& S ) { //沿途所遇节点依次入栈
   while ( BinNodePosi<T> x = S.top() ) //自顶而下，反复检查当前节点（即栈顶）
      if ( x->lc ) { //尽可能向左
         if ( x->rc ) S.push( x->rc ); //若有右孩子，优先入栈
         S.push( x->lc ); //然后才转至左孩子
      } else //实不得已
         S.push( x->rc ); //才向右
   S.pop(); //返回之前，弹出栈顶的空节点
}

template <typename T, typename VST>
void travPost_I( BinNodePosi<T> x, VST& visit ) { //二叉树的后序遍历（迭代版）
   Stack<BinNodePosi<T>> S; //辅助栈
   if ( x ) S.push( x ); //根节点入栈
   while ( !S.empty() ) { // x始终为当前节点
      if ( S.top() != x->parent ) ////若栈顶非x之父（而为右兄）
         gotoLeftmostLeaf( S ); //则在其右兄子树中找到HLVFL（相当于递归深入）
      x = S.pop(); visit( x->data ); //弹出栈顶（即前一节点之后继），并访问之
   }
}
// #endif


#endif
/*
 J   *      ┌─ J
 K ! *── K !
 F   *      │                ┌─ F
 G ! *      │          ┌─ G !
 D   *      │          │    │    ┌─ D
 e ! *      │          │    └─ e !
 C   *      │          │          └─ C
 h ! *      │    ┌─ h !
 a   *      │    │    │    ┌─ a
 b ! *      │    │    └─ b !
 i ! *      └─ i !



| 沿途所遇节点依次入栈S                     | 访问元素       |
| ------------------------------- | ---------- |
| [K]                             |            |
| [K,J,i,h,G,b,a,(^)],pop ^       | a,visit(a) |
| [K,J,i,h,G,b],a->parent = b     |            |
| [K,J,i,h,G,b],pop b             | b,visit(b) |
| b->parent=h ! = b               |            |
| [K,J,i,h,G,F,e,D,c,(^)],pop(^), | c,visit(c) |
| c->parent=e !=D                 |            |
| [K,J,i,h,G,F,e,D,(^)],pop ^     |            |
| [K,J,i,h,G,F,e]                 | D,visit(D) |
| [K,J,i,h,G,F,e],D->parent = e   |            |
| [K,J,i,h,G,F]                   | e,visit(e) |
| [K,J,i,h,G,F]                   |            |
| [K,J,i,h,G]                     | F,visit(F) |
| [K,J,i,h]                       | G,visit(G) |
| [K,J,i]                         | h,visit(h) |
| [K,J]                           | i,visit(i) |
| [K,J]                           |            |
| [K]                             | J,visit(J) |
| []                              | K,visit(K) |


*/