/********************************************************
Nick Inserra z1749082
csci 689
prog5.h Header file

Purpose:  Contains Function Prototypes and
          constants used in prog5.cc
*********************************************************/

#ifndef PROG5_H
#define PROG5_H

#include <string>
#include <vector>

using namespace std;

const int SEED = 1;     //random probablity seed

void buildMineField( vector< vector<bool> >& mines, const double& mineProb);  
void displayMineLocations( const vector<vector<bool> >& mines);
void displayMineCounts( const vector<vector<unsigned> >& mines);
void fixCounts( const vector<vector< bool> >& mines, vector< vector< unsigned> >& counts);  //create count 2darray for mines in neihgboring areas

#endif
