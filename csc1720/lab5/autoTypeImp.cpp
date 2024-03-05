/*
Emma Jerrier
February 3rd 2022
CSC1720
~/csc1720/lab4
About: We created a header, implementation, and main file and defined, implemented and tested the class respectively. I defined multiple vehicles to test different values through. I defined 3 private values in the class and used the methods in the class to access them, modify them, and print them. We also narrated what we were doing throughout and I said what I was inputting and what I expected it to output/correct to.
compile: g++ -c autoTypeImp.cpp g++ autoMain.cpp autoTypeImp.o
run: ./a.out
resource: https://www.cplusplus.com/reference/string/to_string/
*/

#include <iostream>
// included string to be able to concatenate it :) and included the header so the class would be defined
#include <string>
#include "autoType.h"

using namespace std;

void autoType::setValues(double od, double fl, double fe)
{
   if(od>=0 && od<300000)
      odometer = od;
   else
      odometer = 0;
 
   if(fl>=0 && fl<200)
      fuelLev = fl;
   else
      fuelLev = 0;

   if(fe>=10 && fe<100)
      fuelEff = fe;
   else
      fuelEff = 10;
}

string autoType::createDash() const
{
   string output;
   output = "Odometer = " + to_string(odometer) + " miles, Fuel Level = " + to_string(fuelLev) + " gallons, Efficiency = " + to_string(fuelEff) + " miles per gallon,";
   return output;
}

void autoType::drive(double miles)
{
   double gallons;
   if(fuelEff>0)
      gallons = miles/fuelEff;
   else
      gallons = 0;
     
   if (gallons<fuelLev)
      fuelLev-=gallons;
   else
   {
      fuelLev=0;
      odometer+=(fuelEff*fuelLev);
   }
   if (fuelEff>0)
      odometer+=miles;  
}

autoType::autoType(double od, double fl, double fe)
{
   if(od>=0 && od<300000)
      odometer = od;
   else
      odometer = 100;

   if(fl>=0 && fl<200)
      fuelLev = fl;
   else
      fuelLev = 0;

   if(fe>=10 && fe<100)
      fuelEff = fe;
   else
      fuelEff = 10;
}

autoType::autoType()
{
   odometer = 100;
   fuelLev = 0;
   fuelEff = 10;
}
