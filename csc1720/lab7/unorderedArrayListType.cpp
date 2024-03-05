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
#include<string>
#include <iostream>
#include "unorderedArrayListType.h" 

using namespace std; 

unorderedArrayListType::unorderedArrayListType(int size)
                      : arrayListType(size)
{
}  //end constructor

void unorderedArrayListType::insertAt(int location, string insertItem) 
{
   if (location < 0 || location >= maxSize || location > length)
      cout << "The position of the item to be inserted "
           << "is out of range." << endl;
   else if (length >= maxSize)  //list is full
      cout << "Cannot insert in a full list" << endl;
   else
   {
      for (int i = length; i > location; i--)
         list[i] = list[i - 1];	//move the elements down

      list[location] = insertItem; //insert the item at 
                                   //the specified position

      length++;	//increment the length
   }
} //end insertAt

void unorderedArrayListType::insertEnd(string insertItem)
{
   if (length >= maxSize)  //the list is full
      cout << "Cannot insert in a full list." << endl;
   else
   {
      list[length] = insertItem; //insert the item at the end
      length++; //increment the length
   }
} //end insertEnd

void unorderedArrayListType::replaceAt(int location, string repItem)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      list[location] = repItem;
} //end replaceAt

int unorderedArrayListType::seqSearch(string searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < length && !found)
      if (list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)
      return loc;
   else
      return -1;
} //end seqSearch


