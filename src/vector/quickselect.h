#ifndef QUICKSELECT_H
#define QUICKSELECT_H

// #include "vector/vector.h"
#include <cstdlib>
#include <ctime>
template <typename T> Rank quickSelect( T const * A, Rank n, Rank k );
template <typename T> Rank quickSelect( T const * A, Rank n, Rank k ) { 
   Vector<Rank> R(n); 
   for ( Rank i = 0; i < n; i++ ) R.insert(i); 
   for ( Rank lo = 0, hi = n; ; ) { 
      swap( R[lo], R[lo + rand()%(hi-lo)] ); T pivot = A[R[lo]]; Rank mi = lo; 
      for ( Rank i = lo+1; i < hi; i++ ) 
         if ( A[R[i]] < pivot )
            swap( R[++mi], R[i] );
      swap( R[lo], R[mi] ); 
      if ( mi < k ) lo = mi + 1; 
      else if ( k < mi ) hi = mi; 
      else return R[mi]; 
   }
}

#endif