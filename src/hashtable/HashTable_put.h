#ifndef HASHTABLE_PUT_H
#define HASHTABLE_PUT_H

template <typename K, typename V> bool Hashtable<K, V>::put( K k, V v ) { //散列表词条插入
   if ( ht[ probe4Hit( k ) ] ) return false; //忽略相等元素
   Rank r = probe4Free( k ); //找个空桶（只要装填因子控制得当，必然成功）
   ht[ r ] = new Entry<K, V>( k, v ); ++N; //插入新词条
   removed->clear( r );  //清除懒惰删除标记
   if ( (N + removed->size())*2 > M ) rehash(); //若装填因子高于50%，重散列
   return true;
}

#endif
