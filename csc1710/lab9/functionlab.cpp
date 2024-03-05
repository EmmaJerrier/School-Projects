/* 
Emma Jerrier
10/28/2021
~/csc1710/lab9/functionlab.cpp
Assisted by Dr. Titus and Troy Kubanka
We had to write code to take the first and last name of two members and how many boxes they sold each week for 5 weeks. We then had to write functions to add up the weeks, print out the information, and calculate the profit. 
*/
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// put in prototypes for the 3 functions
int updateSales(string, string);
void printInfo (string, string, int);
double profit (int);

int main ()
{
// declared my global variables
   string FirstName, LastName;
   int sales, whole=0, n=1;
   double total;
   
   while(n<=2)
   {
      cout<<"Enter the member's first name: "<<endl;
      cin>>FirstName;
      cout<<"Enter the member's last name: "<<endl;
      cin>>LastName; 
// This was my main issue when I was calling updateSales, I wasn't setting sales equal to the function
      sales=updateSales(FirstName, LastName);    
      printInfo(FirstName, LastName, sales);
      whole+=sales;
      n++;
   }
   cout<<"Total boxes sold by all members: "<<whole<<endl;
// This was the same issue as updateSales, I had to set total equal to the profit function so it would over write it
   total=profit(whole);
   cout<<"Total profit from band booster candy sales: $"<<total<<endl;
 
}
// Something is/was wrong with my math so I'm testing a bunch of different solutions out
// Nothing was wrong with my function in itself, I was just having issues calling it in my main
int updateSales(string FirstName, string LastName)
{
   int i=1, boxes=0, sales=0;
   sales=boxes;
   while(i<=5)
   {
      cout<<"How many boxes did "<<FirstName<<" "<<LastName<<" sell during week "<<i<<"?"<<endl;
      cin>>boxes;
      sales += boxes;
      i++;
   }
   
   return sales;
}
// I think the issue is with my printstatement because it is printing the wrong number for sales
// This was not the issue haha - just didn't assign sales the right value in main
void printInfo ( string FirstName, string LastName, int sales) 
{
   cout<<"Member Name: "<<FirstName<<" "<<LastName<<", Total Boxes Sold: "<<sales<<endl;
}

double profit (int whole)
{
   double priceper,total;
   cout<<"What is the profit the band makes per box?"<<endl;
   cin>>priceper;
   total=whole*priceper;

   return total;
} 
