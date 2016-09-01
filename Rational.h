/********************************************************
Nick Inserra z1749082
csci 689
Rational.h Header file

Purpose:  Contains Class declaration for Rational class
          Contains constants for Rational class
*********************************************************/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>

using namespace std;

//constants
//const int YEAR = 2000;



class Rational
{
public:
//constructer
   Rational(const int& n = 0,const int& d = 1);
//copy constructer
   Rational(const Rational& r);
//set methods
   void setNum(const int&);
   void setDen(const int&);
   int getNum()const;
   int getDen()const;
   string toString()const;
// overloaded operators
   Rational& operator=(const Rational& r);
   Rational& operator*=(const Rational& r);
   Rational& operator/=(const Rational& r);
   Rational& operator+=(const Rational& r);
   Rational& operator-=(const Rational& r);
   Rational operator++(int unused);
   Rational operator--(int unused);
   Rational& operator--();
   Rational& operator++();
//overload arthimitc operators
   friend Rational operator+(const Rational& r1,const Rational& r2);
   friend Rational operator-(const Rational& r1,const Rational& r2);
   friend Rational operator*(const Rational& r1,const Rational& r2);
   friend Rational operator/(const Rational& r1,const Rational& r2);
//overload relational operators
   friend bool operator==(const Rational& r1, const Rational& r2);
   friend bool operator!=(const Rational& r1, const Rational& r2);
   friend bool operator<(const Rational& r1, const Rational& r2);
   friend bool operator<=(const Rational& r1, const Rational& r2);
   friend bool operator>(const Rational& r1, const Rational& r2);
   friend bool operator>=(const Rational& r1, const Rational& r2);

//friend stream functions
   friend istream& operator >>(istream& is, Rational& r);
   friend ostream& operator <<(ostream& os, const Rational& r);
private:
//private data members
   int num;	//numerator
   int den;	//denominator
//private member functions
   int gcd(int x,int y);

 
   
};

string intToString(const int& n);
#endif
