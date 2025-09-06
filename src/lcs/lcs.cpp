#include "lcs.h"

unsigned int lcsRecursion( char const * A, int n, char const * B, int m ) {
   if ( n < 1 || m < 1 ) //trivial cases
      return 0;
   if ( A[n-1] == B[m-1] ) //decrease & conquer
      return 1 + lcsRecursion( A, n-1, B, m-1 );
   else //divide & conquer
      return max( lcsRecursion( A, n-1, B, m ), lcsRecursion( A, n, B, m-1 ) );
}

unsigned int lcsIteration( char const * A, int n, char const * B, int m ) {
   if (n < m) { swap(A, B); swap(n, m); } //make sure m <= n
   unsigned int* lcs1 = new unsigned int[m+1]; //the current two rows are
   unsigned int* lcs2 = new unsigned int[m+1]; //buffered alternatively
   memset( lcs1, 0x00, sizeof(unsigned int)*(m+1) ); lcs2[0] = 0; //sentinels
   for ( int i = 0; i < n; swap(lcs1, lcs2), i++ )
      for ( int j = 0; j < m; j++ )
         lcs2[j + 1] = (A[i] == B[j]) ? 1 + lcs1[j] : max(lcs2[j], lcs1[j+1]);
   unsigned int solu = lcs1[m];
   delete[] lcs1;
   delete[] lcs2;
   return solu;
}
unsigned int lcsM( char const * A, int n, char const * B, int m, unsigned int * const lcs, int const M ) {
   if ( n < 1 || m < 1 )
      return 0;
   if ( UINT_MAX != lcs[(n-1)*M + m-1] )
      return lcs[(n-1)*M + m-1]; //recursion stops here
   return lcs[(n-1)*M + m-1] = ( A[n-1] == B[m-1] ) ?
            1 + lcsM( A, n-1, B, m-1, lcs, M ) :
            max( lcsM( A, n-1, B, m, lcs, M ), lcsM( A, n, B, m-1, lcs, M ) );
}

unsigned int lcsMemoization( char const* A, int n, char const* B, int m ) {
   unsigned int* lcs = new unsigned int[n*m]; //a lookup-table of all sub-solutions
   memset(lcs, 0xFF, sizeof( unsigned int)*n*m ); //initialized with n*m UINT_MAX's
   unsigned int solu = lcsM( A, n, B, m, lcs, m );
   delete[] lcs;
   return solu;
}

unsigned int lcsDPAll(char const* A, int n, char const* B, int m, vector<vector<int> >& dp) {
    // 确保dp表大小正确
    if (dp.size() != n + 1 || dp[0].size() != m + 1) {
        dp.assign(n + 1, vector<int>(m + 1, 0));
    }

    // 填充DP表
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    /* 按照矩阵的方式打印DP表
    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
    */
    
    return dp[n][m];
}


void backtrackAll(char const* A, char const* B, const vector<vector<int> >& dp, 
                  int i, int j, string& current, set<string>& results) {
    // 基本情况
    if (i == 0 || j == 0) {
        string reversed = current;
        reverse(reversed.begin(), reversed.end());
        results.insert(reversed);
        return;
    }
    
    // 如果字符匹配
    if (A[i-1] == B[j-1]) {
        current.push_back(A[i-1]);
        backtrackAll(A, B, dp, i-1, j-1, current, results);
        current.pop_back();
    } 
    // 如果不匹配，向两个方向继续搜索
    else {
        // 向上
        if (dp[i-1][j] == dp[i][j]) {
            backtrackAll(A, B, dp, i-1, j, current, results);
        }
        // 向左
        if (dp[i][j-1] == dp[i][j]) {
            backtrackAll(A, B, dp, i, j-1, current, results);
        }
    }
}


// 回溯函数，只找到一个LCS解即可
bool backtrackOne(char const* A, char const* B, const vector<vector<int> >& dp, 
                  int i, int j, string& result) {
    // 基本情况
    if (i == 0 || j == 0) {
        reverse(result.begin(), result.end());
        return true;
    }
    
    // 如果字符匹配
    if (A[i-1] == B[j-1]) {
        result.push_back(A[i-1]);
        if (backtrackOne(A, B, dp, i-1, j-1, result)) {
            return true;
        }
        result.pop_back();
    } 
    // 如果不匹配，选择一个方向继续搜索
    else {
        // 优先选择dp值相等的方向，先检查向上，再检查向左
        if (dp[i-1][j] == dp[i][j]) {
            if (backtrackOne(A, B, dp, i-1, j, result)) {
                return true;
            }
        }
        if (dp[i][j-1] == dp[i][j]) {
            if (backtrackOne(A, B, dp, i, j-1, result)) {
                return true;
            }
        }
    }
    
    return false;
}