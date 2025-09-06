#ifndef LISTNODE_INSERTASPRED_H
#define LISTNODE_INSERTASPRED_H 

// #include "listNode.h"
template <typename T> //将e紧靠当前节点之前插入于当前节点所属列表（设有哨兵head）
ListNodePosi<T> ListNode<T>::insertPred( T const& e ) {
   ListNodePosi<T> x = new ListNode( e, pred, this ); //创建新节点
   pred->succ = x; pred = x; //设置正向链接
   return x; //返回新节点的位置
}


#endif