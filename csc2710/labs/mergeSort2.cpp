/*
   Name: Ky Nguyen
   Class: CSC-2710
   Date: 9-28-2022
   
   Feature: implemting merge sort 
   
   Compile: g++ mergeSort2.cpp 
   Execute: ./a.out
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include <string>

using namespace std;

// prototype
void loadArray(string filename, int array[], int n);
void outputArray(int array[], int n);
void merge(int array[], int l, int m, int r);
void mergeSort (int array[], int l, int r);

// for determining time 
timeval startTime, stopTime;
double start, stop, diff;

// max size of elements in list
int MAX = 10000;

//counter for the number of times the for loop(s) were executed in mergesort function
int mergeSortCount = 0;
int mergeCount = 0;

// main function
int main()
{
   int array[MAX];
   int n;
   string filename = " ";
   int userArrayChoice;
   
   cout << "To hardcode an array, enter 0. To enter a file, enter 1." << endl;
   cin >> userArrayChoice;
   cout << endl << endl;

   if(userArrayChoice == 0)
   {
      cout << "How many numbers will be in your array?" << endl;
      cin >> n;

      int userArray[n];
      cout << endl << endl;

      cout << "Input the numbers in your array " << endl;
      for(int i = 0; i < n; i++)
         cin >> userArray[i];

      mergeSort(userArray, 0, n-1);
      //outputArray(array, n);
      for(int i = 0; i < n; i++)
      {
         cout << userArray[i] << endl;
      }
   }
   else if(userArrayChoice == 1)
   {
      cout << "Enter the name of the file with random numbers: ";
      cin >> filename;

      // input file 
      ifstream my_file;
      my_file.open(filename);
      if(!my_file)
      {
         cout << "No such file!";
      }
      else
      {
         cout << endl << endl;
         cout << "Enter the number of random numbers (max = 10,000) = ";
         cin >> n;
      }
   
      for(int i = 0; i < n; i++)
      {
         my_file >> array[i];
      }

      my_file.close();

      cout << endl << endl;
   
      mergeSort(array, 0, n - 1);
      //outputArray(array, n);
   }
   return 0;
}

//loadArray function
void loadArray(string filename, int array[], int n)
{
   ifstream my_file;
   my_file.open(filename);
   for(int i = 0; i < n - 1; i++)
   {
      my_file >> array[i];
   }
   my_file.close();
}

// Debugging
/*void outputArray(int array[], int n)
{
  string input;
  cout << "Output the sorted list (yes/no)?";
  cin >> input;

  if (input == "yes")
  {
    for (int i = 0; i < n - 1; i++)
      cout << array[i] << " ";
  }
}
*/

//merge function 
void merge(int array[], int l, int m, int r)
{
   int n1 = m - l + 1;
   int n2 = r - m;

   int L[n1], R[n2];

   for(int i = 0; i < n1; i++)
   {
      mergeCount += 1; // counts each compare in for loop
      L[i] = array[l+i];
   }

   for(int j = 0; j < n2; j++)
   {
      mergeCount += 1; // counts each compare in for loop
      R[j] = array[m + 1 + j];
   } 

   int i = 0;

   int j = 0;

   int k = l;

   while(i < n1 && j < n2)
   {
      mergeCount += 2; // counts each compare in while loop and if statements 
      if(L[i] <= R[j])
      {
         array[k] = L[i];
         i++;
      }
      else
      {
         array[k] = R[j];
         j++;
     }
     k++;
   } 

   while(i < n1)
   {
      //mergeCount += 1; // counts each compare in while loop 
      array[k] = L[i];
      i++;
      k++;
   }

   while(j < n2)
   {
      //mergeCount += 1; // counts each compare in while loop
      array[k] = R[j];
      j++;
      k++;
   }
}


//mergsort fucntion page 59 in textbook
void mergeSort (int array[], int l, int r)
{  
   if(l < r)
   {  
      mergeSortCount += 1; // counts each compare in if statement
   
      int m = l + (r - l) / 2;
      mergeSort(array, l, m); 
      mergeSort(array, m + 1, r);
      merge(array, l, m, r);
   }
}
