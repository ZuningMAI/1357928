
#ifndef PRINT_H
#define PRINT_H



#define PRINT(x)  { print(x); crc(x); checkOrder(x); printf("\n"); }

#include <cstdio> //采用C风格精细控制输出格式
#ifndef RPN_RUN
#include "binTree/BinTree.h" //
#include "huffman/huffChar.h" //Huffmanַ
#include "Huffman/HuffTree.h" //Huffman
#include "BST/BST.h" //
#include "AVL/AVL.h" //AVL
#include "splay/Splay.h" //չ
#include "redBlack/RedBlack.h" //
#include "BTree/BTree.h" //
#include "Entry/Entry.h" //
#include "Skiplist/Quadlist.h" //Ĳ
#include "Skiplist/Skiplist.h" //ת
#include "hashtable/Hashtable.h" //ɢб
#include "PQ_List/PQ_List.h" //бʵֵȼ
#include "PQ_ComplHeap/PQ_ComplHeap.h" //ȫʵֵȼ
#include "PQ_LeftHeap/PQ_LeftHeap.h" //ʽʵֵȼ
#include "graph/Graph.h" //ͼ
#include "graphMatrix/GraphMatrix.h" //ڽӾʵֵͼ

#endif


class UniPrint {
public:
   static void p ( int );
   static void p ( size_t );
   #ifndef MSVC
   static void p ( unsigned int );
   #endif
   static void p ( float );
   static void p ( double );
   static void p ( char );
   #ifndef RPN_RUN
   static void p ( HuffChar& ); //Huffmanַ
   static void p ( VStatus ); //ͼ״̬
   static void p ( EType ); //ͼߵ
   #endif

  
   #ifndef RPN_RUN
   template <typename K, typename V> static void p( Entry<K, V>& ); // Entry
   template <typename T> static void p( BinNode<T>& b ) { p( &b ); }; // BinTreeڵ
   template <typename T> static void p( BinNodePosi<T> ); // BinTreeڵ
   template <typename T> static void p( BinTree<T>& ); //
   template <typename T> static void p( BST<T>& ); // BST
   template <typename T> static void p( AVL<T>& ); // AVL
   template <typename T> static void p( Splay<T>& ); // Splay
   template <typename T> static void p( BTree<T>& ); // B+
   template <typename T> static void p( RedBlack<T>& ); // RedBlack
   template <typename K, typename V> static void p( Hashtable<K, V>& ); // Hashtable
   template <typename T> static void p( Quadlist<T>& ); // Quadlist
   template <typename K, typename V> static void p( Skiplist<K, V>& ); // Skiplist
   template <typename T> static void p( PQ_List<T>& ); // PQ_List
   template <typename T> static void p( PQ_ComplHeap<T>& ); // PQ_ComplHeap
   template <typename T> static void p( PQ_LeftHeap<T>& ); // PQ_LeftHeap
   #endif
   #ifndef RPN_RUN
   template <typename Tv, typename Te> static void p( GraphMatrix<Tv, Te>& ); // Graph
   #endif
   template <typename T> static void p( T& ); //向量、列表等支持traverse()遍历操作的线性结构
   template <typename T> static void p( T* s ) //指针所有指针
   { if (s) p(*s); else printf("<NULL>");} //统一转为引用
}; //UniPrint

/******************************************************************************************
 * 数据元素、数据结构通用输出接口
 ******************************************************************************************/
template <typename T> static void print ( T* x ) {  if (x) print ( *x ); else printf ( " <NULL>" );   }
template <typename T> static void print ( T& x ) {  UniPrint::p ( x );  }
template <typename T> static void print ( const T& x ) {  UniPrint::p ( x );  } //for Stack
static void print ( char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //ַر
static void print ( const char* x ) {  printf ( " %s", x ? x : "<NULL>" );  } //ַر

#include "print_implementation.h"

#endif