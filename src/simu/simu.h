#ifndef SIMU_H
#define SIMU_H
#pragma warning(disable : 4996)

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>

#include "queue/queue.h" //引入队列
#include "Customer.h" //顾客类

int bestWindow( Queue<Customer> *, Rank );
void printCustomer( Customer );
void displayProgress( Queue<Customer> *, Rank, Rank );
void simulate( Rank, Rank );

extern int delay; //控制进度显示的延迟
#endif
