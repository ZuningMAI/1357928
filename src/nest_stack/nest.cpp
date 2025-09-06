

/*DSA*/#include "nest.h"

bool paren ( const char exp[], Rank lo, Rank hi ) { //表达式括号匹配检查，可兼顾三种括号
   Stack<char> S; //使用栈记录已发现但尚未匹配的左括号
   for ( Rank i = lo; i <= hi; i++ ) /* 逐一检查当前字符 */ /*DSA*/{
      switch ( exp[i] ) { //左括号直接进栈；右括号若与栈顶失配，则表达式必不匹配
         case '(': case '[': case '{': S.push ( exp[i] ); break;
         case ')': if ( ( S.empty() ) || ( '(' != S.pop() ) ) return false; break;
         case ']': if ( ( S.empty() ) || ( '[' != S.pop() ) ) return false; break;
         case '}': if ( ( S.empty() ) || ( '{' != S.pop() ) ) return false; break;
         default: break; //非括号字符一律忽略
      /*DSA*/} displayProgress ( exp, i, S );
   }
   return S.empty(); //最终栈空，当且仅当匹配
}