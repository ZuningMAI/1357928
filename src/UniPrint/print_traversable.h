#ifndef PRINT_TRAVERSABLE_H
#define PRINT_TRAVERSABLE_H


#include <typeinfo>
// #include <type_traits>


/******************************************************************************************
 * 向量、列表等支持traverse()遍历操作的线性结构
 ******************************************************************************************/
template <typename T> //元素类型
void UniPrint::p ( T& s ) { //引用
   printf ( "%s[%d]*%d:\n", typeid ( s ).name(), (int) &s, (int)s.size() ); //基本信息
   s.traverse ( print ); //通过print()遍历输出所有元素
   printf ( "\n" );
}

#endif

/*
#ifndef PRINT_TRAVERSABLE_H
#define PRINT_TRAVERSABLE_H


#include <typeinfo>
#include <type_traits>

// 使用SFINAE检查类型是否有size()和traverse()方法
template<typename T>
class has_traverse_and_size {
    template<typename U>
    static auto test(int) -> decltype(
        std::declval<U>().size(),
        std::declval<U>().traverse(nullptr),
        std::true_type{}
    );
    
    template<typename>
    static std::false_type test(...);
    
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};
template <typename T> //元素类型
void UniPrint::p ( T& s ) { //引用
   // 只有当类型T具有size()和traverse()方法时才执行以下代码
   if constexpr (has_traverse_and_size<T>::value) {
       printf ( "%s[%d]*%d:\n", typeid ( s ).name(), (int) &s, (int)s.size() ); //基本信息
       s.traverse ( &print ); //通过print()遍历输出所有元素
       printf ( "\n" );
   } else {
       // 对于不支持traverse和size的类型，使用默认打印方式
       print(s);
       printf("\n");
   }
}
#endif
*/