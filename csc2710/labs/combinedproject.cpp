/*
Author: Emma, Hanna, Landon, Isabella, Ky, Eli
Class: CSC2710
Due Date: October 7, 2022
Group Project - Combined main program

To compile: g++ combinedproject.cpp

To execute: ./a.out
*/

#include<iostream>
#include<cmath>
#include<iomanip>
#include <fstream>
#include <sys/time.h>
#include <string>

using namespace std;

void loadArray(string, int[], int);
void outputArray(int [], int);
//Hanna bubble sort
void bubbleSort(int [], int);
// Emma selection and exchange sorts
void exchangesort(int n, int s[]);
void selectionsort(int n, int s[]);
// Isabella insertion sort
void insertionSort(int S[], int length);
// Landon quicksort
void quickSort(int low, int high, int array[]);
void partion(int low, int high, int& pivotpoint, int array[]);
// ky merge sort
void merge(int array[], int l, int m, int r);
void mergeSort(int array[], int l, int r);
// eli heap sort
struct heap
{
int heapsize;
int S[10000];
};
void siftDown(heap& H, int i, int maxnum);
int root(heap& heap, int maxnum);
void removeKeys(int n, heap& H, int S[], int maxnum);
void makeHeap(int n, heap& heap, int maxnum);
void heapSort(int n, heap& H, int S[], int maxnum);

//for determining time
timeval startTime, stopTime;
double start, stop, diff;

//max number of numbers in the list
int MAX = 10000;

//bubble
int forCountBubbleSort = 0;
int ifCountBubbleSort = 0;
//select and exchange
int exchangeSwap=0;
int exchangeComp=0;
int selectSwap=0;
int selectComp=0;
//quick
int quickSortCount = 0;
int partitionCount = 0;
//merge
int mergeSortCount = 0;
int mergeCount = 0;
//heap
int comparecounter = 0;

int main()
{
// declaring variables for the users choice of sort (1-7), length, and if they choose to hardcode an array (array[MAX]) or read in a file (userArrayChoice), and a string for the filename
   int array[MAX], n, userArrayChoice, userSortChoice;
   string filename = "";
// giving the user a choice of which sort they want to test
   cout << "Determine sorting method (type in number): " << endl;
   cout << "Selection Sort = 1" << endl << "Exchange Sort = 2" << endl;
   cout << "Bubble Sort = 3" << endl << "Insertion Sort = 4" << endl;
   cout << "Merge Sort = 5" << endl << "Quick Sort = 6" << endl;
   cout << "Heap Sort = 7" << endl;
   cin >> userSortChoice;

// giving the user a choice to hardcode an array or read in a file
   cout << "To hardcode an array, enter 0. To enter a file, enter 1." << endl;
   cin >> userArrayChoice;

   cout << endl << endl;

   //runs program and functions necessary w/ user hardcoding array
   if (userArrayChoice == 0)
   {
     cout << "How many numbers will be in your array?" << endl;
     cin >> n;

     int userArray[n];
     cout << endl << endl;
// for loop to read in values for hardcoded array
     cout << "Input the numbers in your array" << endl;
     for (int i = 0; i < n; i++)
        cin >> userArray[i];

     cout << endl << endl;

//selection
     if(userSortChoice == 1)
     {
        selectionsort(n, userArray);
        cout<<endl<<endl;
        outputArray(userArray, n);
     }
//exchange
     if(userSortChoice == 2)
     {
        exchangesort(n, userArray);
        cout<<endl<<endl;
        outputArray(userArray, n);
     }
// bubble sort
     if (userSortChoice == 3)
     {
       bubbleSort(userArray, n);
       cout << endl << endl;
       outputArray(userArray, n);
     }
// insertion
    if(userSortChoice == 4)
    {
       insertionSort(userArray, n);
       cout<<endl<<endl;
       outputArray(userArray, n);
    }
//merge sort
    if(userSortChoice == 5)
    {
      gettimeofday(&startTime, NULL);
      mergeSort(userArray, 0, n-1);
      gettimeofday(&stopTime, NULL);
      start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
      stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);
      diff = stop - start;
      cout<<"Analyzing Merge Sort: "<<endl;
      cout<<"n = "<<n<<endl;
      cout<<"Times Merge Sort was called: "<<mergeSortCount<<endl;
      cout<<"Times Merge was called: "<<mergeCount<<endl;
      cout<<"Time = "<< setprecision(10) << diff << " seconds"<<endl;
      cout<<endl<<endl;
      outputArray(userArray, n);
    }
//quicksort
    if(userSortChoice == 6)
    {
       //start time capture
       gettimeofday(&startTime, NULL);
       //call quicksort
       quickSort(0, n, userArray);
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
       cout << endl << endl;
       outputArray(userArray, n);
    }
//heap sort
    if(userSortChoice == 7)
    {
       struct heap H = {n};
       int heapArray[n];
       for(int i=0; i<n; i++)
       {
       H.S[i]=userArray[i];
       }
        gettimeofday(&startTime, NULL);
        heapSort(n-1, H, heapArray, n);
        gettimeofday(&stopTime, NULL);
        start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
        stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);
        diff = stop - start;
        cout<<"Analyzing Heap Sort: "<<endl;
        cout<<"n = "<<n<<endl;
        cout<<"Times Heap Sort Compared Numbers: "<<comparecounter<<endl; 
        cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
        cout<<endl<<endl;
        string input;
        cout << "Output the sorted list (yes/no)?";
        cin >> input;

        if (input == "yes")
        {
           for (int i = 0; i < n; i++)
           cout << H.S[i] << " ";
        }
    }
  }

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
//selection
    if(userSortChoice == 1)
    {
       loadArray(filename, array, n);
       cout<<endl<<endl;
       selectionsort(n, array);
       cout<<endl<<endl;
       outputArray(array,n);
    }
