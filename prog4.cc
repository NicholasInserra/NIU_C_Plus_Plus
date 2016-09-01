/************************************************************o
CSCI 689 - Assignment 4 - Spring 2016

Progammer: Nick Inserra
Z-ID: z1749082
Section: 2
Date Due: 2/18

Purpose: Removes comments from a .cc source file.
Constants:  INPUT_PATH
            OUTPUT_PATH
************************************************************/ 
#include "prog4.h"
#include <iostream>	//input output stream
#include <string>       //c++ strings
#include <fstream>      //file i/o

using namespace std;

int main()
{

//declare streams for i/o
   ifstream infile;
   ofstream outfile;

//opens files
   open_files(infile, outfile);

//remove comments
   process_data(infile, outfile);

   close_files(infile, outfile);
}


/***************************************************************
Function Name:  open_files

Use: First opens .cc files & error checks 
Parameters: &instream forinput file, &ostream for output
Returns: void
***************************************************************/

void open_files(ifstream& instream, ofstream& ostream)
{
//open the file and error check
   instream.open(INPUT_PATH);
   if(!instream.is_open())
     {
      error(INPUT_PATH);
     }
//open outputfile and error check
   ostream.open(OUTPUT_PATH);
   if(!ostream.is_open())
     {
      error(OUTPUT_PATH);
     }

}

/***************************************************************
Function Name:  process_data
Use: removes comments from code
Parameters: 1. ifstream:  input file
            2. ofstream: output file
Returns:  void

Notes:   sometimes deletes wholele lines esepcially when using
         */ /* on a single line with actual code
***************************************************************/

void process_data( ifstream& instream, ofstream& ostream)
{
   string buffer;             //buffer to hold each line
   bool comment_flag = false; //signals multi line comment on

   while( !instream.eof())   //while in file
      {
       getline(instream, buffer);  //process line
  
       if (comment_flag)     //if multi line comment
         {
          if (buffer.find("*/") < buffer.length()) //searcg for delimeter
            {
            buffer.erase(0, buffer.find("*/")+2);  //delete including delimter
            comment_flag = false;   //turn multi line comment off
            }
          else buffer.clear();   //else clear line
         }




//handles two part comment structure

       if (buffer.find("/*") < buffer.length())    //find comment start
         {
          if (buffer[0] == '/' && buffer[1] == '*') comment_flag = true;   //if it starts the line just exit and mark as true
          
     //ignore comments in " " quotes
          else if (buffer.find("\"/*") != string::npos)
                  {}
          else if (buffer.find("/*\"") != string::npos)
                  {}
         
          else if ( (buffer.find("*/") != string::npos) && (buffer.find("//") == string::npos) ) //if there is no// to wrory about 
               {
                buffer.erase(buffer.find("/*"), buffer.find("*/")+2); //erase within delimters
                comment_flag = false;                                 //end multi line comment
               } 
          else if (buffer.find("/*") < buffer.find("//") )           //if /* before //
               {
                if (buffer.find("*/") != string::npos)               //if delimters */
                  {
                   buffer.erase(buffer.find("/*"),buffer.find("*/")+2);
                   comment_flag = false;
                  }
                 else                                             //delete wholeline leave flag on for multi line
                  {
                   buffer.erase(buffer.find("/*"), string::npos);
                   comment_flag = true;
                  }

              }
         }

       if (!comment_flag)   //if multi linecomment not on
         {
          for (unsigned int i = 0; i < buffer.length(); i++ )  //iterate through one by one
            {
             if ( i < buffer.length() )
               {
                if ( (buffer[i]=='/') && (buffer[i+1]=='/') && (buffer[i-1] !='"') && (buffer[i+2] != '"') ) break;  //break for quotes " "
             else
		{
                 ostream << buffer[i];  //output the code to stream
                }
               }
            }
          ostream << endl;
         }
      
      //check flag turn off if */ 
       if (comment_flag)
         {
          if( buffer.find("*/") < buffer.length() ) comment_flag = false;
         }
      }
}


/***************************************************************
Function Name:  error
Use: wrapper class to call error
Parameters: 1. string: error message
Returns:  void
***************************************************************/

void error(const string& msg)
{
   cout << "Error cannot open file from  " << msg <<  endl;
   exit(EXIT_FAILURE);
}

/***************************************************************
Function Name:  close_files
Use: wrapper class to to close both stream
Parameters: 1. ifstream input stream
            2. ofstream output stream
Returns:  void
***************************************************************/


void close_files(ifstream& instream, ofstream& ostream)
{
   instream.close();
   ostream.close();
}

