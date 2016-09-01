/************************************************************o
CSCI 689 - Assignment 7 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 4/1/16

Purpose:  This files contains the implemtations of the Rational Number class
          Overloads: + ++ - -- > < >= <= == = != << >> += * *= / /= -=

Notes: Throws error if ettempting to divide by zero

Constants: None
************************************************************/ 
#include "Rational.h"
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>	//input output stream
#include <algorithm>
#include <sstream>
using namespace std;

/***************************************************************
Function:  Rational constructer

Use: create instance of Rational object

Returns: nothing

Notes:   default values in header file
***************************************************************/
Rational::Rational(const int& n, const int& d)
{
   if (d == 0) cerr << "Error: Division by zero\n";
   else
   { 
      if (n == 0)  //if top is zero make it zero
      {
         num = 0;
         den = 1;
      }
      else
      {
         int g = gcd(abs(n),abs(d));  //makesure in reduced form
         num = n/g;
         den = abs(d)/g;
         if (d < 0) num = -num;
      }
   }
}

/***************************************************************
Function: copy constructer

Use: create instance of Rational object

Returns: nothing

Notes:
**************************************************************/
Rational::Rational(const Rational& r)
{
   num = r.num;
   den = r.den;
}

/****************************************************************
Function:  gcd()

Use:  finds greatest common denominator

Returns: int the gcd

Notes:
***************************************************************/ 
int Rational::gcd(int x, int y)
{
   int g = x % y;
   while (g != 0)
   {
       x = y;
       y = g;
       g = x % y;
   }
   return y;
}



/****************************************************************
Function:  setNum()

Use:  sets the numerator for the Rational object

Returns: void

Notes:
***************************************************************/ 
void Rational::setNum(const int& n)
{
   num = n;
}


/***************************************************************
Function:  setDen()

Use: sets the day denomnator of Rational object

Returns: void

Notes:
***************************************************************/ 
void Rational::setDen(const int& d)
{
   den = d;
}
/***************************************************************
Function: getNum() 

Use: gets Numerator from Rational object

Returns: int numerator

Notes:
***************************************************************/ 
int Rational::getNum() const
{
   return num;
}
/***************************************************************
Function:  getDen

Use: get denominator from Rational object

Returns: the denomaintor as int

Notes:
***************************************************************/ 
int Rational::getDen() const
{
   return den;
}

/***************************************************************
Function:  toString()

Use: changes format toa string

Returns: String rational number

Notes:  if the denomnator is 1 it will output whole number
***************************************************************/ 
string Rational::toString() const
{
   if (den == 1)   return intToString(num);   //whole number
   else   return intToString(num) + "/" + intToString(den);   //fraction
}

/***************************************************************
Function:  intToString()

Use: changes int to string

Returns: string

Notes: not a member function
***************************************************************/ 
string intToString(const int& n)
{
   return to_string(n);
}


/****************************************************************
Function:  OverLoad +

Use:  allows for addition of Rational objects

Returns: Rational object sum of two objects

Notes:
***************************************************************/ 
Rational operator+(const Rational& r1,const Rational& r2)
{
   return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}
