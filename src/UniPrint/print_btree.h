#ifndef PRINT_BTREE_H
#define PRINT_BTREE_H

/******************************************************************************************
 * BTree打印
 ******************************************************************************************/
#include "Bitmap/Bitmap.h" //使用位图记录分支转向

/******************************************************************************************
 * BTree打印入口：
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p ( BTree<T> & bt ) { //打印
   printf ( "%s[%d]*%d:\n", typeid ( bt ).name(), (int) &bt, bt.size() ); //基本信息
   Bitmap* leftmosts = new Bitmap; //记录当前节点各层的左邻
   Bitmap* rightmosts = new Bitmap; //记录当前节点各层的右邻
   printBTree ( bt.root(), 0, true, true, leftmosts, rightmosts ); //打印树状结构
   delete leftmosts; delete rightmosts; printf ( "\n" );
}

/******************************************************************************************
 * BTree打印（递归）
 ******************************************************************************************/
template <typename T> //元素类型
static void printBTree ( BTNodePosi<T> bt, int depth, bool isLeftmost, bool isRightmost, Bitmap* leftmosts, Bitmap* rightmosts ) {
   if ( !bt ) return;
   isLeftmost ? leftmosts->set ( depth ) : leftmosts->clear ( depth ); //更新左侧拐点标志
   isRightmost ? rightmosts->set ( depth ) : rightmosts->clear ( depth ); //更新右侧拐点标志
   int k = bt->child.size() - 1; //找到当前节点的最右孩子
   printBTree ( bt->child[k], depth + 1, false, true, leftmosts, rightmosts ); //递归打印之
   /*DSA*/bool parentOK = false; BTNodePosi<T> p = bt->parent;
   /*DSA*/if ( !p ) parentOK = true;
   /*DSA*/else for ( Rank i = 0; i < p->child.size(); i++ ) if ( p->child[i] == bt ) parentOK = true;
   while ( 0 < k-- ) { //自右向左打印各关键码及其左右分支
      /*DSA*/printf ( parentOK ? " " : "X" );
      print ( bt->key[k] ); printf ( " *>" );
      for ( int i = 0; i < depth; i++ ) //打印每一层的横向连接
         ( leftmosts->test ( i ) && leftmosts->test ( i + 1 ) || rightmosts->test ( i ) && rightmosts->test ( i + 1 ) ) ? //拐点是否一致，来决定
         printf ( "      " ) : printf ( "│    " ); //是否应该打印横向连接
      if ( ( ( 0 == depth && 1 < bt->key.size() ) || !isLeftmost && isRightmost ) && bt->key.size() - 1 == k ) printf ( "┌─" );
      else if ( ( ( 0 == depth && 1 < bt->key.size() ) || isLeftmost && !isRightmost ) && 0 == k )            printf ( "└─" );
      else                                                                                               printf ( "├─" );
      print ( bt->key[k] ); printf ( "\n" );
      printBTree ( bt->child[k], depth + 1, 0 == k, false, leftmosts, rightmosts ); //递归打印左子树
   }
}
#endif
