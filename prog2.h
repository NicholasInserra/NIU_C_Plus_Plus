/********************************************************
Nick Inserra z1749082
csci 689
prog2.h Header file

Purpose:  Contains constants used in prog2.cc
*********************************************************/

#ifndef PROG2_H
#define PROG2_H
#include <string>

using namespace std;

const int MAX_VALUE = 9999;     //max range to look for perfect numbers
bool isPerfect(unsigned int n);		//determine if number is perfect
string divisors(unsigned int n);	//list divisiors of number

#endif
