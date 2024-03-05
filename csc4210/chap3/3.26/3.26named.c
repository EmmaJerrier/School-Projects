/*
Name - Emma Jerrier & Matt Burton
Date - February 19, 2024
Class - CSC4210
About - this program is the same as the other 3.26 program, 
where it reads a message in using the parent process, 
uses a pipe to send it to the child process where the characters' cases are flipped 
and then another pipe is used to send it back to the parent process where it is printed. 
this version uses named pipes using mkfifo.

to compile: gcc 3.26named.c -o named
to execute: ./named
*/

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define BUFFER_SIZE 80
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
/*
pre condition: this function is called with the parent to child pipe (FIFO1) 
and the char buffer where the string will be stored

post condition: this function will have asked for a string from the user and 
then will have written it into the parent to child pipe (FIFO2)

*/
void parentin(int parent_to_child);
/*
pre condition: this function is called with both pipes (FIFO1 & FIFO2) and the char buffer array

post condition: this function will have read the input from the parent
- switched the case of each letter
- written the message (buffer) into the second pipe

*/
void child(int parent_to_child, int child_to_parent);
/*
pre condition: this function is called with the child to parent pipe and the char buffer array

post condition: this function will have read in the message 
from the child to parent pipe and outputs the new message 

*/
void parentout(int child_to_parent);

int main(){
   // create two pipes                           

   char buffer[BUFFER_SIZE];
   pid_t pid;
   //making the named pipes
   // FIFO1 = parent to child pipe
   mkfifo(FIFO1, 0666);
   // FIFO2 = child to parent pipe
   mkfifo(FIFO2, 0666);

   //fork a child process
   pid = fork();

   if(pid<0){
      fprintf(stderr, "Fork Failed!");
      exit(3);
   }
   // parent process
   if (pid > 0) {
      // creates the pipe and opens FIFO1 for writing only
      int parent_to_child = open(FIFO1, O_WRONLY);
      // creates the pipe and opens FIFO2 for reading only
      int child_to_parent = open(FIFO2, O_RDONLY);

      if (parent_to_child == -1){
         fprintf(stderr, "Failed to open pipe from parent to child");
         exit(8);
      }
      if(child_to_parent == -1){
         fprintf(stderr, "Failed to open pipe from child to parent");
         exit(9);
      }

      //calls function to get string from stdin and put into pipe 1  parent_to_child (FIFO1))
      parentin (parent_to_child);
      wait(NULL);
      // calls function to get string from pipe 2 (child_to_parent (FIFO2))
      parentout(child_to_parent);

      close (parent_to_child);
      close(child_to_parent);
   }
   // child process
   else{
      // creates the pipe and opens FIFO1 for reading only
      int parent_to_child = open(FIFO1, O_RDONLY);
      // creates the pipe and opens FIFO2 for writing only
      int child_to_parent = open(FIFO2, O_WRONLY);
      
      if (parent_to_child == -1){
         fprintf(stderr, "Failed to open pipe from parent to child");
         exit(8);
      }
      if(child_to_parent == -1){
         fprintf(stderr, "Failed to open pipe from child to parent");
         exit(9);
      }
      
      // calls function to take the string from pipe 1 flips the characters and puts the string in pipe 2
      child (parent_to_child, child_to_parent);
   
      close (parent_to_child);
      close(child_to_parent);
   }
   
   //removes both named pipes
   unlink(FIFO1);
   unlink(FIFO2);

   return 0;
}


// reads string from STDIN and puts it in pipe 1
void parentin(int parent_to_child){
   char buffer[BUFFER_SIZE];
   //prompt for and read in message
   fprintf(stdout, "Enter a line of text (max 80 characters): ");
   //ensures the message is stored in input
   if(fgets(buffer, BUFFER_SIZE, stdin)==NULL){
      fprintf(stderr, "Error reading input");
      exit(5);
   }
   //Send message to child
   if(write (parent_to_child, buffer, strlen(buffer)+1)==-1){
      fprintf(stderr, "Write to pipe failed");
      exit(2);
   }
}

// reads the new string from 2nd pipe 
void parentout(int child_to_parent){
   char buffer[BUFFER_SIZE];
   int bytes_read = read(child_to_parent, buffer, BUFFER_SIZE);
   if(bytes_read == -1){
      fprintf(stderr, "Read from pipe failed");
      exit(8);
   }
   // Terminate the character array with the null character
   buffer[bytes_read] = '\0';
   // Output the flipped message
   fprintf(stdout, "Flipped message: %s\n", buffer);  
 //  printf("%s", buffer);   
}

// takes string from pipe 1, reverses characters and puts it in pipe 2
void child(int parent_to_child, int child_to_parent){
   char buffer[BUFFER_SIZE];
   //read input from parent
   int bytes_read = read (parent_to_child, buffer, BUFFER_SIZE);
   if (bytes_read == -1)
   {
        fprintf(stderr, "Read from pipe failed");
        exit(6);
   }   

   buffer[bytes_read]='\0';

   //switches the cases of each letter
   for(int i=0; i<strlen(buffer); i++){
        if (islower(buffer[i]))
        {
            buffer[i] = toupper(buffer[i]);
        }
        else if (isupper(buffer[i]))
        {
            buffer[i] = tolower(buffer[i]);
        }
   }
   //writes message into second pipe
   if(write(child_to_parent, buffer, strlen(buffer)+1)==-1){
      fprintf(stderr, "Write to pipe failed");
      exit(7);
   }   
}
