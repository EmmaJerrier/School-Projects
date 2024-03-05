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
#ifndef UniqueList_TYPE
#define UniqueList_TYPE

#include "unorderedArrayListType.h"

using namespace std;

class uniqueListType: public unorderedArrayListType
{
   public:
 
      // Constructor 
      uniqueListType(int size = 100);
  
      /*
      insertAt - this function will test to make sure that the item being input isn't already there, by calling seqSearch, and then will insert a string value at a chosen location in the list
      precondition: location and insertItem are passed in and the list is accessed and will  be modified
      postcondition: insertItem will be input into the list at designated location
      */
      void insertAt(int location, string insertItem);

      /*
      insertEnd - this function will test to make sure that the item being input isn't already there, by calling seqSearch, and then will insert a string value at the end of the list
      precondition: insertItem is passed in and list and length will be accessed as well
      postcondition: the insertItem will be the final item on the list
      */
      void insertEnd(string insertItem);

      /*
      replaceAt - this function will test to make sure that the item being input isn't already there by calling seqSearch and then will insert a string value to replace the item at a location
      precondition: an int for location and string for repItem are passed in and the list will be accessed
      postcondition: whatever value is at the location will be replaced by repItem
      */
      void replaceAt(int location, string repItem);

};

#endif
