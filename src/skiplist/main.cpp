
/******************************************************************************************
 * Test of Skiplist
 ******************************************************************************************/

#include "skipList_test.h"

/******************************************************************************************
 * 测试跳转表
 ******************************************************************************************/
template <typename K, typename V> //key、value
void testSkiplist ( Rank n ) {
   Skiplist<K, V> L;
   while ( L.size() < n )
      switch ( dice ( 3 ) ) {
         case 0: { //查找，成功率 <= 33.3%
            K key = dice ( ( K ) n * 3 ); //[0, 3n)范围内的key
            printf ( "Searching for " ); print ( key ); printf ( " ... " );
            V* pValue = L.get ( key );
            if (pValue) {
                printf("Found with ");
                print(*pValue);
            } else {
                printf("Not found");
            }
            printf("\n");
            break;
         }
         case 1: { //删除，成功率 <= 33.3%
            K key = dice ( ( K ) n * 3 ); //[0, 3n)范围内的key
            printf ( "Removing " ); print ( key ); printf ( " ... " );
            if ( L.remove ( key ) ) { printf ( "Done\n" ); print(L); }
            else printf ( "Entry not exists\n\n" );
            break;
         }
         default: {//插入，成功率 == 100%
            K k = dice ( ( K ) n * 3 ); V v = ( V ) 'A' + dice ( 26 ); //在[0, 2n)*['A'~'Z']范围内的词条
            printf ( "Inserting <" ); print ( k ); printf ( "," ); print ( v ); printf ( "> ... " );
            L.put ( k, v ); printf ( "Done\n" );
            print ( L );
            break;
         }
      }
   while ( L.size() > 0 ) {
      K key = dice ( ( K ) n * 3 ); //[0, 3n)范围内的key
      printf ( "Removing " ); print ( key ); printf ( " ... " );
      if (L.remove(key)) printf("Done\n"); else printf("Entry not exists\n");
      print ( L ); printf("\n");
   }
}

/******************************************************************************************
 * 主程序
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //随机种子
   //srand( 31415926 ); //固定种子（假种子，调试用）
   testSkiplist<int, char> ( atoi ( argv[1] ) ); //元素类型可以在这里任意选择
   // system("pause");
   return 0;
}