/* 
*/

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main ()
{

   int i;
   double PurPrice, AIR, PayNum, DPP, IP, PrincPay, PrincBal, PMI, MPA, MIR, DP, PrincAm;

   cout<<"Please input the purchase price: "<<endl;
   cin>>PurPrice;
   cout<<"Please input your annual interest rate: "<<endl;
   cin>>AIR;
   cout<<"Please input your number of payments: "<<endl;
   cin>>PayNum;
   cout<<"Please input your down payment percentage: "<<endl;
   cin>>DPP;

   cout<<fixed<<showpoint<<setprecision(3); 

   i=0;
   while(i<40)
   {
      cout<<"-";
      i++;
   }
   cout<<endl;

   while(PayNum>=0)
   {
      cout<<setw(8)<<PayNum;
      PayNum--;
      MIR=(AIR)/12;
      DP=PayNum*(DPP/100);
      PrincAm=PurPrice-DP;
      MPA=((MIR)*(PrincAm))/pow(1-(1+MIR),(-PayNum));
      PrincPay=PayNum-IP;
      PrincBal-=PrincBal-PrincPay;
      IP=((1.0/12)*(AIR))/PrincBal;
      cout<<setw(8)<<IP;
      cout<<setw(8)<<PrincPay;
      cout<<setw(8)<<PrincBal;
        
      if(DPP<20)
      {
         if(DPP>=0 && DPP<5)
            PMI=1.030;
         else if(DPP>=5 && DPP<10)
            PMI=0.875;
         else if(DPP>=10 && DPP<15)
            PMI=0.675;
         else if(DPP>=15 && DPP<20)
            PMI=0.375;
         cout<<setw(8)<<PMI<<endl;
      }
      else
         cout<<endl;
  }
  return 0;
}
