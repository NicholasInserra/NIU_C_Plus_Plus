/********************************************************
Nick Inserra z1749082
csci 689
prog2.3 Header file

Purpose:  Contains Function Prototypes and
          constants used in prog3.cc
*********************************************************/

#ifndef PROG3_H
#define PROG3_H
#include <string>

using namespace std;

const string INPUT_PATH = "/home/cs689/progs/16s/p3/prog3.d2";     //path for input file to be ciphered
const int ALPHA_NUMS = 26;                                          //leters in aplhabet

void process_infile(int shift);                                    //process file, calls other functions
string encodeCaesarCipher(string str, int shift);                 //ciphers the text, calls new_position & error
int new_position(char c, int shift);                              //finds actual new char
void error(const string& msg);                                    //error wrapper

#endif
