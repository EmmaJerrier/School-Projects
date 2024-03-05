//
//  BubbleTutorial.cpp
//  
// Sample for gdb tutorial
#include <iostream>
using namespace std;

void bubbleSort(int x[], int n);
void printArray(int x[], int n);

int main()
{
    int y[7]={67,45,97,23,51,18,40};
    int num = 7;
    bubbleSort(y,num);
    printArray(y,num);
    return 0;
}

void bubbleSort(int x[], int n)
{
   int i, j, temp;
   for(i=0; i<n; i++)
      for(j=0; j<10; j++)
         if(x[j] > x[j+1])
         {
            temp = x[j];
            x[j] = x[j+1];
            x[j+1] = temp;
         }
} 
void printArray(int x[], int n)
{
    for(int i=0; i<n; i++)
        cout << x[i] << endl;
    cout << x[10] << endl;
}
