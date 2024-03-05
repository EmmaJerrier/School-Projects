/*
Emma Jerrier
March 18th 2022
CSC1720
~/csc1720/lab8
compile: g++ testProg.cpp
execute: ./a.out

about: This lab we copied files over, and had to make the files all work for a template. we had to create another file for a ordered list type as well and implement a copy constructor, destructor and overload operator = and implemented a friend function to overload insertion operator
*/

#ifndef H_orderedArrayListType
#define H_orderedArrayListType

#include <iostream>

using namespace std;
 
#include "arrayListType.h"

   
template <class elemType> 
class orderedArrayListType: public arrayListType<elemType>
{
public:

    /*
    insertAt -  inserts insertItem depending on the order
    precondition: location and insertItem passed in
    postcondition: elements of the list are shifted down one, the item goes in the location, the length increases by 1
    */
    void insertAt(int location, const elemType& insertItem);
    /*
    insertEnd - inserts insertItem depending on the order  
    precondition: insert item is passed in
    postcondition: length is increased and the item is at the end
    */
    void insertEnd(const elemType& insertItem);
    /*
    replaceAt - replaces repItem in ordered list
    precondition: location and repItem are passed in
    postcondition: if location is out of range, an appropriate message is displayed. or the location will be replaced with repItem
    */
    void replaceAt(int location, const elemType& repItem);
    /*
    seqSearch - this function searches the list for the searchItem 
    precondition: the item being search for is passed in 
    postcondition: if it's found the location is returned; otherwise -1 is returned
    */
    int seqSearch(const elemType& searchItem) const;
    /*
    remove - removes the "removeItem" from the list and the length decreases
    pre condition: the item being removed is passed in
    post condition: the item will be removed and the length is decremented by 1
    */
    void remove(const elemType& removeItem);
    /*
    insert - this method inserts an item in an ordered list
    precondition - insertItem is passed in
    postcondition - the item will be insert depending on the order of the list
    */
    void insert(const elemType& insertItem);
    /*
    constructor - creates an array of the size specified by the parameter size. the default array size is 100.
    pre condition: a size is passed in which sets the array size or the default is 100
    post condition: the list points to the array, length =0, and maxSize = size
    */
    orderedArrayListType(int size = 100);
      //Constructor
}; 

template <class elemType>
int orderedArrayListType<elemType>::seqSearch
                            (const elemType& searchItem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < this->length && !found && this->list[loc+1]>=searchItem; loc++)
        if (this->list[loc] == searchItem)
        {
            found = true;
        }

    if (found)
        return loc-1;
    else
        return -1;
} //end seqSearch

template <class elemType>
void orderedArrayListType<elemType>::remove
                               (const elemType& removeItem)
{
    int loc;

    if (this->length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            this->removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

template <class elemType>
void orderedArrayListType<elemType>::replaceAt(int location, 
                                       const elemType& repItem)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be "
             << "replaced is out of range." << endl;
    else
        this->list[location] = repItem;
} //end replaceAt 

template <class elemType>
orderedArrayListType<elemType>::
                       orderedArrayListType(int size)
                       : arrayListType<elemType>(size)
{
}  //end constructor

template <class elemType>
void orderedArrayListType<elemType>::insert(const elemType& insertItem)
{
   if(this->length == 0)
      this->list[this->length++] = insertItem;
   else if (this->length == this->maxSize)
      cout<<"Cannot insert in a full list."<<endl;
   else
   {
      int loc=0;
      bool found = false;
      while (!found && loc < this->length)
      {
         if(this->list[loc] >= insertItem)
            found = true;
         else
            loc++;
      }
     
      for(int i = this->length; i>loc; i--)
         this->list[i]=this->list[i-1];

      this->list[loc] = insertItem;
      this->length++;
   }
}

template <class elemType>
void orderedArrayListType<elemType>::insertAt(int location, const elemType& insertItem)

{
   insert(insertItem);
}

template <class elemType>
void orderedArrayListType<elemType>::insertEnd(const elemType& insertItem)
{
   insert(insertItem);
}


#endif
