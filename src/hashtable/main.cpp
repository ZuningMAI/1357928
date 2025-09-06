
/******************************************************************************************
 * Test of Hashtable
 ******************************************************************************************/
#include "Hashtable_test.h"
#include "HashTable_hashcode.h"

/******************************************************************************************
 * 测试散列表
 ******************************************************************************************/
// /*
template <typename K, typename V> //key、value
void testHashtable ( Rank n ) {
   Hashtable<K, V> ht ( n ); print ( ht );
   while ( ht.size() < 4 * n ) {
      printf ( "\n" );
      switch ( dice ( 3 ) ) {
         case 0: { //查找，成功率 <= 33.3%
            K key = dice ( ( K ) n * 12 ); //[0, 3n)范围内的key
            printf( "Searching " ); print ( key ); printf( "(%04d) :\n", hashCode( key ) );
            V* pValue = ht.get ( key );
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
            K key = dice ( ( K ) n * 12 ); //[0, 3n)范围内的key
            printf( "Removing " ); print ( key ); printf( "(%04d) :\n", hashCode( key ) );
            if (ht.remove(key)) {
                printf("Done\n");
                print(ht);
            } else {
                printf("Entry not exists\n");
            }
            break;
         }
         default: {//插入，成功率 == 100%
            K key = dice ( ( K ) n * 12 ); V v = ( V ) 'A' + dice ( 26 ); //在[0, 2n)*['A'~'Z']范围内的词条
            printf( "Inserting <" ); print( key ); printf( "(%04d)", hashCode( key ) ); printf( " :" ); print ( v ); printf( " >\n" );
            if (ht.put( key, v )) {
                printf("Done\n");
                print(ht);
            } else {
                printf("Dup key\n");
            }
            break;
         }
      } //switch
   } //while
   while ( ht.size() > 0 ) {
      printf( "\n" );
      K key = dice( ( K ) n * 12 ); //[0, 3n)范围内的key
      printf( "Removing " ); print( key ); printf( " :\n" );
      if (ht.remove(key)) {
         printf("Done\n");
         print(ht);
      } else {
         printf("Entry not exists\n");
      }
   }
}
// */

// 测试辅助函数
void test_hash(const char* type, const char* value, Rank hashValue, void* testValue) {
    if (strcmp(type, "char") == 0) {
        char val = *(char*)testValue;
        printf("| %-8s | '%c' (ASCII %-3d) | 0x%08X | %u |\n", 
               type, val, (int)val, hashValue, hashValue);
    } 
    else if (strcmp(type, "int") == 0) {
        int val = *(int*)testValue;
        printf("| %-8s | %-15d | 0x%08X | %u |\n", 
               type, val, hashValue, hashValue);
    } 
    else if (strcmp(type, "long long") == 0) {
        long long val = *(long long*)testValue;
        printf("| %-8s | %-15lld | 0x%08X | %u |\n", 
               type, val, hashValue, hashValue);
    } 
    else if (strcmp(type, "string") == 0) {
        char* val = (char*)testValue;
        printf("| %-8s | \"%-15s\" | 0x%08X | %u |\n", 
               type, val, hashValue, hashValue);
    }
}

// 主测试函数
int test_for_HashCode() {
    // 测试数据
    char testChar = 'A';
    int testInt = 123456789;
    long long testLL = 0x123456789ABCDEF0LL;
    char testStr1[] = "Hello";
    char testStr2[] = "World";
    char testStr3[] = "HashCode";
    char testStr4[] = "你好世界";  // 中文测试

    // 打印表头
    printf("+----------+-----------------+------------+------------+\n");
    printf("| 类型      | 测试值          | 哈希值     | 十进制     |\n");
    printf("+----------+-----------------+------------+------------+\n");
    
    // 执行测试
    test_hash("char", "char", hashCode(testChar), &testChar);
    test_hash("int", "int", hashCode(testInt), &testInt);
    test_hash("long long", "long long", hashCode(testLL), &testLL);
    test_hash("string", "string", hashCode(testStr1), testStr1);
    test_hash("string", "string", hashCode(testStr2), testStr2);
    test_hash("string", "string", hashCode(testStr3), testStr3);
    test_hash("string", "string", hashCode(testStr4), testStr4);
    

    
    // 边界值测试
    printf("\n边界值测试:\n");
    char minChar = 0;
    char maxChar = 127;
    int minInt = -2147483648;
    int maxInt = 2147483647;
    long long minLL = 0x8000000000000000LL;
    long long maxLL = 0x7FFFFFFFFFFFFFFFLL;
    char emptyStr[] = "";
   //  
    test_hash("char", "char", hashCode(minChar), &minChar);
    test_hash("char", "char", hashCode(maxChar), &maxChar);
    test_hash("int", "int", hashCode(minInt), &minInt);
    test_hash("int", "int", hashCode(maxInt), &maxInt);
    test_hash("long long", "long long", hashCode(minLL), &minLL);
    test_hash("long long", "long long", hashCode(maxLL), &maxLL);
    test_hash("string", "string", hashCode(emptyStr), emptyStr);

}

/*
+----------+-----------------+------------+------------+
| 类型      | 测试值          | 哈希值     | 十进制     |
+----------+-----------------+------------+------------+
| char     | 'A' (ASCII 65 ) | 0x00000041 | 65 |
| int      | 123456789       | 0x075BCD15 | 123456789 |
| long long | 1311768467463790320 | 0xACF13568 | 2901489000 |
| string   | "Hello          " | 0x04B43DEF | 78921199 |
| string   | "World          " | 0x05A955E4 | 94983652 |
| string   | "HashCode       " | 0x2CA34B3E | 748899134 |
| string   | "你好世界   " | 0xF4B27042 | 4105334850 |

边界值测试:
| char     | '' (ASCII 0  ) | 0x00000000 | 0 |
| char     | '' (ASCII 127) | 0x0000007F | 127 |
| int      | -2147483648     | 0x80000000 | 2147483648 |
| int      | 2147483647      | 0x7FFFFFFF | 2147483647 |
| long long | -9223372036854775808 | 0x80000000 | 2147483648 |
| long long | 9223372036854775807 | 0x7FFFFFFE | 2147483646 |
| string   | "               " | 0x00000000 | 0 |
*/
/******************************************************************************************
 * 主程序
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand((unsigned int)time(NULL)); //随机种子
   // srand( 31415926 ); //固定种子（假种子，调试用）
   testHashtable<int, char>( atoi( argv[1] ) ); //元素类型可以在这里任意选择

//    test_for_HashCode();
   system("pause");
   return 0;
}
