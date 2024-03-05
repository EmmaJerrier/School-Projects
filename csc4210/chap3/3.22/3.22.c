/*
Name - Emma Jerrier & Matt Burton
Class - CSC4210
Date - February 21, 2024
About - This program is similar to 3.21 but uses shared memory to store the numbers and then the parent process reads them from stored memory. 
The parent also finds the sum of all values in the sequence and outputs the sum.


to compile: gcc 3.22.c -0 3.22 
to execute: ./3.22 <positive integer>
*/

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define BUFFER_SIZE 100
/*
pre condition: the checking function calls the child function and passes the number from the command line (int num) 
and the pointer to the shared memory object (*ptr)

post condition: the function will either divide num by 2 if it's even, or multiply num by 3 and add 1 if it's even. 
This will loop until num is equal to 1. The function will store up to 100 of these values in the shared memory.
*/
void child(int num, void *ptr);
/*
pre condition: the shared memory object has been created and the integer has been read in from the command line.
The number from the command line has been passed in (int num), the pid has been passed in (pid_t pid), and the pointer to the shared memory object (*ptr)

post condition: this function will check to make sure the input is valid and make sure the fork works. 
It will call the functions Child and Parent and then return 0 if it all worked successfully.
*/
int checking(int num, pid_t pid, void *ptr);
/*
pre condition: the checking function will call the parent function and passes the number from the command line (int num) 
and the pointer to the shared memory obeject (*ptr)

post condition: this function will access the shared memory and print each value while adding each value to sum. 
After the loop finishes or reaches 100 values it will print the sum as well. 
*/
void parent(int num, void *ptr);

int main(int argc, char* argv[])
{
   pid_t pid;
   pid = fork();
   char *a=argv[1];
   int num=atoi(a);
   int count=0;

   if(argc!=2){
      fprintf(stderr, "Usage: %s <positive integer>\n", argv[0]);
      exit(3);
   }

   /* size of shared mem object */
   const int SIZE = 4096;
   /* name of shared mem object */
   const char* name = "OS";
   /* shared mem descriptor */ 
   int fd;
   /* pointer to shared mem object */
   void* ptr; 
   /* creating shared mem object */
   fd = shm_open(name, O_CREAT | O_RDWR, 0666);
   /* config size of shm */
   ftruncate(fd, SIZE);
   /* memory map the shm */
   ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);   

   checking(num, pid, ptr);
   
   shm_unlink(name);

   return 0;
}

int checking(int num, pid_t pid, void *ptr){
   
   /* checks to make sure the number is positive */
   if(num<0){
      fprintf(stderr, "Number must be a positive integer\n");
      exit(4);
   }
   /* checks to make sure the fork has been created */
   else{
      if (pid<0) {
         fprintf(stderr, "Fork Failed");
         exit(5);
      }

      /* Child process */
      else if (pid ==0){
         child(num, ptr);
         return 0;
      }
      /* Parent process */
      else{
         wait(NULL);
         parent(num, ptr);
         return 0;
      }
   }
}

void child(int num, void *ptr){
   char buffer[20];
   int index=0;
      /* ensures that it prints only the buffer size and num is greater than 1 */
      while(num!=1 && index<BUFFER_SIZE){

         int length = snprintf(buffer, sizeof(buffer), "%d ", num);
         /* stores value in shared memory object */
         memcpy(ptr, buffer, length);
         ptr += length;
         /* if num is odd it multiplies it by 3 and adds 1 */
         if(num%2!=0){
            num=(3*num)+1;}
         /* if num is even it divides by 2*/
         else{
            num=num/2;}
         index++;
      }
   /* adds the last value of the sequence to the memory */
    snprintf(buffer, sizeof(buffer), "%d", num);
    int length = strlen(buffer);
    memcpy(ptr, buffer, length);
    ptr += length; 
}

void parent(int num, void *ptr){
   char *sequence = (char *)ptr;   

   int sum = 0;
   int value;
   char *token = strtok(sequence, " ");

    while (token != NULL) {
        /* Convert token to integer */
        sscanf(token, "%d", &value);
        
        /* Print the value */
        printf("%d ", value);
        
        /* Add the value to the sum */
        sum += value;
        
        /* Move to the next token */
        token = strtok(NULL, " ");
    }
    
    /* Print the sum */
    printf("\nSum of Collatz sequence for %d: %d\n", num, sum);

}
