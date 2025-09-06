#ifndef PQ_LEFTHEAP_MERGE_RECURSIVE_H
#define PQ_LEFTHEAP_MERGE_RECURSIVE_H

template <typename T> //合并以a和b为根节点的两个左式堆（递归版）
BinNodePosi<T> merge( BinNodePosi<T> a, BinNodePosi<T> b ) {
   if ( !a ) return b; //退化情况
   if ( !b ) return a; //退化情况
   if ( *a < *b ) swap( a, b ); //确保a>=b
   ( a->rc = merge( a->rc, b ) )->parent = a; //将a的右子堆，与b合并
   if ( !a->lc || ( a->lc->npl < a->rc->npl ) ) //若有必要
      swap( a->lc, a->rc ); //交换a的左、右子堆，以确保右子堆的npl不大
   a->npl = a->rc ? a->rc->npl + 1 : 1; //更新a的npl
   return a; //返回合并后的堆顶
} //本算法只实现结构上的合并，堆的规模须由上层调用者负责更新

#endif
