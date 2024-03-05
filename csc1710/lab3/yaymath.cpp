/* Name:Emma Jerrier
   Date:September 9th 2021
   Course:CSC1710
   Path:~/home/students/ejerrier/csc170/lab3
   Description: We had to evaluate multiple expressions on paper and then compare them to how the compiler did them, and had to write code to figure out how each of the expressions had to be written down in the code specifically. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
   int p=17,q=4,r=3;
   double j=3.00,k=5.0;
   cout<<"+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*+-*/+-*/+-*/"<<endl;
//I declared each of the values as either integers or doubles :) //
   cout<<showpoint;
   cout<<"p-q*r = "<<p-q*r<<endl;
   cout<<"p/r = "<<p/r<<endl;
   cout<<"p%r = "<<p%r<<endl;
   cout<<"p/q/r = "<<p/q/r<<endl;
   cout<<"q+r%p = "<<q+r%p<<endl;
   cout<<"q*j/p = "<<q*j/p<<endl;
   cout<<"p/q/j = "<<p/q/j<<endl;
   cout<<"p/j/q = "<<p/j/q<<endl;
   k/=r/q; 
//I got an error message the first time I did the line below this, because I tried to do k/=r/q and the computer definitely did not like that so I had to go back and redeclare K as the equation//
   cout<<"k/=r/q = "<<k<<endl;
   cout<<"j/(-q) = "<<j/(-q)<<endl;
   cout<<"The area of a triangle with a base of p and a height of r is "<<(.5)*p*r<<endl;
//For this one I wrote out the specific problem rather than just the formula just to make it more clear what specifically the equation was searching for since it was unique :) //
   cout<<"+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/"<<endl;
   cout<<"Why do Java programmers have to wear glasses?"<<endl;
   cout<<"Because they don't C#"<<endl;
   return 0;
} 
