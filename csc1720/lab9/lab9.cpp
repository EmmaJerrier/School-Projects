/*
Emma Jerrier
3/22/2022
CSC1720
~/csc1720/lab9
compile: g++ lab9.cpp
execute: ./a.out

about: in this lab, we created a function called "repower" to calculate exponents of user input numbers. we used a recursive function to do this. the code is also interactive so we had to prompt the user for the base and exponent and then calculate it and then also ask them if they would like to continue or not and allow them to continue for as long as they'd like

if you were on a starship, what position would you be? 
I'd want to be a navigator or science officer :) 
*/

#include <iostream>
#include <iomanip>

using namespace std;
/*
repower - this function will calculate what j to the power of k is, I used if elses for each of the cases, I had 2 base cases of when k is 0 or 1, and the other 2 general cases for if k is negative or if k is greater than 1 
precondition - j is passed in and must be a positive number and will be the base of the exponent and k is passed in and will be the exponent and can be a positive or negative integer
postcondition - if k is 0, it will return 1, if k is 1, it will return j, if k is greater than 1 it will return j to the power of k and if k is a negative it will return 1 over j to the power of k
*/
double repower(int j, int k);

int main()
{
// base and exponent
   int j, k;
// control for being able to run repeatedly
   string run;
   cout<<"Enter the base number, positives only: ";
   cin>>j;
   // while loop to make sure the base is positive
   while(j<0)
   {
      cout<<"Please enter a positive value for the base: ";
      cin>>j;
   }
   cout<<"Enter the exponent value: ";
   cin>>k;
   // warning for what happens when it overflows, so if this number is the answer it is evident to why
   cout<<"If value returned is 1410065408, then the value overflowed and was too big."<<endl;
   // calls the function
   cout<<"The value of "<<j<<" raised to the power of "<<k<<" is "<<repower(j,k)<<endl;
   // asks if they'd like to run again
   cout<<endl<<endl<<"Would you like to run this again? Please type yes or no: ";
   cin>>run;
   // starts the loop until they decide they don't want to run this again and type something other than "yes"
   while(run=="yes")
   {
      cout<<"Enter the base number, positives only: ";
   cin>>j;
   while(j<0)
   {
      cout<<"Please enter a positive value for the base: ";
      cin>>j;
   }
   cout<<"Enter the exponent value: ";
   cin>>k;
   cout<<"If value returned is 1410065408, then the value overflowed and was too big."<<endl;
   cout<<"The value of "<<j<<" raised to the power of "<<k<<" is "<<repower(j,k)<<endl;
   cout<<"Would you like to run this again? Please type yes or no: "; 
   cin>>run;
   }   

   return 0;
}

double repower(int j, int k)
{
// base case
   if(k==0)
      return 1;
// base case
   else if(k==1)
      return j;
// if it is greater than 1, recursive
   else if(k>1)
      return j*repower(j, k-1);
// if its negative, recursive, will switch the sign and run as if it's positive and then just return as a fraction
   else if(k<0)
      return (1/(repower(j,-k)));
}
