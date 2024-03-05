#include<iostream>

#include<cmath>
#include<iomanip>

using namespace std;

int main ()
{
   int i, PayNum, m;
   double PurPrice, Interest, IntPay, PrincipalPay, MonthlyInterest, exponent, PrincipalBal, PrincipalBal2, AnnualIntRate, MonthPayAmt;

   cout<<"Please input the purchase price: "<<endl;
   cin>>PurPrice;
   cout<<"Please input the Annual Interest Rate: "<<endl;
   cin>>AnnualIntRate;
   cout<<"Please input the number of monthly payments: "<<endl;
   cin>>PayNum;
//   cout<<"Please input the monthly payment amount: "<<endl;
//   cin>>MonthPayAmt;

   cout<<setw(11)<<"| Payment |"<<setw(11)<<" Interest |"<<setw(11)<<" Principal|"<<setw(11)<<" Principal|"<<endl;
   cout<<setw(11)<<"|  Number |"<<setw(11)<<"  Payment |"<<setw(11)<<"  Payment |"<<setw(11)<<"  Balance |"<<endl; 
 
   while(i<=44)
   {
      cout<<"-";
      i++;
   }
   cout<<endl;

   PrincipalBal=PurPrice;
   m=1;

   while(m<=PayNum)
   {
      cout<<fixed<<showpoint<<setprecision(2);
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
