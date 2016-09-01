/************************************************************o
CSCI 689 - Assignment 5 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 2/26

Purpose: Minesweeper

Constants: SEED = 1 for random intialization
************************************************************/ 
#include "prog5.h"

#include <stdlib.h>
#include <vector>
#include <iostream>	//input output stream

using namespace std;

template< class T>
void myVectorResize( vector<vector<T> > & mineField, int mineFieldSize)
{
  mineField.resize(mineFieldSize);
  for(int i =0; i < mineFieldSize; i++)
    mineField[i].resize(mineFieldSize);
}



int main()
{
   int mineFieldSize;
   double mineProb;

   //intialize random seed
   srand(SEED);


   vector<vector<bool> > mineField;
   vector<vector<unsigned> > countField;

   while(cin >> mineFieldSize)  //while std input is coming
   {
      cin >> mineProb;  //get mine probablity
  
      cout << "The size of the matrix is: " << mineFieldSize << " X " << mineFieldSize << "  with a mine probablity of " << mineProb << endl;
      cout << endl;
 
   //resize the vectors for minefield
      myVectorResize(mineField, mineFieldSize);
      myVectorResize(countField, mineFieldSize);      
 
      buildMineField( mineField, mineProb);
      displayMineLocations(mineField);  

      fixCounts(mineField, countField);
      displayMineCounts(countField);
   } 
}



/***************************************************************
Function Name:  buildMineField

Use: Builds a mine field.  The mine field is a 2d vector of boolean
     values.  True means there is a mine, alse no mine
 
Parameters: 1. 2d vector of bool to hold the mine field
            2. double mineProb to calculate probability of mine exisitng
               at a given location
***************************************************************/

void buildMineField( vector<vector<bool> >& mineField, const double&mineProb)
{
   for(unsigned int row = 0; row < mineField.size(); row++)
     {
        for(unsigned int col = 0; col < mineField[0].size(); col++)
          {
             double rnd = (double)rand() / (double(RAND_MAX) + 1);   
              
             if (rnd < mineProb) 
               mineField[row][col] = true;
             else
               mineField[row][col] = false;  
          }       	
     }
}
/***************************************************************
Function Name:  fixCounts

Use: fills the count vector witha value 0 - 9 indicating how many
     mines are in the neiughboring locations also includes actual
     location

Parameters: 1. Input 2d vector of bool to hold the mine field
            2. Output 2d vector of unsigned to hold the number of mines
***************************************************************/

