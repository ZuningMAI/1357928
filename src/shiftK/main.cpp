#include "shift.h"

int main ( int argc, char* argv[] ) {
   if ( argc < 3 ) { printf ( "Usage: %s <array_length> <shift>\n", argv[0] ); return 1;}
   int   n = atoi ( argv[1] );   if ( n < 0 ) return 1;
   int   k = atoi ( argv[2] );   if ( k < 0 || k > n ) return 1;
   printf ( "Shift A[%d] with k = %d ...\n", n, k );
   int* A = ( int* ) malloc ( sizeof ( int ) * n );
   printf ( "\n== shift algorithm #0 ========\n" );
   for ( int i = 0; i < n; i++ ) A[i] = i; print ( A, n );
   printf ( "== move *%3d\n", shift0 ( A, n, k ) ); print ( A, n ); printf ( "\n" );
   printf ( "\n== shift algorithm #1 ========\n" );
   for ( int i = 0; i < n; i++ ) A[i] = i; print ( A, n );
   printf ( "== move *%3d\n", shift1 ( A, n, k ) ); print ( A, n ); printf ( "\n" );
   printf ( "\n== shift algorithm #2 ========\n" );
   for ( int i = 0; i < n; i++ ) A[i] = i; print ( A, n );
   printf ( "== move *%3d\n", shift2 ( A, n, k ) ); print ( A, n ); printf ( "\n" );
   free ( A );
   system ( "pause" );
   return 0;
}