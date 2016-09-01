/********************************************************
Nick Inserra z1749082
csci 689
Date.h Header file

Purpose:  Contains Class declaration for Date class
          Contains constants for Date class
*********************************************************/

#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//constants
const string MONTH = "January";
const int DAY = 1;
const int YEAR = 2000;
const vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};




class Date
{
private:
//private data members
   string month;
   int day;
   int year;
//private member functions
   bool isValidMonth() const;
   int daysInMonth(const string& m) const;
   bool isLeapYear() const;
   int monthIndex()const;

public:
//constructer
   Date( const string& m = MONTH, const int& d = DAY, const int& y = YEAR);
   Date(const Date& d); //copy constructer
//set methods
   void setMonth(const string& m);
   void setDay(const int& d);
   void setYear(const int& y);
//get methods
   string getMonth() const;
   int getDay() const;
   int getYear() const;
//add functions
   Date& addDay(const int& n);
   Date& addMonth(const int& n);
   Date& addYear(const int& n);
//day index
   int dayIndex() const;
//convert month to be case insensitive
   void Month();
//check if date is valid
   bool isValidDate() const;
//conver date format
   string toString() const;
//assignment overload
   Date& operator=(const Date& d);
//friend stream functions
   friend istream& operator >>(istream& is, Date& d);
   friend ostream& operator <<(ostream& os, const Date& d);
 
   
};

string intToString(const int& n);
unsigned dateDiff(const Date& d1, const Date& d2);
int daysInYear(const int y);
#endif
