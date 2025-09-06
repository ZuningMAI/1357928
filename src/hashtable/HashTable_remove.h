#ifndef HASHTABLE_REMOVE_H
#define HASHTABLE_REMOVE_H

template <typename K, typename V> bool Hashtable<K, V>::remove( K k ) { //散列表词条删除算法
   Rank r = probe4Hit( k ); if ( !ht[r] ) return false; //确认目标词条确实存在
   delete ht[r]; ht[r] = NULL; --N; //清除词条
   removed->set(r); //设置懒惰删除标记
   return true;
}
#endif
