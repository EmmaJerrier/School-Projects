/* 
By Emma Jerrier & Troy Kubanka
October 18th, 2022
CSC2342
ABOUT: 
*/
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

void inputArray(string arr[]);
void combineArray(string Arr1[], string Arr2[], string final[], int len1, int len2);
void intersectArray(string Arr1[], string Arr2[], string final[], int len1, int len2);

// declare 3 string arrays U, A, B
// make bit strings for each - max 32 bits (one unsigned int)

// find ~A, A union B, A intersect B, A-B, and A xor B

// use I/O redirection not prompts

int main()
{
   string U[32], A[32], B[32]; 
   int lenU, lenA, lenB, lenUnion, lenInter;
   unsigned int u, a, b, unionbit, intersectionbit;
   
   inputArray(U);
   inputArray(A);
   inputArray(B);  
   
   lenU=sizeof(U)/sizeof(U[0]);
   lenA=sizeof(A)/sizeof(A[0]);
   lenB=sizeof(B)/sizeof(B[0]);
    
   string Union[32], Intersection[32];
   combineArray(A, B, Union, lenA, lenB);
   intersectArray(A, B, Intersection, lenA, lenB);

// assign values to the bit strings 


   return 0;
}

void inputArray(string arr[])
{
   int i=0;
   string S, T;
   stringstream X(S);
   getline(cin, S);
   while(getline(X, T,' '))
   {
      arr[i]=T;
      i++;
   }
}

void combineArray(string Arr1[], string Arr2[], string final[], int len1, int len2)
{
   bool unique=true;
   int x;
   for(int i=0; i<len1; i++)
   {
      final[i]=Arr1[i];
      x=i;
   }
   for(int j=0; j<len2; j++)
   {
      unique=true;
      for(int k=0; k<len1; k++)
      {
         if(Arr2[j]==Arr1[k])
            unique=false;
      }
      if(unique==true)
      {
         final[x]=Arr2[j];
      }
   }
}

void intersectArray(string Arr1[], string Arr2[], string final[], int len1, int len2)
{
   int k=0;
   for(int i=0; i<len1; i++)
   {
      for(int j=0; j<len2; j++)
      {
         if(Arr1[i]==Arr2[j])
         {
            final[k]=Arr1[i];
            k++;
         }
      }
   }
}



