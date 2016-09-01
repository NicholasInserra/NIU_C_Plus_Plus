/************************************************************o
CSCI 689 - Assignment 9 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 4/12

Purpose:  This program creates a simple text based calculator
          Utlizies the stack containter. 
Constants: 
************************************************************/ 
#include "prog9.h"
#include <iostream>	//input output stream
#include <string>       //c++ strings
#include <stack>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
   string token;
   //stack to hold numebrs calcualted
   stack <double> myStack;
 
//while input is coming into calcualtor
   while (cin >> token)
   {
      process_token(token, myStack);   //keep calcualting
   }
}


/***************************************************************
Function Name:  prcoess_token()

Use: Main function of program.  Will process input and store numbers
     into the stack.  If and operator or clear is in the token
     it will process accordingly

Parameters: stringt he command, stack to store numbers

Notes:  Token is defined as coninuous string no white space  

Returns: void
***************************************************************/
void process_token(const string& constToken, stack <double> & S)
{

   double result = 0.0;
   //move const token, so we can manipulate it
   string token = constToken;
   //length process of token to determine end of string
   int lengthUsed = 0;
   //length flag is true if size is 1 which causes .substr to not funtion properly
   bool lengthFlag = false;
   //pushFlag resets i to zero when true because working with new substring
   bool pushFlag = false;

   for( unsigned i = 0; i <= token.length(); i++)  //For the whole token
   {
      //set length flag because of size 1 errors
      if (token.length() == 1)
      {
         i = 0; lengthFlag = true;   
      }
      else lengthFlag = false;
      //if push flag is on reset i then reset flag
      if (pushFlag) 
      {
         i = 0;
         pushFlag = false;
      }
      //checking if valid number
      if ( isdigit(token[i]) || urnarySign(token[i], token, i) || floatPoint(token[i], token, i) )  
      {  
         if ( (i == token.length() - 1) )  //only push at end of number
         {
            result = getNumber(token[i], token, i, floatPoint(token[i], token, i) );  //get the result and store it
            S.push(result);
         }
         else if (isValidOperator(token[i+1]) )    //if next char is an operator its the end of number
         {  
            string subToken = token.substr(0,i+1);        //get sub token to store
            lengthUsed += subToken.length();              //store length used
            //size 1 can't use substring to store remaming token
            if (constToken.length() - lengthUsed == 1)
            {
                token.resize(1);
               token = constToken.back();
            }
            else      //if size is bigger get remaining token
            {
                token = token.substr(i+1);
            }           
            result = getNumber(subToken[0], subToken, i, floatPoint(subToken[i], subToken, i) );  //store the number
            S.push(result);
            i=0; pushFlag = true;         //pushFlag true because same token, but new sub token
         }  
         if (lengthFlag) i++;        
      }
      else if ( isValidOperator(token[i]) )    //if valid +-/*
      {
         //get top two numbers on stack
         double num1 = popStack(S);               
         double num2 = popStack(S);
         //calculate result based on operator
         double operatorResult = operation(token[i], num1, num2);
         S.push(operatorResult);
         //substr for bigger tokens else for 1 remaming
         if (token.size() != 2)
            token = token.substr(token[i+1]);
         else token = token.back();
         if (lengthFlag)i++;  
      }
      else if (token[i] == '=')   //if equal sign
      {
         printResult(S);
         if (lengthFlag)i++;
      }
      else if (token[i] == 'c')   //if c clear 
      {
           emptyStack(S);
           token = token.substr(i+1);
           pushFlag = true;
      }
      else //get the errors
      {
         if (token[i] == '!')
         {
            cout << "error: character '" << token[i] << "' is invalid" << endl;
         }
         if (lengthFlag)i++;
      }
    }
}



 /****************************************************************

   FUNCTION:  urnarySign()
   
   ARGUMENTS:  char c to analyze, string that holds character, i the index

   RETURNS: bool true if it is a valid urnary sign + or -

   NOTES:     
****************************************************************/
bool urnarySign(const char& c, const string& token, const unsigned& i)
{
 if( token.length() == 1) return false;

 if (c == '+' || c == '-')
 {
   if (i < token.length())       //if not at end of tken
   {  
      if (isdigit(token[i+1]) || token[i+1] == '.')  //next char has to be digit or .
      {
         return true; 
      }
      else return false;
   }
   else {return false;}
 }
 else return false; 
}

 /****************************************************************

   FUNCTION:  floatPoint
   
   ARGUMENTS: char c to analyze, string that holds character, i the index
 
   RETURNS: bool true if it is a valid decimal

   NOTES:     
****************************************************************/

bool floatPoint(const char& c, const string& token, const unsigned& i)
{
 if (c == '.')
 {
   if (i < token.length())       //if not at end of tken
   {  
      if (isdigit(token[i+1]))   //next nuber has to be a digit
      {
         return true; 
      }
      else return false;
   }
   else return false; 
 }
 else return false;
}

 /****************************************************************

   FUNCTION:  getNumber()
    
   ARGUMENTS: char c to analyze, string that holds character, i the index
 
   RETURNS: double a valid double point number

   NOTES:     
****************************************************************/

double getNumber(const char& c, const string& token, const unsigned& i, const bool& floatPointFlag)
{  
   if(c == c && i == i && floatPointFlag == floatPointFlag)
   {}
   size_t numberOfDecimal = count(token.begin(), token.end(), '.');
   if (numberOfDecimal <=1)
   {
      return stod(token);
   }
   else
   {
   cerr << "error: number '" << token << "' is invalid" << endl;
   return 33333.33333;
   }   
}

 /****************************************************************

   FUNCTION:  isValidOperator()
   
   ARGUMENTS:  char c is determine if it is valid

   RETURNS: true if + - * /

   NOTES:     
****************************************************************/

bool isValidOperator(const char& c)
{
   if ( c == '+' || c == '-' || c == '*' || c == '/' )
   {
      return true;
   }
   else return false;
}

 /****************************************************************

   FUNCTION:  operation()
   
   ARGUMENTS:  const char C the operation, x and y to double numbers

   RETURNS: doubble the result

   NOTES:     
****************************************************************/

double operation(const char& c, const double& x, const double& y)
{
   if ( c == '+' )
   {
      return x + y;
   }
   else if ( c == '-' )
   {
      return y - x;
   }
   else if ( c == '*' )
   {
      return x * y;
   }
   else if ( c == '/' )
   {
     if (x != 0)
     {
        return y / x ;
     }
     else return 33.33;   //error returns
   }
   else return 33.33;   //error returns
}

 /****************************************************************

   FUNCTION: popStack() 
   
   ARGUMENTS:  stack of double numbers

   RETURNS: double the number on top of stack

   NOTES:     error if empty
***************************************************************/


double popStack(stack <double>& S)
{
   if ( !S.empty())
   {
      double temp = S.top();
      S.pop();
      return temp;
   }
   else 
   {
      cerr << "error: stack is empty\n";  
   }
   return 0.0;
}

 /****************************************************************

   FUNCTION:  printResult()
   
   ARGUMENTS:  Stack of doubles

   RETURNS: void

   NOTES:     
****************************************************************/

void printResult(const stack<double> & S)
{
   if ( !S.empty())
   {
      cout << setw(8) << right << fixed << setprecision(2) << S.top() << endl;
   } 
}

 /****************************************************************

   FUNCTION:  emptyStack()
   
   ARGUMENTS:  stack of doubles S

   RETURNS: void

   NOTES:     empties the stack
****************************************************************/

void emptyStack(stack<double> & S)
{
   while (! S.empty())
     S.pop();
}


