/************************************************************o
CSCI 689 - Assignment 3 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 2/10

Purpose: This program creates a simple ceaser cipher.

Constants: INPUT_PATH: path of file to be ciphered
           ALPHA_NUMS: numbers in given alphabet
************************************************************/ 
#include "prog3.h"
#include <iostream>	//input output stream
#include <string>       //c++ strings
#include <fstream>      //file i/o
#include <cmath>        //modulo abs

using namespace std;

int main()
{

   int shift = 0;     //how far to shift character

  while(cin >> shift)  //while std input is coming
   {
   cout << "\n\nThe shift is " << shift << endl;         //output the shift


//if shifts are outside of +-26 correct with modulo
   if (shift > ALPHA_NUMS)
     {
      shift = shift % ALPHA_NUMS;
     }
   else if (shift < -ALPHA_NUMS)
     {
      shift = (shift % ALPHA_NUMS);
     }

   process_infile(shift);      //process the file
   }
}


/***************************************************************
Function Name:  process_infile

Use: First opens data file, then encrypts text and prints to std out 
Parameters: 1. shift a positive or negative int for the ceaser chiper
Returns: void
***************************************************************/

void process_infile(int shift)
{
//open the file and error check
   ifstream inputFile;
   inputFile.open(INPUT_PATH);
   if(!inputFile.is_open())
     {
      error(INPUT_PATH);
     }

   string buffer;
   string message = "";

   while (!inputFile.eof())
     {
      if (getline(inputFile, buffer))             //process one line at a time
      message += encodeCaesarCipher(buffer, shift) + "\n ";       //apply cipher to whole line
     }

    cout << message << endl;    //output whole message

   inputFile.close();     //close file

}

/***************************************************************
Function Name:  encodeCaesarCipher
Use: encodes a string by shifting the letters a given number
Parameters: 1. string:  string to be encoded
            2. shift:  amount of letters to shift
Returns:  A string that has been encrpyped by the ceaser cipher
***************************************************************/

string encodeCaesarCipher(string input, int shift)
{
   for (unsigned int i = 0; i < input.length(); i++)      //for whole string
   {
    if (isalpha(input[i]))  //must be alpha
     {
         input[i] = new_position(input[i], shift);   //call new postion
     }
   }
   return input;
}

/***************************************************************
Function Name:  new_position
Use: for a given character caluclated the new position after shift
Parameters: 1. char: character to be shifted
            2. shift:  amount of letters to shift
Returns:  An int that encrpypts by the ceaser cipher
***************************************************************/

int new_position(char c, int shift)
{
   int value = 0;

   if (isalpha(c))          //must be alpha
     {
      if (isupper(c))
        {
         value = (c - 'A');       //bring to zero
         value += shift;          //add shift
         if (value > ALPHA_NUMS - 1)          //if goes to high
           {
            value -= ALPHA_NUMS;
           }
         if (value < 0)          //if goes to low
           {
            value += ALPHA_NUMS;
           }
         return value + 'A';      //bring back to ascii proper
        }
      else
        {
         value = (c - 'a');        //bring to zero
         value += shift;          //add shift
         if (value > ALPHA_NUMS - 1)
           {
            value -= ALPHA_NUMS;
           }
         if (value < 0)
           {
            value += ALPHA_NUMS;
           }
          return value + 'a';       //bring back to ascii proper
        }
      }
    else return 0;             //return 0 if no shift




}

/***************************************************************
Function Name:  error
Use: wrapper class to call error
Parameters: 1. string: error message
Returns:  void
***************************************************************/

void error(const string& msg)
{
   cout << "Error cannot open seccond data file from  " << msg <<  endl;
   exit(EXIT_FAILURE);

}

