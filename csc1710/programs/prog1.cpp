/*
Name: Emma Jerrier
Date: 9/27/2021
Path: ~/csc1710/programs
Description: Write a program that asks for a total number of seconds and then converts it to days, hours, minutes, and seconds
*/

#include <iostream>
using namespace std;

int main ()
{
// I ended up adding input2 and input3 for the math to use with the % to get however many seconds carry on 
   int input, days, input2, hours, input3, minutes, seconds;
   cout<<"Please input the amount of seconds, nothing more than 2147483647 seconds (with no commas please)"<<endl;
   cin>>input;
// I did the math below and did the original input divided by how many seconds are in a day, then I used a % to find out how many seconds are left over that carry on to the next category, and so on   
   days = input/86400;
   input2 = input%86400;
   hours = input2/3600;
   input3 = input2%3600;
   minutes = input3/60;
   seconds = input3%60;

   cout<<"Your output is "<<days<<" days, "<<hours<<" hours, "<<minutes<<" minutes, and "<<seconds<<" seconds."<<endl;

   return 0;
} 
