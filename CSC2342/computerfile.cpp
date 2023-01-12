/* 
By Emma Jerrier & Troy Kubanka
October 24th, 2022
CSC2342
ABOUT:This program we worked on implementing sets and bit strings and executing operations with the bit strings. I used functions to read in the 3 sets, to output the sets for each operation, to add the bit values to strings A, B, and U, and an extra function to calculate the A - B operation 
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

using namespace std;

// declaring a struct to hold universal set, set A, and set B
struct element
{
   string name;
   int bit;
};
/*
readUArray - reads in the universal set and assigns bit values to each element 
readArray - reads in sets a and b and compares them to the universal set to assign the correct bit values
bitOutput - takes the bit string and compares it with the universal set to output the values for the expression
bitAddition - adds the correct values to the unsigned ints for Universal set, set A, and set B
subtraction - this is used for the A-B expression where it compares the bit strings for A and B and if it is a 1 for A and a 0 for B then it would check the universal set and output the correct value
*/
void readUArray(element set[], int& count);
void readArray(element set[], element uset[], int ucount, int& count, unsigned int &A);
void bitOutput(element uset[], unsigned int C, int ucount);
void bitAddition(unsigned int &A, element set[], int ucount);
void subtraction(element uset[], unsigned int A, unsigned int B, int ucount);

int main()
{
// sizes for Universal set, set A, and set B respectively
  int i=0, j=0, k=0;
// universal set, set A, and set B
  element uset[32], aset[32], bset[32];
// bit values for all sets and operations   
  unsigned int U, A, B, C, D, Acomp, Axor; 
 
// reads in universal set
  readUArray(uset, i);
  cin.get(); // takes the '\n' 
// reads in set A and then set B
  readArray(aset, uset, i, j, A);
  cin.get(); // takes the '\n'
  readArray(bset, uset, i, k, B);
  
// creating bit strings for U, A, and B
  bitAddition(U, uset, i);
  bitAddition(A, aset, j);
  bitAddition(B, bset, k); 
// expressions for complement of A, A|B, A&B, and AxorB - couldn't do A-B simply in main so I built a function for it
  Acomp=~A;
  C=A|B;
  D=A&B;
  Axor = A^B;  

// outputting the values
  cout<<"U = {";
  for(int x=0; x<i; x++)
     cout<<uset[x].name<<" ";
  cout<<"}"<<endl;
  cout<<"A = {";
  bitOutput(uset, A, i);
  cout<<"}"<<endl;
  cout<<"B = {";
  bitOutput(uset, B, i);
  cout<<"}"<<endl;
  cout<<endl<<endl;
  cout<<"~A {";
  bitOutput(uset, Acomp, i);
  cout<<"}"<<endl;
  cout<<"A union B = {";
  bitOutput(uset, C, i);
  cout<<"}"<<endl;
  cout<<"A intersect B = {";
  bitOutput(uset, D, i);
  cout<<"}"<<endl;
  cout<<"A - B = {";
// function to do A-B
  subtraction(uset, A, B, i);
  cout<<"}"<<endl;
  cout<<"A xor B = {";
  bitOutput(uset, Axor, i);
  cout<<"}"<<endl;

         

 
  return 0;
}

// reads in Universal Array and assigns a bit value
void readUArray(element set[], int& count)
{
   int bit=1;
   do
   {
      cin>>set[count].name;
      set[count].bit=bit;
      bit=bit<<1;
      count++;
   }while(cin.peek()!='\n');
}

// reads in set A or B and uses the sequential search algorithm to compare set values with the universal set and assign bit values
void readArray(element set[], element uset[], int ucount,int& count, unsigned int &A)
{
   A=0;
   int loc;
 
   while(cin.peek()!='\n')
   {
      cin>>set[count].name;
// sequential search algorithm
      loc = 0;      
      while(loc<ucount && uset[loc].name!=set[count].name)
         loc++;
      if(loc>ucount)
         loc=(-1);
      if(loc>=0){
         set[count].bit=uset[loc].bit;}
      count++;
   }

}
// calculates the bit values for the 3 sets
void bitAddition(unsigned int &A, element set[], int ucount)
{
   for(int i=0; i<ucount; i++)
      A+=set[i].bit;
}

// outputs the bit string by comparing it with the universal set
void bitOutput(element uset[], unsigned int C, int ucount)
{
   int pow2 = 1;
   for(int i=0; i<ucount; i++){
      if((C&pow2)!=0)
         cout<<uset[i].name<<" ";
      pow2<<=1; 
   }
}

// executes the operation for A-B by comparing both strings with the universal set
void subtraction(element uset[], unsigned int A, unsigned int B, int ucount)
{
   int pow2=1;
   for(int i=0; i<ucount; i++){
      if(((A&pow2)!=0) && ((B&pow2)==0))
         cout<<uset[i].name<<" ";
      pow2<<=1;
   }
}  
