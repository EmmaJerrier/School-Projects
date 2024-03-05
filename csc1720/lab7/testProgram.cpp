/*
Emma Jerrier
March 11th 2022
~/csc1720/lab7
compile: g++ testProgram.cpp uniqueListType.cpp unorderedArrayListType.cpp arrayListType.cpp
execute: ./a.out<names.txt
ABOUT: in this lab we were given the ArrayListType and UnorderedArrayListType implementation and header files, and had to convert them from ints to strings and we also had to create a new class from the unordered list type called unique list type which meant that there were no repeats of names through the list. I overrode the constructor, the insertAt, the insertEnd, and the replaceAt methods because the final 3 have to be tested for repeats within the list. The main program uses a load function as well to load the file with I/O redirection and tests all the overloaded functions
*/

#include<iostream>
#include<string>
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "uniqueListType.h"

using namespace std;

/*
load - this function will read in the list through I/O redirection until EOF or the list is full
precondition: the list is passed in by reference and will be filled
postcondition: the list will be loaded from the file
*/
void load(unorderedArrayListType &list1);

int main()
{
   uniqueListType list1(16);
   cout<<"Created an unique list type, size 20, loading and printing."<<endl;
   load(list1);
   list1.print();

   cout<<endl<<"In list1 I'm replacing the name Emma at the 5th position and printing."<<endl;
   list1.replaceAt(4, "Emma");
   list1.print();
   
   cout<<endl<<"In list1 I'm replacing the name Snoopy into the 3rd position and printing. It should fail because the name is already in the list."<<endl;
   list1.replaceAt(2, "Snoopy");
   list1.print();   

   cout<<endl<<"In list1, I'm adding the name Jay at the end and printing which will fail because it's full."<<endl;
   list1.insertEnd("Jay");
   list1.print();
   
   cout<<endl<<"In list1 I'm deleting the name Jim from the list."<<endl;
   list1.removeAt(11);
   list1.print();
 
   cout<<endl<<"In list1 I'm inserting the name Brennan at the end."<<endl;
   list1.insertEnd("Brennan");
   list1.print();

   return 0;   
}

void load(unorderedArrayListType &list1)
{
   string word;
   cin>>word;
   while(cin && !list1.isFull())
   {
      list1.insertAt(0, word);
      cin>>word;
   }

}

