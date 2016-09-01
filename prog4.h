/********************************************************
Nick Inserra z1749082
csci 689
prog4 Header file

Purpose:  Contains Function Prototypes and
          constants used in prog4.cc
*********************************************************/

#ifndef PROG4_H
#define PROG4_H
#include <string>

using namespace std;

const string INPUT_PATH = "/home/cs689/progs/16s/p4/prog4-in.cc";     //path for input  file
const string OUTPUT_PATH = "prog4-out.cc";                            //path for output stream
void open_files( ifstream & is, ofstream & os);
void close_files( ifstream & is, ofstream & os);
void process_data( ifstream & is, ofstream & os);
void error( const string& msg);

#endif
