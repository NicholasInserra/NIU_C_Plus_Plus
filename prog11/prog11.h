#ifndef H_PROG11
#define H_PROG11

#include <iomanip>
#include <string>
#include <vector>

#define N 50
#define LINE string ( N, '=' )

using namespace std;

void solveNQueens(const unsigned&);
bool solveNqueensUtil(vector<vector<bool>>&, const unsigned&);
bool isSafe(const vector<vector<bool> >&, const int&, const int&);
void initBoard(vector<vector<bool> >& );
void print(vector<vector<bool>>& );

#endif
