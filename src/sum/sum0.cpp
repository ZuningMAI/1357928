// # include "sum.h"

int sumI(int A[],int n)
//数组求和算法（迭代版）
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += A[i];
	return sum;
} //O(1) + O(n)*O(1) + O(1) = O(n+2) = O(n)