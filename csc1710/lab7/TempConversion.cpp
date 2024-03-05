/* 
Emma Jerrier
Csc1710
October 7th 2021
Assisted by mia glenn
~/csc1710/lab7
https://www.convertworld.com/en/temperature/celsius/celsius-to-kelvin.html
https://www.convertworld.com/en/temperature/fahrenheit/fahrenheit-to-celsius.html
We had to write a program to convert fahrenheit to celsius and kelvin and format it into a table
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
// I declared my variables
   double f, c, k, end, incr, i;
// I asked the user for inputs for each section
   cout<<"Please input a starting value in Fahrenheit (the smaller one) with up to three decimals :"<<endl;
   cout<<"Make sure it is betwenn -2000000 and 2000000"<<endl;
   cin>>f;
   cout<<"Please input an end value in Fahrenheit (the greater value) with up to three decimals :"<<endl;
   cout<<"Make sure it is betwenn -2000000 and 2000000"<<endl;
   cin>>end;
   cout<<"Please input a positive increment value, with up to three decimals :"<<endl;
   cin>>incr;
   cout<<endl;
   cout<<"| Fahrenheit (°F) | Celsius (°C) |  Kelvin (K)  |"<<endl;
// I set the precision to 3 decimal points
   cout<<fixed<<showpoint<<setprecision(3); 
// Used a loop to format my dashes
   i=0;
   while(i<49)
   {
      cout<<"-";
      i++;
   }
 
   cout<<endl;
// I used my If statements to have output options if the user misbehaved and put in a value I didn't watch 
   if(f>= -2000000 && f<= 2000000)
   { 
      if(end>= -2000000 && end<= 2000000)
      {
         while(f<=end)
         {
// All my math and everything
            cout<<setw(18)<<f<<"|";
// I originally couldn't get an output for C because I was doing 5/9 and that truncated to 0
            c = (f-32)*(5.0/9);
            cout<<setw(14)<<c<<"|";
   
            k = c+273.15;
            cout<<setw(14)<<k<<"|"<<endl;
   
            f += incr;
         }
      }
      else
         cout<<"Invalid input. Try again."<<endl;
   }
   else
      cout<<"Invalid input. Try again."<<endl;

   return 0;
}
      
