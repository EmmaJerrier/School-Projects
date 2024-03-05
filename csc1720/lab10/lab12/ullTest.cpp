//Thisprogram tests various operations of an unordered linked list
/*
LAB 10
Emma Jerrier
April 4th, 2022
CSC1720
~/csc1720/lab10/lab12
compile: g++ -o testUnordered ullTest.cpp
execute: ./testUnordered
about: this lab we used an unordered link list and  an ordered linked list with a linked list and list iterator. We had to add a destroyList method and add it into the destructor and copyList methods. we also added a delete largest function in both unordered and ordered and in the unordered main program we had to add a findAvg function. 
*/

#include<iostream>
#include"unorderedLinkedList.h"

using namespace std; 
/*
findAvg - this function takes the unordered linked list and uses an iterator to add all the items together and divde by the length to find and return the average
precondition: the unordered linked list is passed in
postcondition: the average is returned as a double
*/
template <class T>
double findAvg(unorderedLinkedList<T> list);

int main()
{
   unorderedLinkedList<int> listA, listB;          
   int num;                                        

   cout << "Creating list with input 22 7 48 93 14 2 " << endl ;

   listA.insertLast(22);                      
   listA.insertLast(7);
   listA.insertLast(48);
   listA.insertLast(93);        
   listA.insertLast(14);
   listA.insertLast(2);
   
   cout << endl;                                 
// calling the average function  
   cout<<"listA average: "<<findAvg(listA)<<endl;

   cout << "listA: ";                      
   listA.print();                                  
   cout << endl;                                   

   cout << "Length of listA: " << listA.length() << endl;                 

   listB = listA;	   //test the assignment operator 

   cout << endl;
   cout << "listB: ";                     
   listB.print();                                  
   cout << endl;                                  
   cout<<"listB average: " <<findAvg(listB)<<endl; 

   cout << "Length of listB: " << listB.length() << endl;                 

   cout << endl;
   cout << "Enter the number to be " << "deleted: ";                           
   cin >> num;                                     

   listB.deleteNode(num);                          
	
   cout << "After deleting " << num << endl;
   cout << "listB: " ;                     
   listB.print();                                  
   cout << endl;                                

   cout << "Length of listB: " << listB.length() << endl;              
   cout << endl;

   cout << "Output listA " << "using an iterator:" << endl;            

   linkedListIterator<int> it;                  

   for (it = listA.begin(); it != listA.end(); ++it)                  
       cout << *it << " ";                        
   cout << endl;

   unorderedLinkedList<char> listC;          
   char x;                                 

   cout << endl << "Creating list with input A K M G ! C " << endl ;

   listC.insertLast('A');                      
   listC.insertLast('K');
   listC.insertLast('M');
   listC.insertLast('G');        
   listC.insertLast('!');
   listC.insertLast('C');
       
   cout << endl;                                   

   cout << "listC: ";                      
   listC.print();                                  
   cout << endl;                                   
   cout << "Length of listC: " << listC.length() << endl;  

   cout<< endl << "Enter the character to be " << "deleted: ";                           
   cin >> x;                                     

   listC.deleteNode(x);                          
	
   cout << "After deleting " << x << endl;
   cout << "listC: " ;                     
   listC.print();                                  
   cout << endl;                         

// calling delete largest for both - having issues printing it though :/ im not sure why
   cout<<"Deleting Largest from ListA and printing:"<<endl;
   listA.deleteLargest();
   listA.print();

   cout<<"Deleting Largest from ListB and printing:"<<endl;
   listB.deleteLargest();
   listB.print();

   return 0;					
}
// find avg function
template <class T>
double findAvg(unorderedLinkedList<T> list)
{
// avg will be returned
   double avg=0;
   linkedListIterator<T> temp;
   temp = list.begin();
   while(temp != list.end())
   {
      avg= avg + *temp;
// pre incremental
      ++temp;
   }
   avg /= list.length()*1.0;

   return avg;
}



