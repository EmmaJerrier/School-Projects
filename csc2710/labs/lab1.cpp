/*

Author: Emma Jerrier
Date: September 11th 2022
Class: CSC2710
Path: ~/csc2710/labs 
To compile: g++ lab1.cpp
ABOUT: In this program we had to implement the algorithms for sequential search, exchange sort, binary search, a recursive fibonacci function, and an iterative fibonacci function. I also used a function to fill an array with 100 randomized numbers and one to print the array to show the before and after of the exchange sort. I also used counters in the sequential search and binary search to show how many compares there were and I used counters for both fibonacci functions to count the number of times two numbers have been added together a generate the final number.

*/

#include <iostream>
#include <iomanip>
using namespace std;
void fillArray(int s[], int size);
void print(int array[], int cnt);
void seqSearch(int n, const int s[], int obj, int& location, int& seqNum);
void exchangesort(int n, int s[]);
void binsearch(int n, const int s[], int x, int& binlocation, int& binNum);
int fib(int num, int& fib1counter);
int fib2(int num2, int& fib2counter);

int main()
{
// initialize an array, s 100
   int array[100];
   int obj, location, binlocation, obj2, num, num2;
   int seqNum, binNum, fib1counter=0, fib2counter=0;
   fillArray(array, 100);
// testing seq search
   cout<<"Input a number to search for: "<<endl;
   cin>>obj;
// idiot proofing
   while(obj<0)
   { cout<<"Invalid input, try again: ";
     cin>>obj;
   }
   cout<<endl;
   seqSearch(100, array, obj, location, seqNum);
   cout<<obj<<" is at location: "<<location<<endl;
   cout<<"Sequential Search compared "<<seqNum<<" times"<<endl;
// test exchange sort
   cout<<"Printing the unsorted array: ";
   print(array, 100);
   cout<<endl<<endl;
   exchangesort(100, array);    
   cout<<"Sorted the array with exchange sort and printing: ";
   print(array, 100);
   cout<<endl<<endl;
// do binary search next
   cout<<"Input a number to search for with a binary search: ";
   cin>>obj2;
   while(obj2<0)
   { cout<<"Invalid input, try again: ";
     cin>>obj2;
   }
   binsearch(100, array, obj2, binlocation, binNum);
   cout<<obj2<<" is at location: "<<binlocation<<endl;
   cout<<"Binary Search compared "<<binNum<<" times"<<endl<<endl;
// fibonacci recursive
   cout<<"Input what term in the Fibonacci sequence you'd like to find recursively: ";
   cin>>num;
   while(num<0)
   { cout<<"Invalid input, try again: ";
     cin>>num;
   }
   cout<<"The number "<<num<<" term in the sequence is "<<fib(num, fib1counter)<<endl;
   cout<<"Numbers were added together "<<fib1counter<<" times"<<endl<<endl;
// fibonacci iterative
   cout<<"Input what term in the Fibonacci sequence you'd like to find iteratively: ";
   cin>>num2;
   while(num2<0)
   { cout<<"Invalid input, try again: ";
     cin>>num2;
   }
   cout<<"The number "<<num2<<" term in the sequence is "<<fib2(num2, fib2counter)<<endl;
   cout<<"Numbers were added together "<<fib2counter<<" times"<<endl<<endl;

  return 0;
}
/*
fillArray - fills the array with randomized numbers up to 100, NOT SEEDED FOR TESTING PURPOSES
precondition: the array is passed in and the size 
postcondition: an array of a passed in size will be filled with randomized numbers
*/
void fillArray(int s[], int size)
{
//   srand(time(0));
   for(int i = 0; i<size; i++)
   {
      int num = rand()%100;
      s[i] = num;
   }
}
/*
print - this function prints the array 
precondition: the array and size are passed in 
postcondition: the array is output to the user but nothing is returned
*/
void print(int array[], int cnt)
{
   for(int i=0; i<cnt; i++)
      cout<<array[i]<<" ";
   cout<<endl;
}
/*
seqSearch - implementation of sequential search algorithm, goes through the array one by one to find the number
precondition: the size, array, and object are passed in and location and counter are both passed in by reference
postcondition: location and seqNum are both passed by reference to main 
*/
void seqSearch(int n, const int s[], int obj, int& location, int& seqNum)
{
   location=1;
   while(location<=n && s[location] != obj)
   {   location++;
       seqNum=location;
   }   
   if(location>n)
   {   location=0;
       seqNum = n;
   }
}
/*
exchangesort - this function sorts the array in nondecreasing order
precondition: size and array are passed in
postcondition: the array will be sorted in nondecreasing order
*/
void exchangesort(int n, int s[])
{
   int i, j, temp;
   for(i=0; i<=n; i++)
      for(j=i+1; j<=n; j++)
         if(s[j]<s[i])
         {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
         }
}
/*
binsearch - this function searches the array by splitting it in half over and over again until it finds the number
precondition: size, array, the object being searched for (x) are passed in and binlocation and binNum are passed in by reference
postcondition: binlocation and binNum are passed by reference to main
*/
void binsearch(int n, const int s[], int x, int& binlocation, int& binNum)
{
   int low, high, mid;
   low=0;
   high=n;
   binlocation=0;
   binNum=0;
   while(low<=high && binlocation==0)
   {
      mid = (low+high)/2;
      if(x==s[mid])
         binlocation=mid;
      else if (x<s[mid])
         high=mid-1;
      else
         low=mid+1;
      binNum++;
   }
}
/*
fib - this function uses recursion to find the nth term of the fibonacci sequence
precondition: the nth term (num), and the fib1counter are passed in
postcondition: it returns the nth term and the counter is passed by reference to main
*/
int fib(int num, int& fib1counter)
{  
   fib1counter++;
   if(num<=1)
   {  
      return num;
   }
   else
   {  
      return fib(num-1, fib1counter)+fib(num-2, fib1counter);
   }
}
/*
fib2 - this function iteratively finds the nth term of the fibonacci sequence
precondition: the nth term (num2), and the fib2counter are passed in
postcondition: it returns the nth term and the counter is passed by reference to main
*/
int fib2(int num2, int& fib2counter)
{
   int i;
   int f[num2];
   if(num2<=1)
   {
      fib2counter++;
      return num2;
   }
   else
   {
      for(i=2; i<=num2; i++)
      {  fib2counter++;
         f[i]=f[i-1]+f[i-2];
      }  
   }
   return f[num2];
}


