
/*DSA*/#include "_share/util.h"
/*DSA*/#include "UniPrint/print_int_array.h"

void reverse ( int * A, int n ) { 
   if ( n < 2 ) return;
   swap ( A[0], A[n-1] ); 
   reverse ( A + 1, n - 2 ); 
} 