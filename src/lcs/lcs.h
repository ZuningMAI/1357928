
#ifndef LCS_H
#define LCS_H

#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

void backtrackAll(char const* A, char const* B, const vector<vector<int>>& dp, 
                  int i, int j, string& current, std::set<string>& results);
bool backtrackOne(char const* A, char const* B, const vector<vector<int> >& dp, 
                  int i, int j, string& result);
unsigned int lcsIteration(char const * A, int n, char const * B, int m);
unsigned int lcsM( char const * A, int n, char const * B, int m, unsigned int * const lcs, int const M );
unsigned int lcsMemoization(char const * A, int n, char const * B, int m);
unsigned int lcsRecursion(char const * A, int n, char const * B, int m);
unsigned int lcsDPAll(char const* A, int n, char const* B, int m, vector<vector<int> >& dp);


#endif