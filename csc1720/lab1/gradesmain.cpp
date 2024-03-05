/*
Emma Jerrier
January 11th 2022
CSC1720
~/csc1720/lab1
description: We used functions and arrays to read in students names and test sco
res, then average their personal scores, give them a letter grade and print that
 all in a table then print the class average
Assisted by: Troy Kubanka
*/

#include <iostream>
#include <fstream>
#include <iomanip>
// This will reference grades.h file where all the function prototypes are stored
#include "grades.h"

using namespace std;

// main function that just calls each of the individual functions
int main()
{
// declared integers for i and count and declares the array for scores (2d) 
   int i, count, scores[NUM_ROW][NUM_COL];
// declared the string array which stores names
   string names[NUM_ROW];
// declared the character array to store the letter grades for each student's average
   char letter[NUM_ROW];
// declared the average array to store each student's average to their row
   double average[NUM_ROW];
// declared the doubles needed to calculate the class average
   double sum=0, classavg=0;
//count is assigned to the value returned from getData to pass along the number of rows needed
   count=(getData(names, scores)-1);
   calcAvg(names, scores, average, count);
   letterGrade(count, names, scores, letter, average);
   printResults(count, names, scores, letter, average); 
// calculating the class average 
   for(i = 0; i<count; i++)
   {
      sum+=average[i];
   }
   classavg=sum/i;
   cout<<endl<<"Class Average is "<<classavg<<"%"<<endl;
   
   return 0;
}
   
