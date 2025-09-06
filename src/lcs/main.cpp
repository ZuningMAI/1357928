
#include "lcs.h"
int main ( int argc, char* argv[] ) {
   srand((unsigned int)time(NULL)); //        
   //srand( 31415926 ); 
   int errors = 0, tests = 100, str_len = 9;
   for ( int k = 0; k < tests; k++ ) {
      printf("\n%d\n", k);
      char* A; int n; char* B; int m;
      if (2 < argc) {
         m = strlen(argv[2]); B = argv[2];
      } else {
         m = str_len + rand() % 9; B = new char[m + 1];
         for (int j = 0; j < m; j++)
            B[j] = 'A' + (rand() % 26);
         B[m] = 0;
      }
      if (1 < argc) {
         n = strlen(argv[1]); A = argv[1];
      } else {
         n = str_len + rand() % 9; A = new char[n + 1];
         for (int i = 0; i < n; i++)
            A[i] = 'A' + (rand() % 26);
         A[n] = 0;
      }
      unsigned int lcsI = lcsIteration( A, n, B, m );
      unsigned int lcsM = lcsMemoization( A, n, B, m );
      unsigned int lcsR = lcsRecursion( A, n, B, m );
      vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
      cout << "A = " << A << endl;
      cout<< "B = " << B << endl;
      unsigned int lcsAll = lcsDPAll( A, n, B, m, dp );
      errors += lcsI != lcsM || lcsM != lcsR || lcsR != lcsAll;
      if ( lcsI == lcsM )
         printf("%2u == %2u", lcsI, lcsM);
      else
         printf("%2u <> %2u", lcsI, lcsM);
      if ( lcsM == lcsR )
         printf(" == %2u", lcsR);
      else
         printf(" <> %2u", lcsR);
      if ( lcsR == lcsAll )
         printf(" == %2u", lcsAll);
      else
         printf(" <> %2u", lcsAll);
      printf(" : %18s [%2d] ~ %18s [%2d]\n", A, n, B, m);
      //         LCS  
      vector<string> lcsAllResults;
      set<string> uniqueResults; // 使用set避免重复
      string current = "";
      bool flag = false;
      if (str_len < 12)
        backtrackAll(A, B, dp, n, m, current, uniqueResults);
      else
        flag = backtrackOne(A, B, dp, n, m, current);
        
      // 将set中的结果复制到vector中
      for (set<string>::const_iterator it = uniqueResults.begin(); it != uniqueResults.end(); ++it) {
            lcsAllResults.push_back(*it);
        }
      if (!lcsAllResults.empty()) {
          printf("All LCS solutions (%zu):\n", lcsAllResults.size());
          for (const string& solution : lcsAllResults) {
              printf("  %s\n", solution.c_str());
          }   
      }
      else {
         if(flag){
            cout << "one solution for this :" << current << endl;}
         else{printf("no solution for this\n");}
    }
      
      if ( argc < 3 ) delete[] B;
      if ( argc < 2 ) delete[] A;
   }
   printf("\n%d / %d\n", tests - errors, tests);
   system("pause");
   return 0;
}