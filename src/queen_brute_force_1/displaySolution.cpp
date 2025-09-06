

#include "queen.h"

void displaySolution ( int* solu, int n ) { //输出n*n的可行布局
   ( Step == runMode ) ? system ( "cls" ) : printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < n; j++ ) {
         printf ( ( j == solu[i] ) ? "█" : "[]" );
      }
      printf ( "\n" );
   }
   if ( Step == runMode ) {
      cout  << nSolu << " solution(s) found after " << nCheck << " check(s)\a";
      getchar();
   } else
      printf ( "\n" );
}