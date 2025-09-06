#ifndef SHUFFLE_H
#define SHUFFLE_H 

#include "UniPrint/print_int_array.h"
#include "reverse/reverse.h"
#include "_share/util.h"
#include <iostream>

int shift ( int* A, int n, int s, int k );
int shift0 ( int* A, int n, int k );
int shift1 ( int* A, int n, int k );
int shift2 ( int* A, int n, int k );

#endif