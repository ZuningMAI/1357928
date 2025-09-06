#ifndef FIB_H
#define FIB_H

/**************************************************************
 * Fibonacci数列类
 * f = fib(k-1),g=fib(k),k=1:n
 **********************************************************/
#include<ctime>
#include<ostream>
using namespace std;
using Rank = unsigned int;
class Fib
{
private:
    Rank f,g;
public:
    Fib(Rank n){
        f=1;g=0;while(g<n)next();
    }
    Rank get() {return g;}
    Rank next() {g += f; f = g - f; return g;}
    Rank prev() {f = g - f;g -= f; return g;}
};

/**************************************************************
 * Fibonacci函数版本
 * f = fib(k-1),g=fib(k),k=1:n
 **********************************************************/
#include "stdint.h"
uint64_t fibI(int n);//迭代版本
uint64_t fib(int n);//二分版本
uint64_t fib(int n,uint64_t &f);//线性递归版本

#endif