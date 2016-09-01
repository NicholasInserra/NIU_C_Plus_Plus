/************************************************************o
CSCI 689 - Assignment 2 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 2/2

Purpose: This program determines if numbers are "perfect" numbers
A perfect number has values which lower than the perfect number
that sum to its value, and are divisiable into the perfect number

Constants:   MAX_VALUE: Maximum range to look for perfect numbers
************************************************************/ 
#include "prog2.h"

#include <iostream>	//input output stream
#include <string>       //c++ strings

using namespace std;

int main()
{
   cout << "This will find perfect numbers between 1 and 9999 \n " ;

   for (unsigned int i = 1; i < MAX_VALUE; i++)   //for given range
    {
     bool perf = isPerfect(i);     //find if number is perfect

      if (perf == true)    //if it is perfect print the divisors
        {
         cout << "The number " << i << " is a perfect number " << endl;
         string res = divisors(i);   //returns string of divisors
         cout << res << endl;
        }


    }

}

/***************************************************************
Function Name:  isPerefct
Use: determins if a given number is "perfect"
Parameters: 1. n: unsigned int number to be tested 
Returns: true if number is perfect else false
***************************************************************/

bool isPerfect(unsigned int n)
{
   unsigned int sum = 0;
   //first find all factors for n
   for (unsigned int i = 1; i < n; ++i)
    {
      if (n % i == 0)
      {
       sum += i;  //sum all the numbers
      }
    }
   return sum == n; //for perfect number sum of factors equals number
}

/***************************************************************
Function Name:  divisors
Use: Lists divisors of a perfect number in good format
Parameters: 1. n: unsigned int number to find divisors of
Returns:  formatted string showing perfect number and it's divisors
***************************************************************/

string divisors(unsigned int n)
{
   string results = to_string(n) + " = "; //set up string

   for (unsigned int i = 1; i < n; i++)
    {
      if (n % i == 0)
      {
       results += to_string(i) + " + "; //add all divisors after with + sign
      }
    }
   results = results.substr(0, results.size() - 3);   //get rid of trailing + sign
   return results;
}
