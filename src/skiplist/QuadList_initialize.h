#ifndef QUADLIST_INITIALIZE_H
#define QUADLIST_INITIALIZE_H

template <typename T> void Quadlist<T>::init() { //Quadlist初始化，创建Quadlist对象时统一调用
   head = new QNode<T>; //创建头哨兵节点
   tail = new QNode<T>; //创建尾哨兵节点
   head->succ = tail; head->pred = NULL; //沿横向联接哨兵
   tail->pred = head; tail->succ = NULL; //沿横向联接哨兵
   head->above = tail->above = NULL; //纵向的后继置空
   head->below = tail->below = NULL; //纵向的前驱置空
   _size = 0; //记录规模
} //如此构造的四联表，不含任何实质的节点，且暂时与其它四联表相互独立
#endif
