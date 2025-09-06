
#include <cstdio>
#include <cstdlib>
/*DSA*/#include "fac.h"

int main ( int argc, char* argv[] ) { 
   for ( int i = 0; i < 25; i++ )
      printf ( "\t%d\t%22lld\t%22lld\n", i, facI ( i ), facR ( i ) );
   
    system("pause");
    return 0;
}