void fixCounts(const vector<vector<bool> >& mineField, vector<vector<unsigned> >& countField)
{
   unsigned count;



   for(unsigned int row = 0; row < mineField.size(); row++)
   {
      for(unsigned int col = 0; col < mineField[0].size(); col++)
      {
         count = 0; //start count over for each
         
         if (row == 0)  //if in first row
         {
            if (col == 0) //top left corner
            {
               if (mineField.size() == 1) 
               {
                  if(mineField[row][col] == true) count++;
               }
               else 
               { 
                  if (mineField[row][col] == true) count++;   //check self
                  if (mineField[row][col+1] == true) count++;   //right
                  if (mineField[row+1][col] == true) count++;         //down
                  if (mineField[row+1][col+1] == true) count++;         //diag
               }   
               countField[row][col] = count;      
            }
            else if (col == (mineField[0].size()-1))  //top right corner
            {
               if (mineField[row][col] == true) count++;   //check self
               if (mineField[row][col-1] == true) count++;
               if (mineField[row+1][col] == true) count++;
               if (mineField[row+1][col-1] == true) count++;
               countField[row][col] = count;
            }
            else   //top row non corner
            {
               if (mineField[row][col] == true) count++;   //self
               if (mineField[row+1][col] == true) count++; //straight down
               if (mineField[row+1][col+1] == true) count++;       //diag down right
               if (mineField[row+1][col-1] == true) count++;       //diag down left
               if (mineField[row][col+1] == true) count++;       //right
               if (mineField[row][col-1] == true) count++;        //left
               countField[row][col] = count;
            }
         }
         else if (row == mineField.size()-1)  //bottom row
         {
            if (col == 0) //bottom left corner
            {
               if (mineField[row][col] == true) count++;   //check self
               if (mineField[row][col+1] == true) count++;   //right
               if (mineField[row-1][col] == true) count++;         //down
               if (mineField[row-1][col+1] == true) count++;         //diag
               countField[row][col] = count;      
            }
            else if (col == (mineField[0].size()-1))  //bottom right corner
            {
               if (mineField[row][col] == true) count++;   //check self
               if (mineField[row][col-1] == true) count++;
               if (mineField[row-1][col] == true) count++;
               if (mineField[row-1][col-1] == true) count++;
               countField[row][col] = count;
            }
            else   //bottom row non corner
            {
               if (mineField[row][col] == true) count++;   //self
               if (mineField[row-1][col] == true) count++; //straight up
               if (mineField[row-1][col+1] == true) count++;       //diag up right
               if (mineField[row-1][col-1] == true) count++;       //diag up left
               if (mineField[row][col+1] == true) count++;       //right
               if (mineField[row][col-1] == true) count++;        //left
               countField[row][col] = count;
            }
         }
         else if (col == 0)  //first coloumn excluding corners
         {
               if (mineField[row][col] == true) count++;   //self
               if (mineField[row-1][col] == true) count++; //straight up
               if (mineField[row-1][col+1] == true) count++;       //diag up right
               if (mineField[row+1][col+1] == true) count++;       //diag down right
               if (mineField[row][col+1] == true) count++;       //right
               if (mineField[row+1][col] == true) count++;        //down
               countField[row][col] = count;
         }
         else if (col == mineField[0].size()-1)  //last row excluding corners
         {
               if (mineField[row][col] == true) count++;   //self
               if (mineField[row-1][col] == true) count++; //straight up
               if (mineField[row-1][col-1] == true) count++;       //diag up left
               if (mineField[row+1][col-1] == true) count++;       //diag down left
               if (mineField[row][col-1] == true) count++;       //left
               if (mineField[row+1][col] == true) count++;        //down
               countField[row][col] = count;
         }
         else //the rest are all interior squares
         {
               if (mineField[row][col] == true) count++;   //self
               if (mineField[row-1][col] == true) count++; //straight up
               if (mineField[row-1][col-1] == true) count++;       //diag up left
               if (mineField[row+1][col-1] == true) count++;       //diag down left
               if (mineField[row][col-1] == true) count++;       //left
               if (mineField[row+1][col] == true) count++;        //down
               if (mineField[row-1][col+1] == true) count++;       //diag up right
               if (mineField[row+1][col+1] == true) count++;       //diag down right
               if (mineField[row][col+1] == true) count++;       //right
               countField[row][col] = count;

         }
      }
   }
}


/***************************************************************
Function Name:  displayMineLocations

Use: Displays a 2d array that represents a mine field  with X
     for mine locations
 
Parameters: 1. 2d vector of bool to hold the mine field
***************************************************************/


void displayMineLocations( const vector<vector<bool> >& mineField)
{
   for (unsigned int i = 0; i < mineField[0].size(); i++)   //print top bounry
      cout << " _ _ "; 
   cout << endl;

   for(unsigned int row = 0; row < mineField.size(); row++)
   {  cout << "| ";
      for(unsigned int col = 0; col < mineField[0].size(); col++)
      {  if (mineField[row][col] == true)                      //print x for mine location
         cout << " X | ";
         else 
         cout << "   | ";
      }
      cout << endl;
      for (unsigned int q = 0; q < mineField[0].size(); q++)   //print bottom boundry
        cout << "- - -";
      cout << endl;
   }
}

/***************************************************************
Function Name:  displayCounts

Use: displays the mine count 2d array
 
Parameters: 1. 2d vector of unsinged to hold the mine field counts
***************************************************************/


void displayMineCounts( const vector<vector<unsigned> >& mineField)
{
   cout << "\n\nThe mine count map\n\n ";

   for (unsigned int i = 0; i < mineField[0].size(); i++)       //print top boundry
      cout << " _ _ "; 
   cout << endl;

   for(unsigned int row = 0; row < mineField.size(); row++)
   {  cout << "| ";        //right boundry
      for(unsigned int col = 0; col < mineField[0].size(); col++)   //print the mine count
      {  cout << mineField[row][col]  << "  | ";
      }
      cout << endl;
      for (unsigned int q = 0; q < mineField[0].size(); q++)   //bottom boundry
        cout << "- - -";
      cout << endl;
   }
   
}
