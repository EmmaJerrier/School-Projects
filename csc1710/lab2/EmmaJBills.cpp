/*Name:Emma Jerrier
Date:9/2/2021
Course:CSC1710-02
Purpose:To add up a random amount of 1s, 5s, 10s,and 20s and to tell you the sum amount of your money
Pathing:~/csc1710/Lab2
Description:I set up a variable for each money amount and calculated how many dollars of 1s, 5s, 10s, and 20s you have and it adds them all up to tell you the total amount.
*/

#include <iostream>
using namespace std;

int main ()
{
   int bills1, product1, bills5, product5, bills10, product10, bills20, product20, sum;
   cout <<"Enter number of $1 bills"<< endl;
   cin >> bills1;
   product1 = bills1*1;
   cout <<"The product of "<<bills1<<"and 1 is "<<product1<< endl;
   cout <<"Enter number of $5 bills"<< endl;
   cin >> bills5;
   product5 = bills5*5;
   cout <<"The product of "<<bills5<<"and 5 is "<<product5<< endl;
   cout <<"Enter number of $10 bills"<< endl;
   cin >> bills10;
   product10 = bills10*10;
   cout <<"The product of "<<bills10<<"and 10 is "<<product10<< endl;
   cout <<"Enter number of $20 bills"<< endl;
   cin >> bills20;
   product20 = bills20*20;
   cout <<"The product of "<<bills20<<"and 20 is "<<product20<< endl;
   sum = product1+product5+product10+product20;
   cout <<"The total is "<<sum<< endl;

   return 0;
}
