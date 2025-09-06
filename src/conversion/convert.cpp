

/*DSA*/#include "convert.h"

void convert ( Stack<char>& S,unsigned long long n, int base ) { //正整数n的2<=base<=16进制打印（迭代版）
   char digit[] = "0123456789ABCDEF"; //数位符号，如有必要可相应扩充
   while ( n > 0 ) { //由低到高，逐一计算出新进制下的各数位
      /*DSA*/printf ( "\n\t%20llu = %20llu * %d + %llu\n", n , n/base, base, n%base );
      S.push ( digit[ n % base ] ); //余数（当前位）入栈
      n /= base; //n更新为其对base的除商
      /*DSA*/print ( S );
   }
} //新进制下由高到低的各数位，自顶而下保存于栈S中

// 递归版本
/*
void convert ( Stack<char>& S, unsigned long long n, int base ) { //整数n的1<base<=16进制打印（递归版）
   static char digit[] = "0123456789ABCDEF"; //数位符号，如有必要可相应扩充
   if ( 0 < n ) { //在尚有余数之前，反复地
      S.push ( digit[n % base] ); //逆向记录当前最低位，再
      convert ( S, n / base, base ); //通过递归得到所有更高位
   }
} //新进制下由高到低的各数位，自顶而下保存于栈S中
*/