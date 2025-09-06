#ifndef QUEEN_H
#define QUEEN_H

#include<iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "stack/stack.h"

#define QUEEN_MAX 20

typedef enum {Continuous, Step} RunMode;

extern RunMode runMode; //运行模式
extern int nSolu; //解的总数
extern int nCheck; //尝试的总次数

void place5Queens_BruteForce();
void displaySolution ( int* solu, int n );
bool collide ( int* solu, int k );

void placeQueens ( int n, int k );

void place2Queens();
void place3Queens();
void place4Queens();
void place5Queens();
#endif
