/********************************************************
Nick Inserra z1749082
csci 689
prog9 Header file

Purpose:  Contains Function Prototypes and
          constants used in prog9.cc
*********************************************************/

#ifndef PROG9_H
#define PROG9_H

#include <string>
#include <stack>
using namespace std;

void process_token(const string& token, stack <double> & S);
bool urnarySign(const char& c, const string& token, const unsigned& i);
bool floatPoint(const char& c, const string& token, const unsigned& i);
double getNumber(const char& c, const string& token, const unsigned& i, const bool& floatPointFlag);
bool isValidOperator(const char& c);
double operation(const char& c, const double& x, const double& y);
double popStack(stack <double>& S);
void printResult(const stack<double> & S);
void emptyStack( stack<double>& S);

#endif