//exchange
    if(userSortChoice == 2)
    {
       loadArray(filename, array, n);
       cout<<endl<<endl;
       exchangesort(n, array);
       cout<<endl<<endl;
       outputArray(array,n);
    }
//bubble
     if (userSortChoice == 3)
     {
       loadArray(filename, array, n);
       cout << endl << endl;
       bubbleSort(array, n);
       cout << endl << endl;
       outputArray(array, n);
     }
//insertion
    if(userSortChoice == 4)
    { 
       loadArray(filename, array, n);
       cout<<endl<<endl;
       insertionSort(array, n);
       cout<<endl<<endl;
       outputArray(array, n);
    }
//merge
   if(userSortChoice == 5)
   {
      loadArray(filename, array, n);
      cout<<endl<<endl;
      gettimeofday(&startTime, NULL);
      mergeSort(array, 0, n-1);
      gettimeofday(&stopTime, NULL);
      start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
      stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);
      diff = stop - start;
      cout<<"Analyzing Merge Sort: "<<endl;
      cout<<"n = "<<n<<endl;
      cout<<"Times Merge Sort was called: "<<mergeSortCount<<endl;
      cout<<"Times Merge was called: "<<mergeCount<<endl;
      cout<<"Time = "<< setprecision(10) << diff << " seconds"<<endl;
      cout<<endl<<endl;
      outputArray(array, n);
   }
//quick   
   if(userSortChoice == 6)
   {
      loadArray(filename, array, n);
      cout<<endl<<endl;
      gettimeofday(&startTime, NULL);
      quickSort(0, n, array);
      gettimeofday(&stopTime, NULL);
      start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
      stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);
      diff = stop - start;
      cout << "Analyzing Quick Sort: " << endl;
      cout << "MAX = " << MAX << endl;
      cout << "Times Quick Sort was recursively called: " << quickSortCount << endl;
      cout << "Times partition was recursively called: " << partitionCount << endl;
      cout << "Time = " << setprecision(10) << diff << " seconds" << endl;
      cout << endl << endl;
      outputArray(array, n);
   }
//heap
   if(userSortChoice == 7)
   {
      struct heap H = {n};
      int heapArray[n];
      ifstream my_file;
      my_file.open(filename);
      for(int i=0; i<n; i++)
      {
         my_file>>H.S[i];
      }   
      my_file.close();
      gettimeofday(&startTime, NULL);
      heapSort(n-1, H, heapArray, n);
      gettimeofday(&stopTime, NULL);
      start = startTime.tv_sec + (startTime.tv_usec/1000000.0);
      stop = stopTime.tv_sec + (stopTime.tv_usec/1000000.0);
      diff = stop - start;
      cout<<"Analyzing Heap Sort: "<<endl;
      cout<<"n = "<<n<<endl;
      cout<<"Times Heap Sort Compared Numbers: "<<comparecounter<<endl;
      cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
      cout<<endl<<endl;
      string input;
      cout << "Output the sorted list (yes/no)?";
      cin >> input;

      if (input == "yes")
      {
         for (int i = 0; i < n; i++)
         cout << H.S[i] << " ";
      }
         
   }
  }

return 0;

}
// loads in an array from a given filename and size
void loadArray(string filename, int array[], int n)
{

  ifstream my_file;
  my_file.open(filename);
  for (int i = 0; i < n; i++)
    my_file >> array[i];
  my_file.close();

}
// gives the user the option to output the sorted list
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

void exchangesort(int n, int s[])
{
// declaring variables
   int i, j, temp;
   bool notSorted = true; // added boolean flag similar to bubble sort to stop if the array is fully sorted, this helps mostly in circumstances where the array is almost sorted
   gettimeofday(&startTime, NULL); // starts clock
   while(notSorted)
   {
      for(i=0; i<=n; i++){
         exchangeComp+=1;
         notSorted=false;// if the list is already sorted this will break it out of the while loop
         for(j=i+1; j<=n; j++){
// made it +=2 because that way it will always count the if as a comparison rather than only if the if statement executes
            exchangeComp+=2;
            if(s[j]<s[i]){
               swap(s[i], s[j]); // this swaps the two values and moves them closer to where they belong
               exchangeSwap+=1;
               notSorted=true;}
         }
      }
   }
   gettimeofday(&stopTime, NULL); // stops clock
   start = startTime.tv_sec + (startTime.tv_usec/10000000.0);
   stop = stopTime.tv_sec + (stopTime.tv_usec/10000000.0);
   diff = stop - start;

   cout<<"Analyzing Exchange Sort: "<<endl;
   cout<<"n = "<<n<<endl;
   cout<<"Number of swaps: "<<exchangeSwap<<endl;
   cout<<"Basic operations: "<<exchangeComp<<endl;
   cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
   cout<<endl;
}

