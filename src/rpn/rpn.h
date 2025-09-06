#ifndef RPN_H
#define RPN_H
#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "stack/stack.h" //使用栈
#include "priority.h"
#include <cstdint>

uint64_t facI ( int );
double calcu ( double a, char op, double b );
double calcu ( char op, double b );
void displayProgress ( char*, char*, Stack<double>&, Stack<char>&, char* );
void readNumber ( char*&, Stack<double>& );
Operator optr2rank ( char );
char priority ( char, char );
void append ( char*, double ); //重载
void append ( char*, char ); //重载
double evaluate ( char* expr, char* rpn );

#endif
