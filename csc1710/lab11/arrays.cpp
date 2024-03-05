/*
Emma Jerrier
November 15th 2021
CSC1710
~/csc1710/lab11
description: we had to use functions to load in, print, sort, print again, and search an array. We also had to write a function to find the median of the array. We then printed out the minimum, maximum and median of the array. 
assisted by Mia Glenn and Troy Kubank
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//put my function prototypes
int loadArray(int a[]);
void printArray(int a[], int length);
void sortArray(int a[], int length);
double median(int a[], int length);
int SearchArray(int a[], int length, int searchItem);

int main ()
{
//declared variables needed and declared array
   int length, a[100], searchItem;
// reading in array
   length = loadArray(a);
// printing array, sorting array in ascending order, and re printing the sorted array
   printArray(a, length);
   sortArray(a, length);
   cout<<endl;
   printArray(a, length);
// Printing minimum, maximum, and median values for the array
   cout<<endl<<"Minimum: A[0]="<<a[0]<<endl;
// used a 2.0 to make a double if needed
   cout<<"Median: A["<<(length-1)/2.0<<"]="<<median(a, length)<<endl;
   cout<<"Maximum: A["<<length-1<<"]="<<a[length-1]<<endl;
   cout<<endl<<"Input the non-negative integer you'd like to search for:"<<endl;
   cin>>searchItem;
   SearchArray(a, length, searchItem);
   cout<<"Number of occurrences of the integer "<<searchItem<<": "<<SearchArray(a, length, searchItem)<<endl;
}

// This function is to get the user to input their file name and it opens the file, reads in the array, and then closes the file and returns the length of the array to the main program
int loadArray(int a[])
{
   int i=0;
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
   
   inFile>>a[i];


   while(a[i]!=-1)
   {
      i++;
      inFile>>a[i];
   }
   inFile.close();

   return i;
}

// This function passes the array and length in and prints out the array as it was read in      
void printArray(int a[], int length)
{
   int n = 0;
   while(n<=(length-1))
   {
      cout<<"A["<<n<<"]="<<a[n]<<endl;
      n++;
   }
}

// This function passes in the array and the length to sort it in ascending order (lowest to highest) 
void sortArray(int a[], int length)
{
   int index=0, smallest, i, temp;
   while(index<length-1)
   {
      smallest=index;
      i = index+1;
      while(i<length)
      {
         if(a[i]<a[smallest])
            smallest=i;
         i++;
      }
      if(index != smallest)
      {
         temp = a[smallest];
         a[smallest] = a[index];
         a[index] = temp;
      }
   index++;
   }
}        
// this function passes in the array and the length and finds the median value
double median(int a[], int length)
{

   double mid;
   if(length%2==0)
   {
// this is if the length is an even number and the median has to be an average between 2 values and I static cast it as a double so it doesn't truncate
      mid=static_cast<double>((a[(length-1)/2]+a[((length-1)/2)+1])/2.0);
   }
   else
   {
      mid=a[(length-1)/2];
   }

   return mid;
}

// this function passes in the array, the length, and the integer the user is searching for and counts the amount of times it occurs
int SearchArray(int a[], int length, int searchItem)
{
   int amount=0;
   for(int i = 0; i < length; i++)
   {
      if(a[i] == searchItem)
         amount++;
   }
   return amount;
} 





