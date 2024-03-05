/*
Emma Jerrier
February 3rd 2022
CSC1720
~/csc1720/lab4
About: We created a header, implementation, and main file and defined, implemented and tested the class respectively. I defined multiple vehicles to test different values through. I defined 3 private values in the class and used the methods
 in the class to access them, modify them, and print them. We also narrated what
 we were doing throughout and I said what I was inputting and what I expected it
 to output/correct to.
compile: g++ -c autoTypeImp.cpp g++ autoMain.cpp autoTypeImp.o
run: ./a.out
resource: https://www.cplusplus.com/reference/string/to_string/
*/
#include<iostream>
#include<string>

using namespace std;


class autoType
{
public:
   void setValues(double od, double fl, double fe);
   string createDash();
   void drive(double miles);
   autoType(double od, double fl, double fe);
   autoType();

private:
   double odometer;
   double fuelLev;
   double fuelEff;
};

