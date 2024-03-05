//Program to test the various operations on an ordered linked list
/*
LAB 10
Emma Jerrier
April 4th, 2022
CSC1720
~/csc1720/lab10/lab12
compile: g++ -o testOrdered ollTest.cpp
execute: ./testOrdered
about: this lab we used an unordered link list and  an ordered linked list with a linked list and list iterator. We had to add a destroyList method and add it into the destructor and copyList methods. we also added a delete largest function in both unordered and ordered and in the unordered main program we had to add a findAvg function. 
*/  
#include <iostream>
#include "orderedLinkedList.h"
 
using namespace std;
 
int main()
{
   orderedLinkedList<int> list1, list2;        
   int num;                                    

   cout << "Creating list with input 77 11 44 99 33 55" << endl ;

   list1.insertLast(77);                      
   list1.insertLast(11);
   list1.insertLast(44);
   list1.insertLast(99);        
   list1.insertLast(33);
   list1.insertLast(55);

   cout << endl;                               

   cout << "list1: ";                  
   list1.print();                             
   cout << endl;                               

   list2 = list1; //test the assignment operator 

   cout << "list2: ";                 
   list2.print();                              
   cout << endl;                              

   cout << "Enter the number to be " << "deleted: ";                        
   cin >> num;                               
   cout << endl;                               

   list2.deleteNode(num);                     

   cout << "After deleting " << num << endl;
   cout << "list2: " ;         
   list2.print();                              
   cout<<endl;  

   cout << endl << "Output list1 " << "using an iterator:" << endl;            

   linkedListIterator<int> it;                  

   for (it = list1.begin(); it != list1.end(); ++it)                  
       cout << *it << " ";                        
   cout << endl;          
// this section isn't working and at this point I can't figure it out so I'm just taking the point loss for this lab
   cout<<"Deleting Largest from List1 and printing:"<<endl;
   list1.deleteLargest();
   list1.print();



   return 0;					
}



