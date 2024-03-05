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
#ifndef autoType_H
#define autoType_H
using namespace std;


class autoType
{
public:
/*
setValues - this method sets the values for the vehicle to whatever I decided them as, because it was NOT interactive. I used if elses to make sure all the values were reasonable for the variables
Precondition: the local variables for the odometer, fuel level, and fuel efficiency are passed in and have already been selected. 
Postcondition: The three values passed in would have been assigned to the private values, or the 'failsafe' values would have been assigned.The values will be tested to make sure they're reasonable, and then will be assigned to the private values fro odometer, fuel level, and fuel efficiency

*/
   void setValues(double od, double fl, double fe);
/*
createDash - this method concatenates the output into one string. I had to use the to_string function to be able to add in the double values without it messing up the string. then the string value is returned to the main program. :)
Precondition: Nothing is passed in, but the method accesses the private values that have already been initialized and will return them in a string. 
Postcondition: the output string will be returned to main including the private values. It will use the to_string function to add them into the string that will be returned
*/
   string createDash() const;
/*
drive - this method 'drives' the car a set amount of miles which is passed in from main and modifies each of the private variables accordingly. So the odometer should increase the number of miles traveled and the fuel level will decrease the amount that they would burn (miles divided by fuel efficiency). 
Precondition: the number of miles is passed in and will be used to calculate the amount of gallons spent and will modify the fuel level and the odometer. 
Postcondition: the private variables will be accessed and the fuel level and odometer will be modified
*/
   void drive(double miles);
/*
autoType - This method is the first constructor that uses set values when the object is declared and will test the values and either use the set ones or the 'failsafe' values to assign it to the private variables. I also used if else's to ensure that the values were reasonable and not anything that didn't make sense
Precondition: 3 variables are passed in that will be assigned to the private values for each object after being tested to make sure they're not weird
Postcondition: the private variables will be accessed and modified to new values for the objects
*/  
   autoType(double od, double fl, double fe);
/*
autoType (default) - this is the default constructor so it will just set the object to what I decided as the 'default' values for each of the private variables.
Precondition: nothing is passed in but the private variables will be accessed and changed into new values
Postcondition: the private variables will be modified to 100, 0, and 10 respectively 
*/
   autoType();

private:
   double odometer;
   double fuelLev;
   double fuelEff;
};
#endif
