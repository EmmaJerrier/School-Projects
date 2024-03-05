/*
Emma Jerrier
January 25th 2022
Class: CSC1720
Location ~/csc1720/lab3
About: This is the header, which defines the counterType class  

How to compile:
g++ -Wall counterType.cpp lab3test.cpp counterTypeImp.cpp -o Lab3

To execute the program:
./Lab3
*/

#include<iostream>

using namespace std;

class counterType
{
public:
/*
initializeCounter - this function just initializes the counter to 0 at the start
Precondition: the value isn't initialized to a specific value and will initialize it to 0 and the user should theoretically be able to re-initialize it to 0 
Postcondition: it will initialize the counter to 0 so it is obviously functional to the user
*/
   void initializeCounter();
/*
setCounter - this sets the counter to an integer value defaulting to 0 if no vale is input
Precondition: this will change the counter for the variable from whatever it was initialized as to the integer value in the program
Postcondition: the counter will be set with a new value or will default to 0
*/
   void setCounter(int = 0);
/*
getCounter - this function will retrieve the counter number from the private value
Precondition: this will return the counter to the main program, no variables passed in
Postcondition: the counter will be returned to main
*/
   int getCounter()const;
/*
incrementCount - this program increments the counter by 1
Precondition: no variables are passed in, it will access the private value and increment it 
Postcondition: the private variable will be incremented by 1
*/
   void incrementCounter();
/*
decrementCounter - this function decrements the counter by 1
Precondition: no variables are passed in, it will access the private variable and decrement it
Postcondition: the private variable will be decremented by 1
*/
   void decrementCounter();
/*
displayCounter - this function will display the counter value 
Precondition: no variables passed in, it will access the private variable and print it
Postcondition: the variable wil be printed 
*/
   void displayCounter()const;
/*
counterType(int) - this is the constructor, it will start the counter at an integer value
Precondition: the counter will be started at a certain integer
Postcondition: the counter is set at a starting value
*/
   counterType(int);
/*
counterType() - this is the default constructor and will set it to 0
Precondition: the starts the counter at 0 if no integer value is input
Postcondition: the counter will be 0
*/
   counterType();

private:
// my private variable
   int counter;
};
