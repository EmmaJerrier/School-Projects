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
#ifndef hybridType_H
#define hybridType_H
#include "autoType.h"
#include<iostream>
using namespace std;

class hybridType : public autoType
{
public:
/*
setChargeLevel - this function sets the private charge value as a number between 0 and 100 ( because it's a percent ) and tests to make sure it isn't less than 0 or more than 100 
Precondition - A double is passed in, and the private value for charge will be accessed and assigned the value of the variable that was passed in
Postcondition - The private value for charge is set to a new value and will be validated to make sure it's in the acceptable range
*/
   void setChargeLevel(double);
/*
getChargeLevel - this function returns the private variable for charge level to the main program 
Precondition: Nothing is passed in but the private variable for charge level is accessed and will return it as a double to main
Postcondition: the charge level will be reuturned to main as a double  
*/
   double getChargeLevel();
/*
setChargeEfficiency - this function sets the private charge efficiency as a value between 0 and 5, as it is going to be a decimal value because it is the max range of the electric battery divided by 100
Precondition: A double is passed in and the private value for charge efficiency will be accessed and assigned the the value of the variable that was passed in
Postcondition: The private value for charge efficiency is set to a new value and will be validated to make sure it's in the acceptable range
*/
   void setChargeEfficiency(double);
/*
getChargeEfficiency - this function returns the private variable for charge efficiency to the main program
Precondition: Nothing is passed in but the private variable for charge efficiency is accessed and will return it as a double to main
Postcondition: the charge efficiency will be returned to main as a double
*/
   double getChargeEfficiency();
/*
createDash - this function overrides the createDash in autotype and prints the variables from autotype and then will append the two private variables in hybrid type to the string
Precondition: Nothing is passed in, but the method accesses the private values that have already been initialized and will return them in a string. It also calls the createDash in autoType and accesses the private values from the base class
Postcondition: the output string will be returned to main including the private values. It will use the to_string function to add them into the string that will be returned
*/
   string createDash() const;
private:
   double charge;
   double charEff;
};
#endif
