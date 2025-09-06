#ifndef HASHTABLE_GET_H
#define HASHTABLE_GET_H

template <typename K, typename V> V* Hashtable<K, V>::get( K k ) //散列表词条查找算法
   { int r = probe4Hit ( k ); return ht[r] ? &( ht[r]->value ) : NULL; } //禁止词条相等

#endif
