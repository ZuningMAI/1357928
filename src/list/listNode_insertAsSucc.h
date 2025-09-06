#ifndef LISTNODE_INSERTASSUCC_H
#define LISTNODE_INSERTASSUCC_H 

// #include "listNode.h"

template <typename T> //将e紧随当前节点之后插入于当前节点所属列表（设有哨兵tail）
ListNodePosi<T> ListNode<T>::insertSucc( T const& e ) {
   ListNodePosi<T> x = new ListNode( e, this, succ ); //创建新节点
   succ->pred = x; succ = x; //设置逆向链接
   return x; //返回新节点的位置
}

#endif