#ifndef QUEUE_H
#define QUEUE_H

#include "list/list.h" //以List为基类派生出的
template <typename T> class Queue: public List<T> { //队列模板类
public: //原有接口一概沿用
   
   void enqueue( T const& e ) { List<T>::insertLast( e ); } //入队：尾部插入
   T dequeue() { return this->remove( List<T>::first() ); } //出队：首部删除
   T& front() { return this->first()->data; } //队首
};

#include "queue_implementation.h"

#endif
