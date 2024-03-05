/* 
Name: Emma Jerrier 
Date: 9/30/2021
Path:~/csc1710/lab6
Description:Write a program to determine whether a year is a leap year or not
Assisted: Marcus & Mia Glenn
Web Reference: https://earthsky.org/human-world/why-do-we-need-leap-years/
*/

#include <iostream>
using namespace std;

int main()
{
// declared variable and asked user for input
   int year, now=2021;
   cout<<"Please enter a year!"<<endl<<endl;
   cin>>year;

   if(year<1583)
      cout<<"Error!"<<year<<" was before adoption of the Gregorian calendar :("<<endl;

// this section with the years ending in 00 made me want to cry. Everything is fine now - I used nested if statements which made it work to figure out which years were divisible by 400
 
   else if(year%100==0 && year>=now)
      if(year%400==0)
         cout<<year<<" will be a leap year! Yay!"<<endl;
      else
         cout<<year<< "will not be a leap year, boo :("<<endl;
   else if(year%100==0 && year<now)
      if(year%400==0)
         cout<<year<<" was a leap year! Yay!"<<endl;
      else
         cout<<year<<" was not a leap year, boo :("<<endl;

// this section was fairly straight forward, I put these after the hundred ones so they wouldn't accidentally qualify and give a false output, and they worked really well

   else if(year%4==0 && year>=now)
      cout<<year<<" will be a leap year! Yay!"<<endl;
   else if(year%4==0 && year<now)
      cout<<year<<" was a leap year! Yay!"<<endl;
// I added this section below to just check for the current year and give an answer in present tense rather than past or future
   else if(year==now)
      if(year%4==0 || year%400==0)
         cout<<year<<"is a leap year! Yay!"<<endl;
      else
         cout<<year<<" is not a leap year, boo :("<<endl;
// this last section is just meant to catch the rest that didn't qualify as a leap year 
   else if(year>=now)
      cout<<year<<" will not be a leap year, boo :("<<endl;
   else if(year<now)
      cout<<year<<" was not a leap year, boo :("<<endl;
   cout<<endl<<"Fun fact about me! I have 8 dogs :)"<<endl; 
 
   return 0;

}
