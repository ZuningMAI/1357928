
#include "shift.h"

int shift ( int* A, int n, int s, int k ) { 
    //从A[s]出发，以k为间隔循环左移，O(n / GCD(n, k))
   int bak = A[s]; //备份起始元素
   int i = s, j = ( s + k ) % n; //从该元素出发
   int mov = 0; //移动次数
   while ( s != j ) { //以k为间隔
      A[i] = A[j]; //依次左移k位
      i = j; j = ( j + k ) % n; mov++;
   }
   A[i] = bak; //将起始元素转入对应位置
   return mov + 1;
}

int shift0 ( int* A, int n, int k ) { //蛮力地将数组循环左移k位，O(nk)
   if ( k < 1 ) return 0; int mov = 0;
   while ( k-- ) { //反复以1为间隔循环左移，共迭代k次
      mov += shift ( A, n, 0, 1 );                                       /*DSA*/printf ( "== move *%3d\n", mov ); print ( A, n );
   }
   return mov;
}

int shift1 ( int* A, int n, int k ) { //通过GCD(n, k)轮迭代，将数组循环左移k位，O(n)
   if ( k < 1 ) return 0;
   int mov = 0, s = 0;
   while ( mov < n ) { //O(GCD(n, k)) = O(n*k/LCM(n, k))
      mov += shift ( A, n, s++, k );                                     /*DSA*/printf ( "== move *%3d\n", mov ); print ( A, n );
   }
   return mov;
}

int shift2 ( int* A, int n, int k ) { //借助倒置算法，将数组循环左移k位，O(3n)
   k %= n; //确保k <= n
   reverse ( A, k ); //将区间A[0, k)倒置：O(3k/2)次操作
   /*DSA*/print ( A, n, 0, k );
   reverse ( A + k, n - k ); //将区间A[k, n)倒置：O(3(n - k)/2)次操作
   /*DSA*/print ( A, n, k, n );
   reverse ( A, n ); //倒置整个数组A[0, n)：O(3n/2)次操作
   /*DSA*/print ( A, n );
   return 3 * n; //返回累计操作次数，以便与其它算法比较：3/2 * (k + (n - k) + n) = 3n
}
