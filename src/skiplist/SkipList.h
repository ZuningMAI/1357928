#ifndef SKIPLIST_H
#define SKIPLIST_H

#include "list/list.h" //引入列表
#include "Entry/Entry.h" //引入词条
#include "Quadlist.h" //引入Quadlist
#include "Dictionary/Dictionary.h" //引入词典

template <typename K, typename V> //key、value
//符合Dictionary接口的Skiplist模板类（隐含假设元素之间可比较大小）
struct Skiplist : public Dictionary<K, V>, public List< Quadlist< Entry<K, V> >* > {
   Skiplist() { this->insertFirst( new Quadlist< Entry<K, V> > ); } //即便为空，也有一层空列表
   QNodePosi< Entry<K, V> > search( K ); //由关键码查询词条
   Rank size() const { return this->empty() ? 0 : this->last()->data->_size; } //词条总数
   Rank height() { return List< Quadlist< Entry<K, V> >* >::size(); } //层高 == #Quadlist
   V* get( K ); //读取
   bool put(K, V); //插入（Skiplist允许词条相等，故必然成功）
   bool remove ( K ); //删除
};

#include "Skiplist_implementation.h"
#endif