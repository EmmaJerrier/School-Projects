/*
Emma Jerrier
February 13th 2022
CSC1720
~/csc1720/lab5
About: We created a header, implementation, and main file and defined, implemented and tested the class respectively. I defined multiple vehicles to test different values through. I defined 3 private values in the class and used the methods in the class to access them, modify them, and print them. We also narrated what we were doing throughout and I said what I was inputting and what I expected it to output/correct to. 
In the second part of the lab, we created a derived hybridType class and created new objects and used the new implementations throughout
compile: g++ -c autoTypeImp.cpp hybridTypeImp.cpp g++ autoMain.cpp autoTypeImp.o g++ hybridTypeImp.o
run: ./a.out
resource: https://www.cplusplus.com/reference/string/to_string/
*/

#include<iostream>
#include<string>
#include "autoType.h"
#include "hybridType.h"

using namespace std;

int main()
{
   autoType vehicle1(200,56,17.8);
   autoType vehicle2(376000,67,1);
   autoType vehicle3(200000,-17,12);
   autoType vehicle4;
   autoType vehicle5;
   hybridType Prius1;
   hybridType Prius2;
   hybridType Prius3;
   double od, fl, fe, miles;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;
// declaring and testing the 3 hybridType objects and outputting original values, the charge level, and charge efficiency, then setting charge level and charge efficiency. I tested high and low values through the 3 different objects
   cout<<"Declared 'Prius 1' and am testing using autoType's default constructor"<<endl;
   cout<<"Using the createDash method that was overridden in hybridType to output the values"<<endl;
   cout<<Prius1.createDash()<<endl<<endl;
   cout<<"Returning the charge level of Prius 1"<<endl;
   cout<<Prius1.getChargeLevel()<<endl<<endl;
   cout<<"Returning the charge efficiency of Prius 1"<<endl;
   cout<<Prius1.getChargeEfficiency()<<endl<<endl;
   cout<<"Setting the charge level to 80 percent on Prius 1"<<endl;
   Prius1.setChargeLevel(80);
   cout<<"Setting the charge efficiency to 2.6 on Prius1"<<endl;
   Prius1.setChargeEfficiency(2.6);
   cout<<"Returning the new charge level of Prius 1 : ";
   cout<<Prius1.getChargeLevel()<<endl;
   cout<<"Returning the new charge efficiency of Prius 1 : ";
   cout<<Prius1.getChargeEfficiency()<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;

cout<<"Declared 'Prius 2' and am testing using autoType's default constructor"<<endl;
   cout<<"Using the createDash method that was overridden in hybridType to output the values"<<endl;
   cout<<Prius1.createDash()<<endl<<endl;
   cout<<"Returning the charge level of Prius 2"<<endl;
   cout<<Prius1.getChargeLevel()<<endl<<endl;
   cout<<"Returning the charge efficiency of Prius 2"<<endl;
   cout<<Prius1.getChargeEfficiency()<<endl<<endl;
   cout<<"Setting the charge level to 200 percent on Prius 2"<<endl;
   Prius1.setChargeLevel(200);
   cout<<"Setting the charge efficiency to 7.34 on Prius 2"<<endl;
   Prius1.setChargeEfficiency(7.34);
   cout<<"Returning the new charge level of Prius 2 (should be 100) : ";
   cout<<Prius1.getChargeLevel()<<endl;
   cout<<"Returning the new charge efficiency of Prius 2 (should be 0.1) : ";
   cout<<Prius1.getChargeEfficiency()<<endl;
 
   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;

cout<<"Declared 'Prius 3' and am testing using autoType's default constructor"<<endl;
   cout<<"Using the createDash method that was overridden in hybridType to output the values"<<endl;
   cout<<Prius1.createDash()<<endl<<endl;
   cout<<"Returning the charge level of Prius 3"<<endl;
   cout<<Prius1.getChargeLevel()<<endl<<endl;
   cout<<"Returning the charge efficiency of Prius 3"<<endl;
   cout<<Prius1.getChargeEfficiency()<<endl<<endl;
   cout<<"Setting the charge level to -55 percent on Prius 3"<<endl;
   Prius1.setChargeLevel(-55);
   cout<<"Setting the charge efficiency to -1 on Prius 2"<<endl;
   Prius1.setChargeEfficiency(-1);
   cout<<"Returning the new charge level of Prius 2 (should be 0) : ";
   cout<<Prius1.getChargeLevel()<<endl;
   cout<<"Returning the new charge efficiency of Prius 2 (should be 0.1) : ";
   cout<<Prius1.getChargeEfficiency()<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;
// testing constructors and outputting them   
   cout<<"Testing the constructer with parameters for vehicle 1 - the values will be 200, 56, and 17.8"<<endl;
   cout<<vehicle1.createDash()<<endl<<endl;
   cout<<"Testing the constructer with parameters for vehicle 2 - the values will be 376000,67, and 1, they should correct to 100, 67, and 10"<<endl;
   cout<<vehicle2.createDash()<<endl<<endl;
   cout<<"Testing the constructer with the parameters for vehicle 3 - the values will be 200000, -17, and 12, it should correct to 200000, 0, and 12"<<endl;
   cout<<vehicle3.createDash()<<endl<<endl;
   cout<<"Testing the default constructer on vehicle 4 - values should be 100, 0, and 10"<<endl;
   cout<<vehicle4.createDash()<<endl<<endl;
   cout<<"Testing the default constructer on vehicle 5 - values should be 100, 0, and 10"<<endl;
   cout<<vehicle5.createDash()<<endl<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;
// setting the values for the 5 vehicles
   cout<<"set the values of the 1st vehicle to be 201.5, 10.31, and 29.40"<<endl<<endl;
   vehicle1.setValues(201.5, 10.31, 29.40);
   cout<<"set the values of the 2nd vehicle to be -101.9, 20.48, and 17.67, the first value should go to 100 and not be negative"<<endl<<endl;
   vehicle2.setValues(-101.9, 20.48, 17.67);
   cout<<"set the values of the 3rd vehicle to be 310000, 17.86, and -20.46, the first should go to 100 and the last value should go to 10 and not be negative"<<endl<<endl;
   vehicle3.setValues(310000, 17.86, -20.46);
   cout<<"set the values of the 4th vehicle to 123.45, 16.29, and 31.24"<<endl<<endl; 
   vehicle4.setValues(123.45, 16.29, 31.24);
   cout<<"set the values of the 5th vehicle to 375.89, 12.34, and 27.35"<<endl<<endl;
   vehicle5.setValues(375.89, 12.34, 27.35);

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;
// outputting the strings of values for each vehicle
   cout<<"prints vehicle 1's values, should be 201.5, 10.31, and 29.40"<<endl;
   cout<<vehicle1.createDash()<<endl<<endl;
   cout<<"prints vehicle 2's values, should be 0, 20.48, and 17.67"<<endl;
   cout<<vehicle2.createDash()<<endl<<endl;
   cout<<"prints vehicle 3's values, should be 178.9, 17.86, and 10"<<endl;
   cout<<vehicle3.createDash()<<endl<<endl;
   cout<<"prints vehicle 4's values, should be 123.45, 16.29, and 31.24"<<endl;
   cout<<vehicle4.createDash()<<endl<<endl;
   cout<<"prints vehicle 5's values, should be 375.89, 12.34, and 27.35"<<endl;
   cout<<vehicle5.createDash()<<endl<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;
// calls the drive method and modifies the values
   cout<<"vehicle 1 drives 20 miles"<<endl;
   vehicle1.drive(20);
   cout<<"Vehicle 1's updated values"<<endl;
   cout<<vehicle1.createDash()<<endl<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;

   cout<<"vehicle 2 drives 35 miles"<<endl;
   vehicle2.drive(35);
   cout<<"Vehicle 2's updated values"<<endl;
   cout<<vehicle2.createDash()<<endl<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;

   cout<<"vehicle 3 drives 16 miles"<<endl;
   vehicle3.drive(16);
   cout<<"Vehicle 3's updated values"<<endl;
   cout<<vehicle3.createDash()<<endl<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;

   cout<<"vehicle 4 drives 75 miles"<<endl;
   vehicle5.drive(75);
   cout<<"Vehicle 4's updated values"<<endl;
   cout<<vehicle4.createDash()<<endl<<endl;

   for(int i=0; i<=40; i++)
      cout<<"-";
   cout<<endl;

   cout<<"vehicle 5 drives 12.4 miles"<<endl;
   vehicle1.drive(12.4);
   cout<<"Vehicle 5's updated values"<<endl;
   cout<<vehicle5.createDash()<<endl<<endl;

   return 0;
}
