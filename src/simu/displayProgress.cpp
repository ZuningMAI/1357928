

#include "simu.h"

/******************************************************************************************
 * 显示当前各（窗口）队列情况
 ******************************************************************************************/
void displayProgress ( Queue<Customer> window[], Rank wins, Rank now ) {
   system( "cls" ); //清屏
   printf( "============ Time: %4d ============\n", now );
   for ( Rank i = 0; i < wins; i++ ) { //对每个窗口，分别
      printf( "Window #%c:  ", 'A' + i ); //输出窗口编号
      window[i].traverse ( printCustomer ); printf ( "\n" ); //列出队列中的所有顾客
   }
}