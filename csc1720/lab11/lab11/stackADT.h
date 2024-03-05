/*
Emma Jerier
April 5th, 2022
Csc1720
~/csc1720/lab11/lab11
compile: g++ -o LinkedStack LinkedStackTest.cpp
         g++ -o ArrayStack ArrayStackTest.cpp
execute: ./LinkedStack or ./ArrayStack
about: in this lab we had to work with stackADT classes for both array-based and
 linked list-based stacks. we had to add a reverseStack method to both to copy t
he list over in reverse order to destroy the contents of stack2, and fill with t
he reverse of stack1 while leaving stack1 unchanged
*/
//Header file: stackADT.h 

#ifndef H_StackADT
#define H_StackADT 
  
template <class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
      //Method to initialize the stack to an empty state.
      //Postcondition: Stack is empty
     
    virtual bool isEmptyStack() const = 0;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.

    virtual bool isFullStack() const = 0;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //               otherwise returns false.

    virtual void push(const Type& newItem) = 0;
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    virtual Type top() const = 0;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top element
      //               of the stack is returned.

    virtual void pop() = 0;
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top 
      //               element is removed from the stack.
};
        
#endif
