#include "prog11.h"
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int main ( )
{
   unsigned input = 0;

   while (cin >> input) //while we are getting single inputs for board size
   {
      solveNQueens(input);
   } 
}



void solveNQueens(const unsigned& n)
{
   //declare bool 2d vector for board
   vector<vector<bool> > board;

   //create board of correct size n by n
   board.resize(n);
   for(unsigned i=0; i < n; ++i)
   {
      board[i].resize(n);
   }
   //iniyislixr board to all false
   initBoard(board);

   //size message
   cout << "The board is size " << n << endl;

   if (solveNqueensUtil(board, 0) )
   cout << "Returned True\n ";
   else cout << "returned false\n";
   
   print(board); 
   

}


void initBoard(vector<vector<bool> >& board)
{
   srand (time(0));
   for(unsigned i=0; i < board.size(); ++i)
   {
      for(unsigned j=0; j < board.size(); ++j)
      { 
         board[i][j] = false;
      }
   }

}

bool solveNqueensUtil( vector<vector<bool> >& b, const unsigned& row)
{
   vector<int> checkedCols;
   int col = 0;
   bool usedCol = false;

   if (row == b.size() )
   {
      return true;
   }

   while(checkedCols.size() != b.size())
   {
      
         col = rand()% b.size();
         while (find(checkedCols.begin(), checkedCols.end(), col) != checkedCols.end()) 
         {
            col = rand() % b.size();  //already checked this column
         }
         checkedCols.push_back(col);
   
      


      if (isSafe(b, row, col ))
      {
         b[row][col] = true;
         if (row == b.size() -1)
         {
            return true;
         }
         else
         {
           solveNqueensUtil(b, row + 1);
           for (unsigned i = 0; i < b.size(); i++)
              b[row][i] = false; 
         }
      }
      
   }  
if (row == 0) return false;

}

bool isSafe(const vector<vector<bool>> & b, const int& row, const int& col)
{
   for(unsigned i = 0; i < b.size(); i++)
   {
      if (b[i][col] == true)
      return false;
   }   
   for(unsigned i = 0; i < b.size(); i++)
   {
      if (b[row][i] == true)
      return false;
   }   


   for(unsigned i = 0; i < b.size(); i++)
   {
      for(unsigned j = 0; j < b.size(); j++)
      {
         if( b[i][j] == true)  //found a queen 
         {
            if ( abs(row - (int)i) == abs(col - (int)j) )
            return false;
         }
      }
   }
   return true;
}

void print(vector<vector<bool>>& b)
{
    for(unsigned i = 0; i < b.size(); i++)
   {
      for(unsigned j = 0; j < b.size(); j++)
      {
         if( b[i][j] == true)  //found a queen 
         {
            cout << " Q ";
         }
         else cout << " - ";
      }
      cout << endl;
   }
}
