void selectionsort(int n, int s[])
{
   int i,j,smallest;

   gettimeofday(&startTime, NULL); //starts clock

   for(i=0; i<=n-1; i++)
   {
      selectComp+=1;
      smallest=i;
      for(j=i+1; j<=n; j++){
// made it +=2 because that way it will always count the if as a comparison rather than only if the if statement executes
         selectComp+=2;
         if(s[j]<s[smallest]){
            smallest=j;
         }
      }
      swap(s[i],s[smallest]);
      selectSwap++;// increments swap counter - there will always be n number of swaps because even if it's already in the lowest position it will swap with itself
   }

   gettimeofday(&stopTime, NULL); //stops clock
   start = startTime.tv_sec + (startTime.tv_usec/10000000.0);
   stop = stopTime.tv_sec + (stopTime.tv_usec/10000000.0);
   diff = stop - start;

   cout<<"Analyzing Selection Sort: "<<endl;
   cout<<"n = "<<n<<endl;
   cout<<"Number of swaps: "<<selectSwap<<endl;
   cout<<"Basic operations: "<<selectComp<<endl;
   cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
   cout<<endl;
}

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

    // outputing elements of the array - no longer necessary because we added an output function in our combined program
//    for(int i = 0; i<length; i++)
//    {
//       cout<<S[i]<<" ";
//    }
    // outputing counter and time
    cout<<"Analyzing Insertion Sort: "<<endl;
    cout<<"n = "<<length<<endl;
    cout<<"\nCounter = "<<counter<<endl;
    cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
 
}

void quickSort(int low, int high, int array[])
{
  quickSortCount++;

  int pivotpoint;

  if (high>low)
  { // calls partition and left and right quicksorts
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
// give j a value
  j = low;
//  start the for loop of comparisons
  for(i=low+1; i<=high; i++)
  {
    if(s[i]<pivotitem)
    {
      j++;
      swap(s[i],s[j]);
    }

  }
//ppivot is J
  pivotpoint =j;
//swap lowest and pivotpoint
  swap(s[low], s[pivotpoint]);
}

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

// heap functions
void siftDown(heap& H, int i, int maxnum)
{
        int parent = i;
        int bigChild;
        int siftkey = H.S[i];
        bool found = false;

        //siftkey = H.S[i];
        //parent = i;
        //found = false;

        while (parent*2 <= H.heapsize && !found)
        {
                comparecounter++;
                if (parent*2 < H.heapsize && H.S[parent*2] < H.S[parent*2+1])
                        {bigChild = parent*2 + 1;}
                else
                        {bigChild = parent*2;}

                comparecounter++;
                if (siftkey < H.S[bigChild])
                        {
                        H.S[parent] = H.S[bigChild];
                        parent = bigChild;

                        /*cout << "this is step " << comparecounter << ": ";
                        for (int i = 0; i<maxnum; i++)
                                {
                                        cout << H.S[i] << " ";
                                }
                        cout << endl << endl;
                        */

                        /*cout << "this is the parent: " << parent << endl;
                        cout << "this is at parent: " << H.S[parent] << endl;
                        cout << "this is at bigchild: " << H.S[bigChild] << endl;
                        cout << "this is the bigChild: " << bigChild << endl;
                        cout << "this is the siftkey: " << siftkey << endl;
                        cout << "I have swapped " << swapcounter << " times" << endl << endl;
                        cout << "I got here";*/
                        }
                else
                        found = true;
        }
        H.S[parent] = siftkey;
}
int root(heap& H, int maxnum)
{
        int keyOut;
        //int size = H.heapsize;

        keyOut = H.S[0];
        H.S[0] = H.S[H.heapsize];
        H.heapsize = H.heapsize - 1;
        //H.heapsize--;
        siftDown(H,0, maxnum);
        return keyOut;
}

void removeKeys(int n, heap& H, int S[], int maxnum)
{
        for (int i = n; i >= 0; i--)
                {S[i] = root(H, maxnum);}
}

void makeHeap(int n, heap& H, int maxnum)
{
        H.heapsize = n;
        for (int i=floor(n/2); i>= 0; i--)
                {siftDown(H, i, maxnum);}
}

void heapSort (int n, heap& H, int S[], int maxnum)
{
        makeHeap(n, H, maxnum);
        removeKeys(n, H, H.S, maxnum);
}
                   














