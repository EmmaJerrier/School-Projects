/* 
Name - Emma Jerrier & Matt Burton
Date - February 22, 2024
Class - CSC4210
About - one process sends a string message of up to 80 characters to a second process 
the second process reverses the case of each character in the message and sends it to the first process.
 This is done using two ordinary pipes.  

to compile: gcc 3.26.c -o 3.26
to execute: ./3.26 
*/
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

#define BUFFER_SIZE 80
#define READ_END 0
#define WRITE_END 1

/*
pre condition: two arrays are created and passed in to checkingpipe

post condition: the program exits if either pipe is failed to be created or this program creates pipes from the arrays

*/
int checkingpipe(int parent_to_child[], int child_to_parent[]);
/*
pre condition: this function is called with the parent to child pipe (parent_to_child) and the char buffer where the string will be stored

post condition: this function will have asked for a string from the user and then will have written it into the parent to child pipe (parent_to_child)
*/
void parentin(int parent_to_child[]);
/*
pre condition: this function is called with both pipes (parent_to_child & child_to_parent) and the char buffer array

post condition: this function will have read the input from the parent
- switched the case of each letter
- written the message (buffer) into the second pipe

*/
void child(int parent_to_child[], int child_to_parent[]);
/*
pre condition: this function is called with the child to parent pipe

post condition: this function will have read in the message from the child to parent pipe and outputs the new message 

*/
void parentout(int child_to_parent[]);

int main(){
   // create two array to be turned into pipes     
   // parent_to_child = parent to child pipe                      
   int parent_to_child[2];
   // child_to_parent = child to parent pipe
   int child_to_parent[2];
   char reverse[BUFFER_SIZE];
   pid_t pid;

   //checks if pipes were successfully created
   checkingpipe(parent_to_child, child_to_parent);

   //fork a child process
   pid = fork();

   if(pid<0){
      fprintf(stderr, "Fork Failed!");
      exit(1);
   }
   // parent process
   if (pid > 0) { 
      //calls function to get string from stdin and put into pipe 1 (parent_to_child)
      parentin(parent_to_child);
      wait(NULL);

      //calls function to get the string from pipe 2 (child_to_parent)
      parentout(child_to_parent);
   }
   // child process
   else{
      //calls function to take the string from pipe 1 flip characters and put new message in pipe 2
      child(parent_to_child, child_to_parent);
   }

   return 0;
}

int checkingpipe(int parent_to_child[], int child_to_parent[]){
   if(pipe(parent_to_child)==-1){
      fprintf(stderr, "Pipe 1 Failed!");
      exit(3);
   }
   if(pipe(child_to_parent)==-1){
      fprintf(stderr, "Pipe 2 Failed!");
      exit(4);
   }   
   return 0;
}

// reads string from STDIN and puts it in pipe 1
void parentin(int parent_to_child[]){
   char buffer[BUFFER_SIZE];
   close(parent_to_child[READ_END]);
   //prompt for and read in message
   fprintf(stdout, "Enter a line of text (max 80 characters): ");
   //ensures the message is stored in input
   if(fgets(buffer, BUFFER_SIZE, stdin)==NULL){
      fprintf(stderr, "Error reading input");
      exit(5);
   }
   //Send message to child
   if (write(parent_to_child[WRITE_END], buffer, strlen(buffer)+1) == -1)
      {
         fprintf(stderr, "Write to pipe failed");
         exit(2);
      }  
   close(parent_to_child[WRITE_END]);
}

// reads the new string from 2nd pipe 
void parentout(int child_to_parent[]){
   char buffer[BUFFER_SIZE];
   close(child_to_parent[WRITE_END]);
   int bytes_read = read(child_to_parent[READ_END], buffer, BUFFER_SIZE);
   if (bytes_read == -1)
   {
      fprintf(stderr, "Read from pipe failed");
      exit(8);
   }
   close(child_to_parent[READ_END]);

   // Terminate the character array with the null character
   buffer[bytes_read] = '\0';
   // Output the flipped message
   fprintf(stdout, "Flipped message: %s\n", buffer);
}

// takes string from pipe 1, reverses characters and puts it in pipe 2
void child(int parent_to_child[], int child_to_parent[]){

    char buffer[BUFFER_SIZE];
    close(parent_to_child[WRITE_END]);
    //read input from parent
    int bytes_read = read(parent_to_child[READ_END], buffer, BUFFER_SIZE);
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
    // writes message into second pipe
   if (write(child_to_parent[WRITE_END], buffer, strlen(buffer)+1) == -1)
   {
      fprintf(stderr, "Write to pipe failed");
      exit(7);
   } 
    close(parent_to_child[READ_END]); 

}
