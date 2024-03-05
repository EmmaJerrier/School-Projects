/*
Emma Jerrier
November 18th 2021
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

using namespace std;

const int NUM_ROW=28;
const int NUM_COL=5;

// getData function to read in the string array with the names and to read in the 2d scores array with the 5 scores for each person in each row
int getData(string names[], int scores[][NUM_COL])
{
   int i=0, col, count=0;
   string filename;
   ifstream inFile;
   cout<<"Please input your file name!"<<endl;
   cin>>filename;
   inFile.open(filename);
   while(!inFile)
   {
      cout<<"Cannot open your datafile... Please try again!"<<endl;
      cin>>filename;
   }
// reading in the array
   inFile>>names[i];
   while(inFile)
   {
//      inFile>>names[i];
      for(col=0; col<NUM_COL; col++)
         inFile>>scores[i][col];    
      inFile>>names[i+1];
      i++;
   }
   count = i;
   inFile.close();

   return count;
}
// calcAvg function to take the scores array and calculate the average of each row (5 grades per row) and it assigns them to a separate function to be place holders
void calcAvg(string names[], int scores[][NUM_COL], double average[], int count)
{
   int row, i=0;
   double avg, a = 0;
// adds all the values in each row to be divided into an average
   for(row=0; row<count; row++)
   {
      i = 0;
      a = 0;
      while(i<NUM_COL)
      {
         a += scores[row][i];
         i++;
      }
      average[row] =static_cast<double>(a/NUM_COL); 
       
   }
}

// letterGrade function that reads from the average function and assigns a character value to each score
void letterGrade(int count, string names[], int scores[][NUM_COL], char letter[], double average[])
{
   int row=0;
// if elses to assign a character value to each average   
   while(row<count)
   {
      if(average[row] >= 90)
         letter[row] = 'A';
      else if(average[row] >= 80 && average[row] < 90)
         letter[row] = 'B'; 
      else if(average[row] >= 70 && average[row] < 80)
         letter[row] = 'C';
      else if(average[row] >= 60 && average[row] < 70)
         letter[row] = 'D';
      else if(average[row] < 60)
         letter[row] = 'F';
      row++;
   }
}

// printResults function prints out the first (sub [0]) row for each array and then increments the row so all of the row 0 are together and so on
void printResults(int count, string names[],int scores[][NUM_COL],char letter[], double average[])
{
   cout<<fixed<<showpoint;
   cout<<left<<setw(10)<<"Names:";
   cout<<right<<setw(9)<<"Scores:";
   cout<<right<<setw(19)<<"Average:";
   cout<<right<<setw(8)<<"Letter:"<<endl;
   for(int k=0; k<46; k++)
      cout<<"-";
   cout<<endl;

   for(int row = 0; row<count; row++)
   {
      cout<<left<<setw(10)<<names[row]<<" ";
      for(int col = 0; col<NUM_COL; col++)
         cout<<right<<setw(3)<<scores[row][col]<<" ";
      cout<<" "<<right<<setw(6)<<setprecision(2)<<average[row]<<" "<<right<<setw(7)<<letter[row]<<endl;
   }
}

 
