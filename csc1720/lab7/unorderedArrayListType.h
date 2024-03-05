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
#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 

using namespace std;

class unorderedArrayListType: public arrayListType
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt Function ...
         Precondition: 
         Postcondition: 
      */
      void insertAt(int location, string insertItem);
  
      /* insertEnd Function ...
         Precondition: 
         Postcondition: 
      */
      void insertEnd(string insertItem);

      /* replaceAt Function ...
         Precondition: 
         Postcondition: 
      */
      void replaceAt(int location, string repItem);
  
      /* seqSearh Function ...
         Precondition: 
         Postcondition: 
      */
      int seqSearch(string searchItem) const;

}; 

#endif
