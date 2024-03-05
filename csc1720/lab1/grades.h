/*
Emma Jerrier
January 11th 2022
CSC1720
~/csc1720/lab1
description: We used functions and arrays to read in students names and test scores, then average their personal scores, give them a letter grade and print that all in a table then print the class average
Assisted by: Troy Kubanka
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
// declared my 2 constants for my rows and column numbers
const int NUM_ROW=28;
const int NUM_COL=5;
/*
getData - reads in the names and scores from an outside file and puts the names in a string array and the scores in a parallel 2d array for each person
Precondition: The names array is going to be loaded with the student names and the 2 dimensional scores array will load in the student's scores with their respective rows
Postcondition: Both the names and scores arrays will be loaded with all the data in the File 
*/
int getData(string names[],int scores[][NUM_COL]);
/*
calcAvg - this function will calculate the average for each row of scores and store the value in an average array ith the same parallel corresponding row
Precondition:names and scores arrays are already loaded and as each row's average is calculated it is input into the average array and count is the result from the getData function and is the number of rows in each array
Postcondition:average will be loaded with data from the scores function
*/
void calcAvg(string names[],int scores[][NUM_COL], double average[], int count);
/*
letterGrade - this function checks the average array for each row and assigns a letter value in the letter array depending on where the average falls
Precondition: count brings the number of rows, names, scores, and average are all already loaded and letter is currently empty
Postcondition: the letter array will be loaded for each row up to count
*/
void letterGrade(int count, string names[],int scores[][NUM_COL],char letter[], double average[]);
/*
printResults - the function outputs the contents of the names array, the scores array, the letter array, and the average array in a formatted table
Precondition: each array is fully loaded from the previous functions
Postcondition: no changes will be made to the array
*/
void printResults(int count, string names[],int scores[][NUM_COL],char letter[], double average[]);
   

 
