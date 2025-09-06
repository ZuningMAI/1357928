#ifndef LISTNODE_H
#define LISTNODE_H


using Rank = unsigned int; //秩

template <typename T> struct ListNode;
template <typename T> using ListNodePosi = ListNode<T>*; //列表节点位置

/******************************************************
 *        ListNode列表节点模板类（以双向链表形式实现）
 * @param T 模板数据类型
 * @param data 数据域
 * @param prev 前向指针（前驱）
 * @param next 后向指针（后继）
 * +---------------------------+
*|       ListNode<T>          |
*+---------------------------+
*| - T            data       | // 数据域
*| - ListNode<T>*   prev     | // 前驱指针
*| - ListNode<T>*   next     | // 后继指针
*+---------------------------+
 *****************************************************/

template <typename T> struct ListNode { 
   T data; ListNodePosi<T> pred, succ; //数值、前驱、后继
// 构造方法
   ListNode() {} //针对head和tail的构造
   ListNode ( T const& e, ListNodePosi<T> p = NULL, ListNodePosi<T> s = NULL )
      : data( e ), pred( p ), succ( s ) {} //默认构造器（类T须定义复制方法）
// 操作接口
   ListNodePosi<T> insertPred( T const& e ); //紧靠当前节点之前插入新节点
   ListNodePosi<T> insertSucc( T const& e ); //紧随当前节点之后插入新节点
};

#include "listNode_implementation.h"
#endif