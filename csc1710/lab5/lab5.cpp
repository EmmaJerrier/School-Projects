/* 
Emma Jerrier
CSC1710
Assisted by Mia Glenn
~/csc1710/lab5
We had to practice using File I/O and if else statements
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main ()
{
   ifstream inFile;
   ofstream outFile;
   int coffeecups;
   string firstName, lastName, department;
   double MGSalary, MBonus, MBonus2, taxes, taxes2, paycheck, distrav, travtime, avgspeed, costpercup, sales;
// declared all my variables //
   inFile.open("inData.txt");

   if(inFile)
{
// I did not know I had to do inFile>> and all the variables so I got about a thousand errors but Marcus helped me figure that out and it solved all my problems //
inFile>>firstName>>lastName>>department>>MGSalary>>MBonus>>taxes>>distrav>>travtime>>coffeecups>>costpercup;
      outFile.open("outData.txt");
      outFile<<fixed<<showpoint<<setprecision(2);
// I set the precision to 2 because all of the decimals go to only 2 places rather than 6 //
      outFile<<"                                                                                    "<<endl;
      outFile<<"____________________________________________________________________________________"<<endl;
      outFile<<"                                                                                    "<<endl;     
      outFile<<"Name: "<<firstName<<" "<<lastName<<", Department: "<<department<<endl;
      outFile<<"Monthly Gross Salary: $"<<MGSalary<<", Monthly Bonus: "<<MBonus<<"%, Taxes: "<<taxes<<"%"<<endl;
// once it compiled and I used it the first time all my numbers were wrong because I didn't realize there was sneaky math in there so I had to go back in and insert the math for the paycheck, average speed, and sales amount //
      MBonus2 = (MBonus/100)*(MGSalary);
      taxes2 = (taxes/100)*(MGSalary+MBonus2);
      paycheck = MGSalary+MBonus2-taxes2; 
      outFile<<"Paycheck: $"<<paycheck<<endl;
      outFile<<"                                                                                    "<<endl;
      outFile<<"____________________________________________________________________________________"<<endl;
      outFile<<"                                                                                    "<<endl;
// I just added some spacers to try and spread it out and make it look nicer :) //
      outFile<<"Distance Traveled: "<<distrav<<" miles, Traveling Time: "<<travtime<<" hours"<<endl;
      avgspeed = distrav/travtime;
      outFile<<"Average Speed: "<<avgspeed<<" miles per hour"<<endl;
      outFile<<"                                                                                    "<<endl;
      outFile<<"____________________________________________________________________________________"<<endl;
      outFile<<"                                                                                    "<<endl;
      outFile<<"Number of Coffee Cups Sold: "<<coffeecups<<", Cost: $"<<costpercup<<" per cup"<<endl;
      sales = coffeecups*costpercup;
      outFile<<"Sales Amount = $"<<sales<<endl;
      outFile<<"                                                                                    "<<endl;
      outFile<<"____________________________________________________________________________________"<<endl;
      outFile<<"                                                                                    "<<endl;

      inFile.close();
      outFile.close();
}
   else
      cout<<"Input failure!"<<endl;

   return 0;
} 
