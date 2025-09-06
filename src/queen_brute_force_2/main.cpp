
#include   "queen_brute_force_1/queen.h"
#include <cstring> // 显式包含cstring以使用strcmp函数

/******************************************************************************************
 * 全局变量
 ******************************************************************************************/
RunMode runMode; //运行模式
int nSolu = 0; //解的数量
int nCheck = 0; //尝试的总次数

/******************************************************************************************
 * 测试函数
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   void ( *pPlaceQueens[] ) ( void ) = {
      place2Queens, //2皇后算法
      place3Queens, //3皇后算法
      place4Queens, //4皇后算法
      place5Queens  //5皇后算法
   };
   if ( argc < 2 ) //检查参数是否给出运行模式
      { cout << "Usage: " << argv[0] << " <-step | -cont>" << endl; return -1; }
   if ( !strcmp ( "-step", argv[1] ) ) runMode = Step; //设定为单步演示模式
   else if ( !strcmp ( "-cont", argv[1] ) ) runMode = Continuous; //设定为连续演示模式
   else { cout << "Unrecognizable running mode" << endl; return -2; }
   for ( int i = 2; i <= 5; i++ ) { //对2~5皇后问题分别求解
      nSolu = 0; nCheck = 0; //初始化解计数器
      ( *pPlaceQueens[i-2] ) (); //启动算法
      printf ( "#Queen = %d\t#Solution = %d\t#Check = %d\a\a\n", i, nSolu, nCheck ); //输出结果
      getchar();
   }
   system ( "pause" );
   return 0;
}