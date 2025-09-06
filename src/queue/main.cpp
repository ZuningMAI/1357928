

/******************************************************************************************
 * Test of queue
 ******************************************************************************************/
#include "queue_test.h"

int testID = 0; //测试编号

/******************************************************************************************
* 测试栈
******************************************************************************************/
template <typename T> void testQueue ( Rank n ) {
   Queue<T> Q;
   printf ( "\n  ==== Test %2d. Growing queue\n", testID++ );
   while ( Q.size() < n ) {
     if ( Q.empty() || ( 30 < dice ( 100 ) ) ) { //70%入队
         T e = dice ( (T)(2 * n) );
         printf ( "enqueueing " ); print ( e ); printf ( " ...\n" );
         Q.enqueue ( e );
      } else { //30%出队
         printf ( "dequeueing with ... " ); print ( Q.dequeue() ); printf ( "\n" );
      }
      print ( Q );
   }
   printf ( "\n  ==== Test %2d. Shrinking queue\n", testID++ );
   while ( !Q.empty() ) {
      if ( 70 < dice ( 100 ) ) { //30%入队
         T e = dice ( (T)(2 * n) );
         printf ( "enqueueing " ); print ( e ); printf ( " ...\n" );
         Q.enqueue ( e );
      } else { //70%出队
         printf ( "dequeueing with ... " ); print ( Q.dequeue() ); printf ( "\n" );
      }
      print ( Q );
   }
}

/******************************************************************************************
 * 测试队列
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   testQueue<double> ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择
   system ( "pause" );
   return 0;
}