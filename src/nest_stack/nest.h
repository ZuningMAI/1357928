#ifndef NEST_H
#define NEST_H

#include<iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "UniPrint/print.h"

#include "stack/stack.h"
// #include "stack_list/stack_list.h"

bool paren ( const char exp[], Rank lo, Rank hi );
void displaySubstring ( const char exp[], Rank lo, Rank hi );
void displayProgress ( const char exp[], Rank i, Stack<char> S );

#endif
