#ifndef HANOI_H
#define HANOI_H

#include <cstdio>
#include <cstdlib>

#include "_share/util.h"
#include "stack/stack.h"

using Disk = int;

void displayHanoi();
void hanoi ( int, Stack<Disk>&, Stack<Disk>&, Stack<Disk>& );
void move ( Stack<Disk>&, Stack<Disk>& );

extern int nDisk; //盘子总数
extern Stack<int> Sx, Sy, Sz; //用三个栈模拟三根柱子，每个盘子的半径用整数表示

#endif
