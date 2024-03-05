/* SUBMITTED AGAIN TO ADD COMMENTS
Emma Jerrier
10/27/2021
Option B + Idiot Proofing
https://www.valuepenguin.com/mortgages/mortgage-payments-calculator
~/csc1710/programs/mortgageCBB.cpp
*/
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main ()
{
// I declared my variables, I originally just had letters but had to really specifiy my variables because I was getting confused
   int i, PayNum, m;
   double PurPrice, IntPay, PrincipalPay, exp, MonthlyInterest, PrincipalBal, AnnualIntRate, MonthPayAmt;

   cout<<"Please input the purchase price: "<<endl;
   cin>>PurPrice;
// Idiot proofed to make sure there were no negatives
   while(PurPrice<0)
   {
      cout<<"Invalid input. No Negatives! Please try again..."<<endl;
      cin>>PurPrice;
   }

   cout<<"Please input the Annual Interest Rate above 0 and below 100: "<<endl;
   cin>>AnnualIntRate;
// Idiot proofing to make sure it's a reasonable rate
   while(AnnualIntRate<=0 || AnnualIntRate>100)
   {
      cout<<"Invalid input. Please try again..."<<endl;
      cin>>AnnualIntRate;
   }

   cout<<"Please input the number of monthly payments above 0: "<<endl;
   cin>>PayNum;
// Idiot proofing
   while(PayNum<=0)
   {
      cout<<"Invalid input. Please try again..."<<endl;
      cin>>PayNum;
   }
// Did some important math that couldn't be put in the loop
   MonthlyInterest=(1/12.0)*(AnnualIntRate/100.00);
   exp=pow(1+MonthlyInterest,-PayNum);
   MonthPayAmt=MonthlyInterest*(PurPrice/(1-(exp)));

   cout<<fixed<<showpoint<<setprecision(2); 
// Table title and column titles 
   cout<<"Your monthly pay amount is $"<<MonthPayAmt<<endl<<endl;
   cout<<"-------------Your Mortgage Table------------"<<endl;

   cout<<setw(11)<<"| Payment |"<<setw(11)<<" Interest |"<<setw(11)<<" Principal|"<<setw(11)<<" Principal|"<<endl;
   cout<<setw(11)<<"|  Number |"<<setw(11)<<"  Payment |"<<setw(11)<<"  Payment |"<<setw(11)<<"  Balance |"<<endl; 
   cout<<setw(11)<<"|         |"<<setw(11)<<"    ($)   |"<<setw(11)<<"    ($)   |"<<setw(11)<<"    ($)   |"<<endl;
 
   while(i<=44)
   {
      cout<<"-";
      i++;
   }
   cout<<endl;

   PrincipalBal=PurPrice;
   m=1;
   cout<<fixed<<showpoint<<setprecision(2);
   cout<<setw(11)<<"0"<<setw(33)<<PurPrice<<endl; 
// Started my loop with m so I could make it count upwards to the Payment Number
// It took a lot of work to figure out all the math
   while(m<=PayNum)
   {
      cout<<setw(11)<<m;
      m++;
      IntPay=(1/12.0)*(AnnualIntRate/100.00)*PrincipalBal;
      PrincipalPay=MonthPayAmt-IntPay;
      PrincipalBal=PrincipalBal-PrincipalPay;  
      cout<<setw(11)<<IntPay;
      cout<<setw(11)<<PrincipalPay;
      cout<<setw(11)<<PrincipalBal<<endl;
    }

   return 0;

}
