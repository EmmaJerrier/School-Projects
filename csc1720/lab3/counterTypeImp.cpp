/*
Emma Jerrier
January 25th 2022
Class: CSC1720
Location ~/csc1720/lab3
About: This is the implementation file where the functions will live :)  

How to compile:
g++ -Wall counterType.cpp lab3test.cpp counterTypeImp.cpp -o Lab3

To execute the program:
./Lab3

Fun fact - cherophobia is an irrational fear of fun or happiness
*/

#include<iostream>
#include "counterType.h"

using namespace std;
// initializes to counter to 0
void counterType::initializeCounter()
{
   counter = 0;
}
// sets the counter to an integer value above 0 or defaults to 0
void counterType::setCounter(int a)
{
   if(a>=0)
      counter=a;
   else
      counter = 0;
}
// returns the counter to main
int counterType::getCounter()const
{
   return counter;
}
// increments the counter by 1
void counterType::incrementCounter()
{
      counter++;
}
// decrements only if it is greater than 0
void counterType::decrementCounter()
{
   if(counter>0)
      counter--;
}
// prints the counter
void counterType::displayCounter()const
{
   cout<<counter;
}
// the two constructors - overloaded 
counterType::counterType(int a)
{
   if(a>=0)
      counter = a;
   else
      counter=0;
}

counterType::counterType()
{
   counter = 0;
}
