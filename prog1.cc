/************************************************************
CSCI 689 - Assignment 1 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 1/25

Purpose: This program accepts a single number from the
keyboard.  Then find the sum of the first N odd integers.

Constants:   START_NUM value at which you start counting odd integers
             typcially 1
             START_RANGE can start at other odd integers than 1 for range 
             default is 0
             RATE value for getting every odd or even number, 2 is default 
************************************************************/ 
#include "prog1.h"

#include <iostream>	//input output stream
#include <stdlib.h>	//exit

using std::cout;
using std::cin;
using std::endl;

int main()
{
   int range = 0;    //Range is N odd integers to be summed
   int sum = 0;

   cout << "This program will calcualte the sum of Odd Integers\n " ;
   cout << "Please enter a positive integer for how many Odd Integers you would like to sum\n " ;

   cin >> range;    //get range from stdin

   if ( (cin) && range >= 1)   //check for valid input
     {
      for (int i = START_RANGE; i < range; i++) //sum all odd numbers in range
	{ sum += (RATE * i) + START_NUM; }
     }
   else   //error and exit if not postive integer value
     {
      cout << "\n Error did not enter valid positive integer for the range\n";
      exit(EXIT_FAILURE);
     }

   cout << "\n The sum of the first " << range << " odd integers is:  " << sum << endl;

   //simple output
   cout << "\n N = " << range << endl;
   cout << "Sum = " << sum << endl;

}
