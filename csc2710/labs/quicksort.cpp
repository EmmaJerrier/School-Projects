
using namespace std;
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//for determining time
timeval startTime, stopTime;
double start, stop, diff;

//max number of numbers in the list
int MAX = 10000;

//counts the number of times the for loop(s) were executed in
int quickSortCount = 0;

int partitionCount = 0;


void quickSort(int low, int high, int array[]);

void loadArray(string filename, int array[], int n);

void partion(int low, int high, int& pivotpoint, int array[]);


int main()
{

  int array[MAX];

  string fileName = "";

  cout << "Enter the name of the file you would like to use: \n";
  cin >> fileName;
  ifstream inFile;

  inFile.open(fileName);  
  loadArray(fileName, array, MAX);
//start time capture
  gettimeofday(&startTime, NULL);
//call quicksort
  quickSort(0,MAX, array);
//end time capture after quicksort runs
  gettimeofday(&stopTime, NULL);
//time calculations
  start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
  stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);
//calculate the difference
  diff = stop - start;
//outputs the data analysis of the algorithm
  cout << "Analyzing Quick Sort: " << endl;
  cout << "MAX = " << MAX << endl;
  cout << "Times Quick Sort was recursively called: " << quickSortCount << endl;
  cout << "Times partition was recursively called: " << partitionCount << endl;
  cout << "Time = " << setprecision(10) << diff << " seconds" << endl;
  cout << endl;

/*  for(int i =1; i <= MAX; i++)
    cout << array[i] << ", ";
  cout << endl;
//output array
*/
  return 0;
}

void quickSort(int low, int high, int array[])
{
  quickSortCount++;

  int pivotpoint;

  if (high>low)
  {
    partion(low, high, pivotpoint,array);
    quickSort(low, pivotpoint -1, array);
    quickSort(pivotpoint+1, high, array);
  }  
}

void partion(int low, int high, int& pivotpoint, int s[])
{

  partitionCount++;
  int i, j;

  int pivotitem;

  pivotitem = s[low];
//give j a value
  j = low;
//start the for loop of comparisons
  for(i=low+1; i<=high; i++)
  {
    if(s[i]<pivotitem)
    {
      j++;
      swap(s[i],s[j]);
    }

  }
//pivot is J
  pivotpoint =j;

//swap lowest and pivotpoint
  swap(s[low], s[pivotpoint]);
}

void loadArray(string filename, int array[], int n)
{

  ifstream inFile;
  inFile.open(filename);
  for (int i = 1; i <= n; i++)
    inFile >> array[i];
  inFile.close();

}

