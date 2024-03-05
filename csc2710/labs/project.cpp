/*
   Author: Isabella Edwards
   Class: CSC2710
   Due Date: 10/7/22
   Group Project: Insertion Sort

   To compile: 
      g++ project.cpp

   To execute:
      ./a.out
*/

// preprocessor directives
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sys/time.h>
#include<string>
using namespace std;

void insertionSort(int S[], int length);

// determining time
timeval startTime, stopTime;
double start, stop, diff;

// max number of elements in the list
int MAX = 10000;

void insertionSort(int S[], int length)
{
   // declaring variables
   int location = 0;
   int counter = 0;
   int i, j;

   // calling gettimeofDay
   gettimeofday(&startTime, NULL);
   
   // insertion sort 
   for(i = 1; i < length; i++)
   {
       location = S[i];
       j = i - 1;
       while (j >= 0 && S[j] > location)
       {
          S[j+1] = S[j];
          j--;
          counter++;
       }
       
       S[j+1] = location;
    }
 
    // calculating time
    gettimeofday(&stopTime, NULL);

    start = startTime.tv_sec+(startTime.tv_usec/1000000.0);
    stop = stopTime.tv_sec+(stopTime.tv_usec/1000000.0);

    diff = stop - start;

    // outputing elements of the array
    for(int i = 0; i<length; i++)
    {
       cout<<S[i]<<" ";
    }
    // outputing counter and time
    cout<<"\nCounter = "<<counter<<endl;
    cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
  
}

int main()
{
   // declaring variables
   int array[MAX];
   int n;
   string filename = "";

   // asking user for input
   cout<<"Enter the name of the file with random numbers: ";
   cin>>filename;

   // opening file
   ifstream my_file;
   my_file.open(filename);
   // checking whether file exists
   if(!my_file)
      cout<<"No such file!";
   else
   {
      cout<<endl<<endl;
      cout<<"Enter the number of random numbers (max = 10,000) = ";
      cin>>n;
   }
   // loading file into the array
   for(int i = 0; i < n; i++)
      my_file >> array[i];

   // closing file
   my_file.close();

   cout<<endl<<endl;
   
   // calling insertionSort
   insertionSort(array, n);

  return 0;
}







