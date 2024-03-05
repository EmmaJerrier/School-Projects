/*
Emma Jerrier
February 13th 2022
CSC1720
~/csc1720/lab5
About: We created a header, implementation, and main file and defined, implemented and tested the class respectively. I defined multiple vehicles to test different values through. I defined 3 private values in the class and used the methods in the class to access them, modify them, and print them. We also narrated what we were doing throughout and I said what I was inputting and what I expected it to output/correct to. 
In the second part of the lab, we created a derived hybridType class and created new objects and used the new implemen
tations throughout
compile: g++ -c autoTypeImp.cpp hybridTypeImp.cpp g++ autoMain.cpp autoTypeImp.o g++ hybridTypeImp.o
run: ./a.out
resource: https://www.cplusplus.com/reference/string/to_string/
*/

#include<iostream>
#include"autoType.h"
#include"hybridType.h"
#include<string>
using namespace std;

void hybridType :: setChargeLevel(double cL)
{
   if(cL>=0 && cL<=100)
      charge = cL;
   else if(cL<0)
      charge = 0;
   else if(cL>100)
      charge = 100;
}

double hybridType :: getChargeLevel()
{
   return charge;
}

void hybridType :: setChargeEfficiency(double cE)
{
   if(cE>=0.1  && cE<=5)
      charEff = cE;
   else
      charEff=0.1;
}

double hybridType :: getChargeEfficiency()
{
   return charEff;

}

string hybridType :: createDash() const
{
   string newoutput, output;
   output = autoType::createDash();
   newoutput= output+" Charge Level = "+to_string(charge)+"%, Charge Efficiency = "+to_string(charEff)+" miles per percent charged.";
   return newoutput;
}
