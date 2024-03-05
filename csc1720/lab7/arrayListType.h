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
#ifndef ArrayList_TYPE
#define ArrayList_TYPE 
 
using namespace std;

class arrayListType 
{
   protected:
      string *list;    //array to hold the list elements
      int length;   //variable to store the length of the list
      int maxSize;  //variable to store the maximum 
                  //size of the list
   public:
      /*Constructor
        Creates an array of the size specified by the 
        parameter size. The default array size is 100.
        Postcondition: The list points to the array, 
                       length = 0, and maxSize = size;
      */
      arrayListType(int size = 100);

      //Copy constructor
      arrayListType (const arrayListType& otherList);

      //Destructor
      //Deallocate the memory occupied by the array.
      virtual ~arrayListType();

      /*isEmpty Function to determine whether the list is empty
        Postcondition: Returns true if the list is empty;
                       otherwise, returns false.
      */
      bool isEmpty() const;

      /*isFull Function to determine whether the list is full
        Postcondition: Returns true if the list is full; 
                       otherwise, returns false.
      */
      bool isFull() const;

      /*listSize Function to determine the number of elements in 
        the list.
        Postcondition: Returns the value of length.
      */
      int listSize() const;

      /*maxListSize Function to determine the maximum size of the list
        Postcondition: Returns the value of maxSize.
      */
      int maxListSize() const;

      /*print Function to output the elements of the list
        Postcondition: Elements of the list are output on the 
                       standard output device.
      */
      void print() const;

      /*insertAt Function to insert insertItem in the list at the 
        position specified by location. 
        Note that this is an abstract function.
        Postcondition: Starting at location, the elements of 
                       the list are shifted down, 
                       list[location] = insertItem; length++;    
                       If the list is full or location is
                       out of range, an appropriate message 
                       is displayed.
      */
      virtual void insertAt(int location, string insertItem) = 0;

      /*insertEnd Function to insert insertItem an item at the end of 
        the list. Note that this is an abstract function.
        Postcondition: list[length] = insertItem; and length++;
                       If the list is full, an appropriate 
                       message is displayed.
      */
      virtual void insertEnd(string insertItem) = 0;

      /*removeAt Function to remove the item from the list at the 
        position specified by location 
        Postcondition: The list element at list[location] is 
                       removed and length is decremented by 1.
                       If location is out of range, an 
                       appropriate message is displayed.
      */
      void removeAt(int location);

      /*clearList Function to remove all the elements from the list 
        After this operation, the size of the list is zero.
        Postcondition: length = 0;
      */
      void clearList();

      /*seqSearch Function to search the list for searchItem.
        Note that this is an abstract function.
        Postcondition: If the item is found, returns the 
                       location in the array where the item   
                       is found; otherwise, returns -1.
      */
      virtual int seqSearch(string searchItem) const = 0;
};
#endif
