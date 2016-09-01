/************************************************************o
CSCI 689 - Assignment 7 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 3/24

Purpose:  This files contains the implemtations of the Date class
          Has get and set methods for all 3 private data members
          Insertion and Output stream overloads
          Month converstions
          Constructer
          validation methods
          toString conversion methods
          Updated Features

          contains non member function int to string

Constants:  Vector Months containing all months
            Default values for 3 private data members
            month day year
************************************************************/ 
#include "Date.h"

#include <stdlib.h>
#include <vector>
#include <iostream>	//input output stream
#include <algorithm>

using namespace std;

/***************************************************************
Function:  Date constructer

Use: create instance of Date object

Returns: nothing

Notes:   default values in header file
         calls method Month to format months
***************************************************************/
Date::Date(const string& m, const int& d, const int& y)
{
   month = m;
   day = d;
   year = y;
   this->Month();    //format month capitlzation
}

/***************************************************************
Function: copy constructer

Use: create instance of Date object

Returns: nothing

Notes:
**************************************************************/
Date::Date(const Date& d)
{
   month = d.month;
   day = d.day;
   year = d.year;
}


/***************************************************************
Function:  setMonth()

Use:  sets the month for date object

Returns: void

Notes:  format with Month() member
***************************************************************/ 
void Date::setMonth(const string& m)
{
   month = m;
   this->Month();   //capitalize
}


/***************************************************************
Function:  setDay()

Use: sets the day member of Date object

Returns: void

Notes:
***************************************************************/ 
void Date::setDay(const int& d)
{
   day = d;
}

/***************************************************************
Function:  setYear()

Use: sets year of Date object

Returns: void

Notes:
***************************************************************/ 
void Date::setYear(const int& y)
{
   year = y;
}


/***************************************************************
Function: getMonth() 

Use: gets month from Date object

Returns: string month

Notes:
***************************************************************/ 
string Date::getMonth() const
{
   return month;
}

/***************************************************************
Function:  getYear()

Use: get year from Date Object

Returns: int for year

Notes:
***************************************************************/ 
int Date::getYear() const
{
   return year;
}

/***************************************************************
Function:  getDay

Use: get day from Date object

Returns: the day as int

Notes:
***************************************************************/ 
int Date::getDay() const
{
   return day;
}

/***************************************************************
Function:  Month()

Use: converts MOnth to first letter capitol rest lower case

Returns: nothing

Notes:
***************************************************************/ 
void Date::Month()
{
   month[0] = toupper(month[0]);   //first letter caps

   for (unsigned int i =1; i < month.length(); i++)    //lowercase rest
      month[i] = tolower(month[i]);
}


/***************************************************************
Function:  isValidDate()

Use: checks if date is valid

Returns: true is it is a valid date
         false if not

Notes:   month stored in constant string
         days of the month
         gets leap year
***************************************************************/ 
bool Date::isValidDate() const
{
   if (!(this->isValidMonth()))
   {
      return false;   //check month
   }
   else						//check day
   {
      if(day > this->daysInMonth(month) || day < 1) return false; //invalid date   
      else 
      {
         if(year == 0) return false;           //check year not zero
         else
           return true;
      }
   }                                              
}   

/***************************************************************
Function:  isValidMonth()

Use: checks if month is valid

Returns: bool if month is in list

Notes:   
***************************************************************/ 
bool Date::isValidMonth() const
{
   if ( find(months.begin(), months.end(), month) != months.end())
   {
      return true;     
   }
   else
      return false;
}

/***************************************************************
Function: daysInMonth  

Use:   find how many days in a month

Returns: int days in a month

Notes:   index is month -1 so months[0] == january
***************************************************************/ 
int Date::daysInMonth(const string& m) const
{
   if( m == months[0] || m == months[2] || m == months[4] || m == months[6] || m == months[7] || m == months[9] || m == months[11] )
     return 31;

   else if( m == months[3] || m == months[5] || m == months[8] || m == months[10]) 
     return 30;

   else
   {
      if (isLeapYear())
        return 29;
      else return 28;
   }
}

