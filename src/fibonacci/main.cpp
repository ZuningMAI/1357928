#include "Fib.h"

int main ( int argc, char* argv[] ) { //测试FIB
// 检查参数
   if ( 2 > argc ) { fprintf ( stderr, "Usage: %s <Rank>\n", argv[0] ); return 1; }
   int n = atoi ( argv[1] );
// 依次计算Fibonacci数列各项
   printf ( "\n------------- class Fib -------------\n" );
   Fib f ( 0 );
   for ( int i = 0; i < n; i++, f.next() )
      printf ( "fib(%2d) = %22I64d\n", i, f.get() );
   for ( int i = 0; i <= n; i++, f.prev() )
      printf ( "fib(%2d) = %22I64d\n", n - i, f.get() );
   printf ( "\n------------- Iteration -------------\n" );
   for ( int i = 0; i < n; i++ )
      printf ( "fib(%2d) = %22I64d\n", i, fibI ( i ) );
   printf ( "\n------------- Linear Recursion -------------\n" );
   for ( int i = 0; i < n; i++ ) {
      uint64_t f;
      printf ( "fib(%2d) = %22I64d\n", i, fib ( i, f ) );
   }
   /*printf ( "\n------------- Binary Recursion -------------\n" );
   for ( int i = 0; i < n; i++ )
      printf ( "fib(%2d) = %22I64d\n", i, fib ( i ) );*/
    system("pause");
    return 0;
}
