

/******************************************************************************************
 * Test of PQ_ComplHeap & PQ_LeftHeap
 ******************************************************************************************/
#include "PQ_test.h"
//#include <windows.h>

/******************************************************************************************
 * 针对基于列表、向量以及左式堆实现的优先级队列，做过程统一的测试
 ******************************************************************************************/
template <typename PQ, typename T> void testHeap( Rank n ) {
   Rank s = 2*n/3; T* A = new T[s]; //创建容量为2*n/3的数组，且
   for ( T i = 0; i < 2 * (T)n / 3; i++ ){T n_dot = (T) 3*n; A[i] = dice(  n_dot); }//所有词条随机
   /*DSA*/printf ( "%d random keys created:\n", s );
   /*DSA*/for ( Rank i = 0; i < s; i++ ) print( A[i] ); printf ( "\n" );
   PQ heap( A + n / 6, n / 3 ); //批量建堆（PQ_ComplHeap实现了Robert Floyd算法）
   delete [] A;
   /*DSA*/print( heap );
   while ( heap.size() < n ) { //随机测试
      if ( dice( 100 ) < 70 ) { //70%概率插入新词条
         T n_dot = (T) 3*n;
         T e = dice( n_dot ); /*DSA*/printf ( "Inserting" ); print( e ); printf( " ...\n" );
         heap.insert( e ); /*DSA*/printf ( "Insertion done\n" );
      } else { //30%概率摘除最大词条
         if ( !heap.empty() ) {
            /*DSA*/printf( "Deleting max ...\n" );
            T e = heap.delMax();/*DSA*/printf( "Deletion done with" ); print( e ); printf( "\n" );
         }
      }
      /*DSA*/print( heap );
   }
   while ( !heap.empty() ) { //清空
      T e = heap.delMax();/*DSA*/printf ( "Deletion done with" ); print ( e ); printf( "\n" );
      /*DSA*/print( heap );
   }
}

/******************************************************************************************
 * 优先级队列测试
 ******************************************************************************************/
int main( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
#if defined(DSA_PQ_LEFTHEAP)
   testHeap<PQ_LeftHeap<int>, int>( atoi ( argv[1] ) ); //词条类型可以在这里任意选择
#elif defined(DSA_PQ_COMPLHEAP)
   testHeap<PQ_ComplHeap<int>, int>( atoi ( argv[1] ) ); //词条类型可以在这里任意选择
#elif defined(DSA_PQ_LIST)
   testHeap<PQ_List<int>, int>( atoi ( argv[1] ) ); //词条类型可以在这里任意选择
#else
   printf( "PQ type not defined yet\n" );
#endif

   system( "pause" );
   return 0;
}
