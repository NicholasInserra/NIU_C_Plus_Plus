
/***********************************************************
CSCI 689 - Assignment 11

Progammer: Nick INserra
Z-ID: z1749082
Section: 2
Date Due: 5/2/16

Purpose: This program determins if you can arragnge the chess
         piece of a queen so that there is one on each row
         of a board of a given size.

         Size is always square

         Prints board only if it finds solution

         Utilizes backtracking
************************************************************/ 

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
  for (unsigned i = 1; i < 9; i++) //test 1 through 8
   {
      solveNQueens(i);
   } 
}

/***************************************************************
solveNQueens
Use: Creates chess board of given size and sets all bool values
     to false showing there is no queen
 
Parameters: 1. unsigned N for dimesnion board will be N X N
Returns: nothing
***************************************************************/

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
   cout << "Board Size = " << n << endl;

   //if it can be solved print the board
   if (solveNqueensUtil(board, 0) )
   {
       print(board);
       cout << endl;
   } 
   else
   {
      cout <<"Solution does not exist." << endl << endl;
   }
   

}

/***************************************************************
initBoard
Use: Sets all board to false for no queens, intializes random
Parameters: 1. 2d bool vector for the board
Returns: nothing
**************************************************************/
void initBoard(vector<vector<bool> >& board)
{
   srand (time(0));
   for(unsigned i=0; i < board.size(); ++i)
   {
      for(unsigned j=0; j < board.size(); ++j)
      { 
         board[i][j] = false;   //no queens empty board
      }
   }

}


/***************************************************************
solveNqueensUtil
Use: Determines if queens can be placed on every row on a board
     of a given nXn size.  It utalizes backtracking so it should always
     find the correct answer.
Parameters: 1. 2d bool vector the board
            2. row attempting to solve 
Returns: bool true if can be solved
**************************************************************/

bool solveNqueensUtil( vector<vector<bool> >& b, const unsigned& row)
{
   //keep track of column guesses
   vector<int> checkedCols;
   int col = 0;
if (row >= b.size()) return true;  //solved the whole board!

   //keep going untill all columns have been checked
   while(checkedCols.size() != b.size())
   {
         col = rand()% b.size();   //select random column
         while (find(checkedCols.begin(), checkedCols.end(), col) != checkedCols.end())  //check if already tried column 
         {
            col = rand() % b.size();  //pick a new column
         }
         checkedCols.push_back(col);  //store so we don't reuse
   
      


      if (isSafe(b, row, col ))   //is given space safe for queen
      {
         b[row][col] = true; //place queen
         if (solveNqueensUtil(b, row + 1) )  //check the next row
         {
            return true;            //gets here once solveQueens reaches top return true
         }
         
         for (unsigned i = 0; i < b.size(); i++)
              b[row][i] = false; //remove queens
         
      }
   }  
return false;   //if checked all

}

/***************************************************************
isSafe
Use: Determines if queen isSafe from other queens in a given position 
Parameters: 1. 2d bool vector of the board,
            2. row and col to place the queen
Returns:  bool true if safe placement for queen
***************************************************************/ 

bool isSafe(const vector<vector<bool>> & b, const int& row, const int& col)
{
   for(unsigned i = 0; i < b.size(); i++)
   {
      if (b[i][col] == true)       //check if its in same column
      return false;
   }   
   for(unsigned i = 0; i < b.size(); i++)
   {
      if (b[row][i] == true)       //check if row is safe
      return false;
   }   


   for(unsigned i = 0; i < b.size(); i++)
   {
      for(unsigned j = 0; j < b.size(); j++)
      {
         if( b[i][j] == true)  //found a queen 
         {
            if ( abs(row - (int)i) == abs(col - (int)j) )  //check for diagnols
            return false;
         }
      }
   }
   return true;
}

/***************************************************************
print
Use: Prints solutions Q is for Queen
Parameters: 1. 2d bool vector of board 
Returns: 
***************************************************************/ 
void print(vector<vector<bool>>& b)
{
   unsigned row = 0;

cout << endl;
      cout << " ";
   for(unsigned i = 0; i< b.size(); i++)  //print top line
       cout << "------";
       cout << endl;

while( row != b.size())  //for every row
{

       cout << "|";
   for(unsigned i = 0; i < b.size(); i++)
       cout << "     |";
       cout << endl;

       cout << "|";
   for(unsigned i = 0; i < b.size(); i++)
    {
        if (b[row][i] == true)
        {
           cout << "  Q  |";   
        }
        else
        {
           cout << "     |";
        }
    }
    cout << endl;

       cout << "|";
    for(unsigned i = 0; i < b.size(); i++)
       cout << "     |";
       cout << endl;

       cout << " ";
    for(unsigned i = 0; i< b.size(); i++)  //print bottom line
       cout << "------";
       cout << endl;

  row++;
 }

}











