/*
Emma Jerrier
Feb 24, 2022
CSC1720
~/csc1720/lab6/lab6
ABOUT: in this lab we were given a base class and a derived class. the base class had multiple pure virtual functions. We had to write the implementation for 3 methods in the derived class, a removeAt, insertFirst, and a findMax. We also had to write a main program with documentation to test everything.
compile: g++ arrayListMain.cpp arrayListType.cpp unorderedArrayList
execute: ./a.out

thin mints are the best girl scout cookies
*/

#include<iostream>
#include "arrayListType.h"
#include "unorderedArrayListType.h"

using namespace std;

int main()
{
// declared 3 separate unordered array lists, one parameterized that works, one that doesnt, and a default one
   cout<<"Declared 3 lists, list1 with a size of 10, list2 with a size of -10 (will correct to 100), and list3 which will use the default constructor"<<endl<<endl;
   unorderedArrayListType list1(10);
   unorderedArrayListType list2(-10);
   unorderedArrayListType list3;
// testing insert, replace, remove, findMax, and print for list1
   cout<<"list1 is filled and should have 27,8,5,12,2,7,84,17,2,9 in that order, using the insertAt and insertEnd methods."<<endl;
   list1.insertAt(0, 27);
   list1.insertEnd(8);
   list1.insertAt(2, 5);
   list1.insertEnd(12); 
   list1.insertEnd(2);
   list1.insertAt(5, 7);
   list1.insertAt(6, 84);
   list1.insertAt(7, 17);
   list1.insertAt(8, 2);
   list1.insertEnd(9);
   
   cout<<"Printing list1 : ";
   list1.print();
   cout<<"Using the insertEnd function on a full list, should give error message"<<endl<<endl;
   list1.insertEnd(10);

   cout<<"Replacing the value at location [2] with 16."<<endl;
   list1.replaceAt(2, 16);   
   list1.print();
   cout<<"Replacing the value at location [11] with 10, shold give error message for out of range"<<endl<<endl;
   list1.replaceAt(11,10);

   cout<<"Running the removeAt method, will replace the location [5] with 9"<<endl;
   list1.removeAt(5);
   cout<<"printing again - expected output is 27,8,16,12,2,9,84,17,2."<<endl;
   list1.print();
   
   cout<<"Using the insertFirst method to input a 7 at the top, and the list should now be 7, 27, 8, 16, 12, 2, 9, 84, 17, 2."<<endl;
   list1.insertFirst(7);
   cout<<"Printing list1 : ";
   list1.print();  

   cout<<"Running the findMax function to find the highest value of list1, which should return 84"<<endl<<"Max = ";
   cout<<list1.findMax()<<endl;

   for(int j=0; j<=40; j++)
      cout<<"-";
   cout<<endl<<endl;
// testing insert, replace, remove, findMax, and print for list2
   cout<<"list2 is filled with 5 values and should have 7, -10, 17, 100, and 3 in that order, using the insertAt and insertEnd methods."<<endl;
   list2.insertAt(0, 7);
   list2.insertEnd(-10);
   list2.insertAt(2, 17);
   list2.insertEnd(100);
   list2.insertEnd(3);

   cout<<"Printing list2 : ";
   list2.print();
   
   cout<<"Running the removeAt function and will replace location [2] with 3"<<endl;
   list2.removeAt(2);
   cout<<"Running the replaceAt function at location [3] with 217"<<endl;
   list2.replaceAt(3, 217);
   cout<<"Printing again - expected output is 7, -10, 3, 217."<<endl;
   list2.print();
   cout<<"Using insertFirst to insert a 25 and printing."<<endl;
   list2.insertFirst(25);
   list2.print();
   cout<<"Running the findMax function which should return 217."<<endl<<"Max = ";
   cout<<list2.findMax()<<endl;

   for(int j=0; j<=40; j++)
      cout<<"-";
   cout<<endl<<endl;
// testing insert, replace, remove, findMax, and print for list3
   cout<<"list3 is filled with 8 values and should have 4, -10, 9, 10, 19, -2, 78, and 35 in that order, using the insertAt and insertEnd methods."<<endl;
   list3.insertAt(0, 4);
   list3.insertEnd(-10);
   list3.insertAt(2, 9);
   list3.insertEnd(10);
   list3.insertEnd(19);
   list3.insertEnd(-2);
   list3.insertEnd(78);
   list3.insertEnd(35);

   cout<<"Printing list3 : ";
   list3.print();

   cout<<"Running the removeAt function and will replace location [5] with 35"<<endl;
   list3.removeAt(5);
   cout<<"Running the replaceAt function at location [1] with 21"<<endl;
   list3.replaceAt(1, 21);
   cout<<"Printing again - expected output is 4, 21, 9, 10, 19, 35, 78."<<endl;
   list3.print();
   cout<<"Using insertFirst to insert a -8 and printing."<<endl;
   list3.insertFirst(-8);
   list3.print();
   cout<<"Running the findMax function which should return 217."<<endl<<"Max = ";
   cout<<list3.findMax()<<endl;

 
   return 0;
}