/****************************************************************
Function:  OverLoad -

Use:  allows for subtraction of Rational objects

Returns: Rational object difference of two objects

Notes:
***************************************************************/ 
Rational operator-(const Rational& r1,const Rational& r2)
{
   return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

/****************************************************************
Function:  OverLoad *

Use:  allows for Multiplication of Rational objects

Returns: Rational object of product two objects

Notes:
***************************************************************/ 
Rational operator*(const Rational& r1,const Rational& r2)
{
   return Rational(r1.num * r2.num, r1.den * r2.den);
}

/****************************************************************
Function:  OverLoad /

Use:  allows for division of Rational objects

Returns: Rational object quotient of two objects

Notes:
***************************************************************/ 
Rational operator/(const Rational& r1,const Rational& r2)
{
   return Rational(r1.num * r2.den, r1.den * r2.num);
}



/***************************************************************
Function:  operator<<

Use: overload << operator

Returns: os outputstream

Notes:  friend function
***************************************************************/ 
ostream& operator<<(ostream& os, const Rational& rat)
{
   os << rat.toString();
   return os;
}


/***************************************************************
Function:  istream()

Use: istream operator overload

Returns: is stream

Notes:
***************************************************************/ 
istream& operator>>(istream& is, Rational& r)
{
  int n = 0, d = 1;
  string sep = "none";
  string line;

   getline(is, line);            //get whole line
   istringstream iss(line);         //make stream
   iss >> n >> sep >> d;            //seperate the pieces
   if (sep != "/" && sep != "none") 
   {
      cerr << "Error stdin is not valid Rational number\n";
   }
   else
   {
      Rational temp(n,d);   //reduce 
      r = temp;             //assign
   }
   return is;
}

/***************************************************************
Function:  Assignment Operator Overload

Use: overload assign

Returns: Rational Object

Notes:   checks to make sure not assignings itself
***************************************************************/


Rational& Rational::operator=(const Rational& r)
{
   if(this != &r) //check for same object
   {
      num = r.num;
      den = r.den;
      return *this;
   }
   else return *this;
}


/***************************************************************
Function:  += Operator Overload

Use: overload plus equals

Returns: Rational Object

Notes:
***************************************************************/


Rational& Rational::operator+=(const Rational& r)
{
   num = num * r.den + r.num * den;
   den = den * r.den;
      int g = gcd(abs(num),abs(den));
      num = num/g;
      den = abs(den)/g;
      if (den < 0) num = -num;
   return *this;
}
/***************************************************************
Function:  -= Operator Overload

Use: overload minues equals

Returns: Rational Object

Notes:
***************************************************************/


Rational& Rational::operator-=(const Rational& r)
{
   num = num * r.den - r.num * den;
   den = den * r.den;
   int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;
         if (den < 0) num = -num;
   return *this;
}
/***************************************************************
Function:  *= Operator Overload

Use: overload mult equals

Returns: Rational Object

Notes:
***************************************************************/


Rational& Rational::operator*=(const Rational& r)
{
   num = num * r.num;
   den = den * r.den;
  int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;
         if (den < 0) num = -num;
 return *this;
}
/***************************************************************
Function:  /= Operator Overload

Use: overload divide equals

Returns: Rational Object

Notes:
***************************************************************/


Rational& Rational::operator/=(const Rational& r)
{
  
   num = abs(num) * abs(r.den); 
   den = abs(den) * abs(r.num);
   int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;   
return *this;
}

/***************************************************************
Function:  ++Pre Operator Overload

Use: overload pre increment

Returns: Rational Object

Notes:
***************************************************************/
Rational& Rational::operator++()
{
   //add one to object
   num += den;
   int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;
         if (den < 0) num = -num;
   return *this;
}

/***************************************************************
Function:  --Pre Operator Overload

Use: overload pre decrement

Returns: Rational Object

Notes:
***************************************************************/
Rational& Rational::operator--()
{
   //add one to object
   num -= den;
   int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;
         if (den < 0) num = -num;
   return *this;
}

/***************************************************************
Function:  ++Pre Operator Overload

Use: overload post increment

Returns: Rational Object

Notes:
***************************************************************/
Rational Rational::operator++(int unused)
{
   Rational temp(*this);
   //add one to object
   num += den;
   int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;
         if (den < 0) num = -num;
   return temp;
}

/***************************************************************
Function:  --Post Operator Overload

Use: overload post decrement

Returns: Rational Object

Notes:
***************************************************************/
Rational Rational::operator--(int unused)
{
   Rational temp(*this); 
  //add one to object
   num -= den;
   int g = gcd(abs(num),abs(den));
         num = num/g;
         den = abs(den)/g;
         if (den < 0) num = -num;
   return temp;
}

/****************************************************************
Function:  OverLoad ==

Use:  Determine if two rational numbers are equal

Returns: bool true if equal

Notes:
***************************************************************/ 
bool operator==(const Rational& r1,const Rational& r2)
{
   if(r1.num == r2.num && r1.den == r2.den) return true;
   else return false;
}

/****************************************************************
Function:  OverLoad !=

Use:  Determine if two rational numbers are not equal

Returns: bool true if not equal

Notes:
***************************************************************/ 
bool operator!=(const Rational& r1,const Rational& r2)
{
   if(r1.num != r2.num || r1.den != r2.den) return true;
   else return false;
}

/****************************************************************
Function:  OverLoad >

Use:  Determine if rational numbers is greater

Returns: bool true if greater than

Notes:
***************************************************************/ 
bool operator>(const Rational& r1,const Rational& r2)
{
   if(r1.num * r2.den > r1.den * r2.num) return true;
   else return false;
}
/****************************************************************
Function:  OverLoad >=

Use:  Determine if rational numbers are greater or equal

Returns: bool true if equal

Notes:
***************************************************************/ 
bool operator>=(const Rational& r1,const Rational& r2)
{
   if(r1.num * r2.den >= r1.den * r2.num) return true;
   else return false;
}
/****************************************************************
Function:  OverLoad <

Use:  Determine if rational numbers are less than

Returns: bool true if less than

Notes:
***************************************************************/ 
bool operator<(const Rational& r1,const Rational& r2)
{
   if(r1.num * r2.den < r1.den * r2.num) return true;
   else return false;
}

/****************************************************************
Function:  OverLoad <=

Use:  Determine if rational numbers are less or equal

Returns: bool true if less or equal

Notes:
***************************************************************/ 
bool operator<=(const Rational& r1,const Rational& r2)
{
   if(r1.num * r2.den < r1.den * r2.num) return true;
    else return false;
}
