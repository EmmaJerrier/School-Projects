#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType

#include <iostream>

using namespace std;
 
#include "arrayListType.h"
   
template <class elemType> 
class unorderedArrayListType: public arrayListType<elemType>
{
public:
    /*
    insertAt -  inserts insertItem at the location specified
    precondition: location and insertItem passed in
    postcondition: elements of the list are shifted down one, the item goes in the location, the length increases by 1
    */
    void insertAt(int location, const elemType& insertItem);
    /*
    insertEnd - inserts insertItem at the end of the list  
    precondition: insert item is passed in
    postcondition: length is increased and the item is at the end
    */
    void insertEnd(const elemType& insertItem);
    /*
    replaceAt - replaces repItem at the specified location
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
    constructor - creates an array of the size specified by the parameter size. the default array size is 100.
    pre condition: a size is passed in which sets the array size or the default is 100
    post condition: the list points to the array, length =0, and maxSize = size
    */
    unorderedArrayListType(int size = 100);
      //Constructor
}; 

template <class elemType>
void unorderedArrayListType<elemType>::insertAt(int location, const elemType& insertItem)
{
    //Complete this function stub
} //end insertAt

template <class elemType>
void unorderedArrayListType<elemType>::insertEnd
                                 (const elemType& insertItem)
{
    if (this->length >= this->maxSize)  //the list is full
        cout << "Cannot insert in a full list." << endl;
    else
    {
       this-> list[this->length] = insertItem; //insert the item at the end
        this->length++; //increment the length
    }
} //end insertEnd

template <class elemType>
int unorderedArrayListType<elemType>::seqSearch
                            (const elemType& searchItem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < this->length; loc++)
        if (this->list[loc] == searchItem)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void unorderedArrayListType<elemType>::remove
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
void unorderedArrayListType<elemType>::replaceAt(int location, 
                                       const elemType& repItem)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be "
             << "replaced is out of range." << endl;
    else
        this->list[location] = repItem;
} //end replaceAt 

template <class elemType>
unorderedArrayListType<elemType>::
                       unorderedArrayListType(int size)
                       : arrayListType<elemType>(size)
{
}  //end constructor


#endif
