#ifndef SKIPLIST_GET_H
#define SKIPLIST_GET_H

template <typename K, typename V> V* Skiplist<K, V>::get( K k ) { //跳转表词条查找算法
   QNode< Entry<K, V> >* p = search(k); //无论是否命中，search()都不会返回NULL
   return (p->pred && p->entry.key == k) ? &(p->entry.value) : NULL; //故须再做判断
} //有多个命中时靠后者优先
#endif
