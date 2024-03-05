/*
Emma Jerrier
February 24 2022
CSC1720
*/
#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 

class unorderedArrayListType: public arrayListType
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      /* insertAt - this function inserts an int value at a chosen location in the list
         Precondition: location and insertItem are passed in and the list is accessed and will  be modified
         Postcondition: insertItem will be input into the list at the designated location
      */
      void insertAt(int location, int insertItem);
  
      /* insertEnd - this Function inserts an int value at the end of the list, adding one more item on
         Precondition: an int for insertItem is passed in and list and length will be accessed as well
         Postcondition: the length will increase by one and insertItem will be the final item on the list
      */
      void insertEnd(int insertItem);

      /* replaceAt - this Function replaces an item in the list at a specified location with a specified int value 
         Precondition: an int for location and repItem are passed in and the list will be accessed
         Postcondition: whatever value is at the location will be replaced by repItem
      */
      void replaceAt(int location, int repItem);
  
      /* seqSearch - this Function searches the list for the specified item 
         Precondition: a searchItem is passed in and the list is accessed to look for it
         Postcondition: the position of the item will be returned to the main program
      */
      int seqSearch(int searchItem) const;

      /*
      removeAt - this function removes the item from the list at the position specified by the location and is replaced the the last item on the list  
      Precondition: the location is passed in and the list will be accessed and modified by moving the last item to the location specified
      Postcondition: the list order will be modified, moving the last to the location specified
      */
      void removeAt(int location);
     
      /*
      insertFirst - Function to insert insertItem at the beginning of the list, which calls the insertAt function to put it in the first position
      precondition: the item is passed in, which will be put into the array at the position [0] and the list is accessed
      postconditon: the array is loaded in with the new value at the first position  
      */
      void insertFirst(int insertItem);  

      /*
      findMax - Function to find the highest value and then return it to the main program
      precondition: nothing is passed in but the list is accessed and the values are searched to find the highest
      postcondition: the highest value from the list is returned to the main program      
      */ 
      int findMax(); 
      
}; 

#endif