/***************************************************************
Function:  isLeapYear()

Use: calculates if it is a leap year

Returns: bool true if it is a leap year

Notes:  
***************************************************************/ 
bool Date::isLeapYear()const
{
   if (year % 100 == 0) //if divisible by 100
   {
      if(year % 400 == 0)
      { 
        return true;
      }
      else
      {
        return false;
      }
   }
   else
   {
      if(year % 4 == 0)
      {
         return true;
      }
      else
      {
         return false;
      } 
   }
}

/***************************************************************
Function:  toString()

Use: changes format toa string

Returns: formated string of type dd-Mon-yyyy

Notes:
***************************************************************/ 
string Date::toString() const
{
   string final = "";

   string dayS = intToString(day);
   string yearS = intToString(year);
   string monthS = month;
   monthS.resize(3);    //get first three letter abbreviations

   final = dayS + "-" + monthS + "-" + yearS;    //put hyphen

   return final;
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

/***************************************************************
Function:  operator<<

Use: overload << operator

Returns: os outputstream

Notes:  friend function
***************************************************************/ 
ostream& operator<<(ostream& os, const Date& dt)
{
   os << dt.getMonth() << " " << dt.getDay() << " " << dt.getYear();
   return os;
}


/***************************************************************
Function:  istream()

Use: istream operator overload

Returns: is stream

Notes:
***************************************************************/ 
istream& operator>>(istream& is, Date& d)
{
   string month;
   int day, year;

//get the variables
   char check;
   is >> month >> day >> check;
   if (isdigit(check))
   {
      is.unget();   //take care of comma
      is >> year;
   }
   else is >> year;  

//get data into object
   d.setMonth(month);
   d.setYear(year);
   d.setDay(day);
   
   return is;
}

/***************************************************************
Function:  Assignment Operator Overload

Use: overload assign

Returns: Date Object

Notes:   checks to make sure not assignings itself
***************************************************************/


Date& Date::operator=(const Date& d)
{
   if(this != &d) //check for same object
   {
      month = d.month;
      day = d.day;
      year = d.year;
      return *this;
   }
   else return *this;
}


/***************************************************************
Function:   dayIndex

Use: creates index for the days for date class

Returns: an integer for the index

Notes:   works ok with smaller time periods
***************************************************************/

int Date::dayIndex() const
{
   int monthId = this->monthIndex();
   int dayIndex = 1;
   if (year > 0)
   {
   {

      for(int i = 1; i < year; i++)
      {
         dayIndex += daysInYear(year); //first get all full years
      }  
      for(int i = 0; i < monthId; i++)
      {
         dayIndex += this->daysInMonth(months[i]);   //get all full months
      }
   }
   dayIndex += day;    //get remaining days
   }
  else   //negative index
   {
      for(int i = -1; i > year; i--)
      {
         dayIndex -= daysInYear(year); //first get all year
      }  
      for(int i = 11; i > monthId; i--)
      {
         dayIndex -= this->daysInMonth(months[i]);
      }
   dayIndex -= (this->daysInMonth(this->getMonth()) - day) ; 
   }
   return dayIndex;
}


/***************************************************************
Function:  monthIndex()

Use: gets index of an object

Returns: const int

Notes:   0 -11 index for months
*************************************************/
int Date::monthIndex() const
{
   for(int i = 0; i < 12; i++)
   {
      if( month == months[i])
          return i;
   }
 return 1;
}


/***************************************************************
Function:  addDay()

Use: adds days Date object

Returns: date object
Notes:   can add positive and negative
***************************************************************/


Date& Date::addDay(const int& d)
{
   int day;
   int currentMonth;

if( d > 0)	//if positive
{
   day = this->getDay() + d;        //add all the days
   currentMonth = this->daysInMonth(month);    //store current month
   
   while (day >= 365)                        //add full years while you can
   {
      this->addYear(1);
      if (this->isLeapYear())
      {
         day -= 366;
      }
      else day -= 365;
   }
   
   while (day > currentMonth )             //add full months while you can
   {
      day -= this->daysInMonth(month);
      this->addMonth(1);
      currentMonth = this->daysInMonth(month);  
   }
   
   this->setDay((day) % this->daysInMonth(month));   //add rest of days
}
else     //for all the negatives
{
   day = this->getDay() + d;                   //add all days
   currentMonth = this->daysInMonth(month);
   
   while (day <= -365)				//add full years
   {
      this->addYear(-1);
      if (this->isLeapYear())
      {
         day += 366;
      }
      else day += 365;
   }
   
   while (day < -currentMonth )                 //if going over current month
   {
      day += this->daysInMonth(month);
      this->addMonth(-1);
      currentMonth = this->daysInMonth(month);  
   }
  
   if (day < 0)
      day *= -1; 
   this->setDay((day) % this->daysInMonth(month));
 }

 return *this;
   
   

}


/***************************************************************
Function:  Date constructer

Use: create instance of Date object

Returns: nothing

Notes:   default values in header file
         calls method Month to format months
***************************************************************/

Date& Date::addMonth(const int& m)
{
   int month;

   if( m > 0)
   {
      month = this->monthIndex() + m;    //add year if to many month
      this->addYear(month/12);
      int curMon = month % 12;
      
      if (this->daysInMonth(this->getMonth()) > this->daysInMonth(months[curMon]) )
      {
         this->setDay(2);
         this->setMonth(months[(month % 12) +1]);
      }
      this->setMonth(months[month % 12]); 
   }
   else
   {
    // int curMon = month % 12;

     if ((this->monthIndex() - m ) >= 11) this->addYear(-1);

      month = this->monthIndex() + m;    //add year if to many month
      month += 12;
      this->addYear((-1)*(month/12)); 
      this->setMonth(months[month % 12]); 
   }

   return *this;
}

/***************************************************************
Function:  Date constructer

Use: create instance of Date object

Returns: nothing

Notes:   default values in header file
         calls method Month to format months
***************************************************************/

Date& Date::addYear(const int& y)
{  
   int year;

   if (y > 0)
   {
      year = this->getYear();
      if(year < 0 && (year + y) >= 0)
      year += 1;

      

      this->setYear(year + y);
   }
   else
   {
      year = this->getYear();
      if(year > 0 && (year + y) <= 0)
      year -= 1;  //account for no year zero
      this->setYear(year + y);
   }

   if( (!this->isLeapYear()) && this->getMonth() == "February" && this->getDay() == 29 )
   {
      this->setMonth("March");
      this->setDay(1);
   }

   return *this;
}


/***************************************************************
Function:  Date constructer

Use: create instance of Date object

Returns: nothing

Notes:   default values in header file
         calls method Month to format months
***************************************************************/

unsigned dateDiff( const Date& d1, const Date& d2)
{
   int day1 = d1.dayIndex();
   int day2 = d2.dayIndex();
 
   if (day1 < 0 && day2 > 0)
     return unsigned(day2 - day1 + 1);

   if (day2 < 0 && day1 > 0)
     return unsigned(day1 - day2 + 1);

  if (day1 < 0 && day2 < 0)
     return unsigned(day1 + day2);
  else
  {
     if (day1 > day2) 
     {
        return unsigned(day1 - day2);
     }
     else
       return unsigned(day2 - day1);
  }
}


/***************************************************************
Function:  Date constructer

Use: create instance of Date object

Returns: nothing

Notes:   default values in header file
         calls method Month to format months
***************************************************************/


int daysInYear(const int year)
{
   if (year % 100 == 0) //if divisible by 100
   {
      if(year % 400 == 0)
      { 
	return 366;
      }
      else
      {
	return 365;
      }
   }
   else
   {
      if(year % 4 == 0)
      {
	 return 366;
      }
      else
      {
	 return 365;
      } 
   } 
}










