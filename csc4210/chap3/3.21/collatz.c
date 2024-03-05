/*
Name - Emma Jerrier 
Date - February 18, 2024
Class - CSC4210
About - This program uses parent and child processes to read in an integer from the command line and then depending on if it is an even or odd integer the child process will manipulate that number until it reaches one and print the sequence to the command line. While the child process runs the parent process waits 

to compile: gcc collatz.c -o collatz
to execute: ./collatz #
# - any positive integer
*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

void child(int num);

int main(int argc, char* argv[])
{ 
pid_t pid;


   pid = fork();
   char *a=argv[1];
   int num=atoi(a);
   
   if(num<0){
      fprintf(stderr, "Invalid Input!\n");
      return 1;
   }

   else{
      if (pid<0) {
         fprintf(stderr, "Fork Failed");
         return 1;
      }

      /* Child process */
      else if (pid ==0)
         child(num);

      /* Parent process */
      else
         wait(NULL);
    
   }
   return 0;
}

void child(int num){
   printf("%d\n", num);
      while(num>1){
         if(num%2!=0){
            num=(3*num)+1;
            printf("%d\n", num);
         }
         else{
            num=num/2;
            printf("%d\n", num);
         }
      }
}
