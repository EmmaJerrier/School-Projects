/*
Emma Jerrier
March 11th 2022
~/csc1720/lab7
compile: g++ testProgram.cpp uniqueListType.cpp unorderedArrayListT
ype.cpp arrayListType.cpp
execute: ./a.out<names.txt
ABOUT: in this lab we were given the ArrayListType and UnorderedArr
ayListType implementation and header files, and had to convert them
 from ints to strings and we also had to create a new class from th
e unordered list type called unique list type which meant that ther
e were no repeats of names through the list. I overrode the constru
ctor, the insertAt, the insertEnd, and the replaceAt methods becaus
e the final 3 have to be tested for repeats within the list. The ma
in program uses a load function as well to load the file with I/O r
edirection and tests all the overloaded functions
*/

#include <iostream> 
#include<string>
#include "arrayListType.h" 
 
using namespace std;

arrayListType::arrayListType(int size)
{
   if (size <= 0)
   {
      cout << "The array size must be positive. Creating "
           << "an array of the size 100." << endl;

      maxSize = 100;
   }
   else
      maxSize = size;

   length = 0;

   list = new string[maxSize];
} //end constructor

arrayListType::~arrayListType()
{
   delete [] list;
} //end destructor

arrayListType::arrayListType(const arrayListType& otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;

   list = new string[maxSize]; 	//create the array

   for (int j = 0; j < length; j++)  //copy otherList
      list [j] = otherList.list[j];
}//end copy constructor

bool arrayListType::isEmpty() const
{
   return (length == 0);
} //end isEmpty

bool arrayListType::isFull() const  
{
   return (length == maxSize);
} //end isFull

int arrayListType::listSize() const
{
   return length;
} //end listSize

int arrayListType::maxListSize() const
{
   return maxSize;
} //end maxListSize

void arrayListType::print() const
{
   for (int i = 0; i < length; i++)
      cout << list[i] << " ";
   cout << endl;
} //end print

void arrayListType::removeAt(int location)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be removed "
           << "is out of range." << endl;
   else
   {
      for (int i = location; i < length - 1; i++)
         list[i] = list[i+1];

      length--;
   }
} //end removeAt

void arrayListType::clearList()
{
   length = 0;
} //end clearList
