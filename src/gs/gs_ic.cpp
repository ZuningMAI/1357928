

extern int s_lo, s_hi;

int gs_IC( int A[], int n ) { //递增策略：O(n^2)
   int gs = A[0]; s_lo = 0; s_hi = 1;
   for ( int lo = 0; lo < n; lo++ ) { //枚举所有起始于lo
      for ( int s = 0, hi = lo; hi < n; ) { //终止于hi的区间
         s += A[hi++]; //递增地得到其总和：O(1)
         if ( gs < s )
            { gs = s; s_lo = lo; s_hi = hi; } //择优、更新
      }
   }
   return gs;
}
