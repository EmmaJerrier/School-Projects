/*
Emma Jerrier
March 18th 2022
CSC1720
~/csc1720/lab8
compile: g++ testProg.cpp
execute: ./a.out

about: This lab we copied files over, and had to make the files all work for a template. we had to create another file for a ordered list type as well and implement a copy constructor, destructor and overload operator = and implemented a friend function to overload insertion operator
*/


//Data: 2.85 6.74 28.93 61.22 10.00 45.34 61.78 5.75

#include <iostream>
#include<string>
#include "unorderedArrayListType.h"
#include "orderedArrayListType.h"

using namespace std; 

int main() 
{
    orderedArrayListType<double> numList(25);
//    unorderedArrayListType<double> numList2(numList);
    cout<<"Create a list of ints:"<<endl;
    numList.insertEnd(2.85);
    numList.insertEnd(6.74);
    numList.insertEnd(28.93);
    numList.insertEnd(61.22);
    numList.insertAt(0, 10.00);
    numList.insertAt(2,45.34);
    numList.insertEnd(61.78);
    numList.insertEnd(5.75);

 //   numList2 = numList;
    orderedArrayListType<double> numList2(numList);
  //  cout<<numList.listSize()<<endl;
    numList.print();
    numList2.print();
    cout << endl;
    cout<<"Remove 6.74:"<<endl;
    numList.remove(6.74);
    numList.print();
    numList2.print();
    cout<<endl;

    cout<<"Remove 0.00:"<<endl;
    numList.remove(0.00);
    cout<<endl<<"Testing overloaded stream insertion operator"<<endl;
    cout<<numList<<endl;
    cout<<endl << "Search for 61.22 in the list:"<<endl;
    if(numList.seqSearch(61.22) != -1)
        cout<<"Successfully found 61.22 in list"<<endl;
    else
        cout<<"61.22 not found"<<endl;

    cout<< endl <<"Search for 255 in the list:"<<endl;
    if(numList.seqSearch(255) != -1)
        cout<<"Successfully found 255 in list"<<endl;
    else
        cout<<"255 not found"<<endl;

    cout<< endl << "List empty? " << numList.isEmpty()<< endl << "List full? " << numList.isFull()<< endl << "length: " <<numList.listSize()<<
        " maxsize: "<<numList.maxListSize()<<endl;

    for(int j=0; j<=40; j++)
       cout<<"-";
    // int list
    orderedArrayListType<int> intList(25);
//    unorderedArrayListType<double> numList2(numList);
    cout<<"Create a list of ints:"<<endl;
    intList.insertEnd(2);
    intList.insertEnd(6);
    intList.insertEnd(28);
    intList.insertEnd(61);
    intList.insertAt(0, 10);
    intList.insertAt(2,45);
    intList.insertEnd(61);
    intList.insertEnd(5);
    
 //   numList2 = numList;
    orderedArrayListType<int> intList2(intList);  
  //  cout<<numList.listSize()<<endl;
    intList.print();   
    intList2.print();        
    cout << endl;              
    cout<<"Remove 6:"<<endl;
    intList.remove(6);
    intList.print();
    intList2.print();
    cout<<endl;

    cout<<"Remove 0:"<<endl;
    intList.remove(0);
    cout<<endl<<"Testing overloaded stream insertion operator"<<endl;
    cout<<intList<<endl;    
    cout<<endl << "Search for 61 in the list:"<<endl;
    if(intList.seqSearch(61) != -1)
        cout<<"Successfully found 61 in list"<<endl;
    else
        cout<<"61 not found"<<endl;

    cout<< endl <<"Search for 255 in the list:"<<endl;
    if(intList.seqSearch(255) != -1)
        cout<<"Successfully found 255 in list"<<endl;
    else
        cout<<"255 not found"<<endl;

    cout<< endl << "List empty? " << intList.isEmpty()<< endl << "List full? " << intList.isFull()<< endl << "length: " <<intList.listSize()<<
        " maxsize: "<<intList.maxListSize()<<endl;
 
    for(int j=0; j<=40; j++)
       cout<<"-";
    // string list    
    orderedArrayListType<string> stringList(6);
    cout<<endl<<"Create a list of strings:"<<endl;
    stringList.insert("Emma");
    stringList.insert("Hello");
    stringList.insert("Friday");
    stringList.insert("hello");
    stringList.insert("apple");
    stringList.insert("Wordle");

    orderedArrayListType<string> stringList2(stringList);
    cout<<"Created a 2nd list of strings to test copy constructor, and printing the first one and using the overloaded stream insertion operator"<<endl;
    stringList.print();
    cout<<stringList2;
    cout<<"Remove Emma:"<<endl;
    stringList.remove("Emma");
    stringList.print();
    stringList2.print();
    
    cout<<"Remove World:"<<endl;
    stringList.remove("World");
    cout<<"Search for Friday in the list:"<<endl;
    if(stringList.seqSearch("Friday") != 1)
       cout<<"Successfully found Friday in list"<<endl;
    else
       cout<<"Friday not found"<<endl;

    cout<<endl<<"List empty? "<< stringList.isEmpty()<< endl << "List full? "<< stringList.isFull()<< endl <<"length: "<< stringList.listSize()<< " maxsize: "<<stringList.maxListSize()<<endl;


    return 0;                                   
}
