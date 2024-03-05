/*
Emma Jerier
April 5th, 2022
Csc1720
~/csc1720/lab11/lab11
compile: g++ -o LinkedStack LinkedStackTest.cpp
         g++ -o ArrayStack ArrayStackTest.cpp
execute: ./LinkedStack or ./ArrayStack
about: in this lab we had to work with stackADT classes for both array-based and linked list-based stacks. we had to add a reverseStack method to both to copy the list over in reverse order to destroy the contents of stack2, and fill with the reverse of stack1 while leaving stack1 unchanged
*/
#include <iostream>
#include "linkedStack.h"

using namespace std;
 
int main()
{
    linkedStackType<int> stack1;
    linkedStackType<int> stack2;

    stack1.initializeStack();
    stack1.push(23);
    stack1.push(45);
    stack1.push(38);
    stack1.push(3);
    stack1.push(29);
    stack1.push(82);
    stack1.reverseStack(stack2); // calling the reverseStack to copy in reverse

    cout << "stack1: ";

    while (!stack1.isEmptyStack())
    {
        cout << stack1.top() << " ";
        stack1.pop();
    }

    cout << endl;

    cout << "stack2: "; // print stack2
   
    while (!stack2.isEmptyStack())
    {
       cout << stack2.top() << " ";
       stack2.pop();
    }

    return 0;
}
