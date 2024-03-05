#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include <string>

using namespace std;

void loadArray(string, int[], int);
void bubbleSort (int [], int);
void outputArray (int [], int);

//for determining time
timeval startTime, stopTime;
double start, stop, diff;

//max number of numbers in the list
int MAX = 10000;

//counts the number of times the for loop(s) were executed in 
int forCountBubbleSort = 0;
int ifCountBubbleSort = 0;





int main()
{

   int array[MAX], n, userArrayChoice, userSortChoice;
   string filename = "";

   cout << "Determine sorting method (type in number): " << endl;
   cout << "Selection Sort = 1" << endl << "Exchange Sort = 2" << endl;
   cout << "Bubble Sort = 3" << endl << "Insertion Sort = 4" << endl;
   cout << "Merge Sort = 5" << endl << "Quick Sort = 6" << endl;
   cout << "Heap Sort = 7" << endl;
   cin >> userSortChoice;


   cout << "To hardcode an array, enter 0. To enter a file, enter 1." << endl;
   cin >> userArrayChoice;

   cout << endl << endl;

   //runs program and functions necessary w/user hardcoding array
   if (userArrayChoice == 0)
   {
     cout << "How many numbers will be in your array?" << endl;
     cin >> n;

     int userArray[n];
     cout << endl << endl;

     cout << "Input the numbers in your array" << endl;
     for (int i = 0; i < n; i++)
        cin >> userArray[i];


     cout << endl << endl;


     if (userSortChoice == 3)
     {
       bubbleSort(userArray, n);
       cout << endl << endl;
       outputArray(userArray, n);
     }
   }


  
   //runs program and functions necessary w/user inputting a file
   if (userArrayChoice == 1)
   {
     cout << "Enter the name of the file with random numbers: ";
     cin >> filename;
     cout << endl << endl;
  

     ifstream my_file;
     
     my_file.open(filename);
     if(!my_file)
       cout << "No such file!";
     else 
     {     
       cout << endl << endl;
       cout << "Enter the number of random numbers (max = 10,000): ";
       cin >> n;
     }

     
     cout << endl << endl;


     if (userSortChoice == 3)
     {
       loadArray(filename, array, n);
       cout << endl << endl;
       bubbleSort(array, n);
       cout << endl << endl;
       outputArray(array, n);
     }
   }



return 0;
}





void loadArray(string filename, int array[], int n)
{

  ifstream my_file;
  my_file.open(filename);
  for (int i = 0; i < n; i++)
    my_file >> array[i];
  my_file.close();

}





void bubbleSort (int array[], int n)
{
  bool unSorted = true;
  gettimeofday(&startTime, NULL); //starts clock

  while (unSorted)
  {
    for (int i = 0; i < n; i++) //end of each for loop has the largest number at the end of the list (and then second last in the list, and so forth)
    {
      forCountBubbleSort += 1;
      unSorted = false; //if the list is already sorted before the first for loop finishes, this statement will stop the while loop so there are no unncessary operations
      for (int j = 0; j < n; j++)
      {
        forCountBubbleSort += 1;
        ifCountBubbleSort += 1;
        if (array[j] > array [j + 1]) //swaps if the item on the left side of the list is larger than the number on the right side of the list
        {
         unSorted = true;
         swap(array[j], array[j + 1]);
        }
      }
    }
  } 

  gettimeofday(&stopTime, NULL); //stops clock

  start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
  stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);

  diff = stop - start;

  cout << "Analyzing Bubble Sort: " << endl;
  cout << "n = " << n << endl;
  cout << "for loop operations: " << forCountBubbleSort << endl;
  cout << "if loop operations: " << ifCountBubbleSort << endl;
  cout << "Basic operations (overall): " << forCountBubbleSort + ifCountBubbleSort << endl;
  cout << "Time = " << setprecision(10) << diff << " seconds" << endl;
  cout << endl;
}





void outputArray(int array[], int n)
{
  string input;
  cout << "Output the sorted list (yes/no)?";
  cin >> input;

  if (input == "yes")
  {
    for (int i = 0; i < n; i++)
      cout << array[i] << " ";
  }
}
