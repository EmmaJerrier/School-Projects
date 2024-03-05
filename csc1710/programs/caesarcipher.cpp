/* Emma Jerrier
December 2nd 2021
~/csc1710/programs/caesarcipher.cpp
We had to write a program to allow a user to input a message and a shift value then we encoded the message. We also had to offer a menu for the user to select from, and create an array to store all the keys and the encrypted messages

LEVEL 94 PROGRAM !!! MAX 94
*/

#include <iostream>
#include <iomanip>
using namespace std;
// declared each of the prototypes, to read in the message, encrypt and print it, and the functions used to control the shift
void readin(char message[][100], int &k);
void encrypt(char message[][100], char encrypted[][100], int shift[], int &k);
void printmessage(char message[][100], char encrypted[][100], int &k);
void entermessage(char message[][100], char encrypted[][100], int &k, int shift[]);
int menu(char message[][100], char encrypted[][100], int &k, int shift[]);
void loopshift( int shift[], char message[][100], char encrypted[][100], int &k, int i);
void ZandAcontrol(char message[][100], char encrypted[][100], int &k, int i);

int main ()
{
   char message[50][100], encrypted[50][100];
   int shift[50], k=0, key;
   menu(message, encrypted, k, shift);   
// k is my value that is passed by reference everytime to make sure everything aligns
   return 0;
}
// This function reads in the whole message from the user to take up one row of the message array
void readin(char message[][100], int &k)
{
     cin>>message[k];
}
// This funtion takes the message array and shift array and I used if elses to determine how it had to be shifted to ensure it was an alphabetical character
void encrypt(char message[][100], char encrypted[][100], int shift[], int &k)
{
   int i=0;
   char temp;
   if(shift[k]!=0 || shift[k]!=26)
   {
   while(message[k][i]!='\0')
   {
      if(message[k][i]>'Z' || message[k][i]<'A')
      {
         encrypted[k][i]=message[k][i];
      }
      if(message[k][i]>'z' || message[k][i]<'a')
      {
         encrypted[k][i]=message[k][i];
      }
      if(message[k][i]<='Z' && message[k][i]>='A')
      {
         if(shift[k]<=25 && shift[k]>=1)
            encrypted[k][i]=message[k][i]+shift[k];
         else if(shift[k]<-26)
            loopshift(shift, message, encrypted, k, i);
         else if(shift[k]<0 && shift[k]>-26)
            encrypted[k][i]=message[k][i]+shift[k];
         else if(shift[k]>26)
            loopshift(shift, message, encrypted, k, i);
      }
      if(message[k][i]<='z' && message[k][i]>='a')
      {
         if(shift[k]<=25 && shift[k]>=1)
            encrypted[k][i]=message[k][i]+shift[k];
         else if(shift[k]<-26)
            loopshift(shift, message, encrypted, k, i);
         else if(shift[k]<0 && shift[k]>-26)
            encrypted[k][i]=message[k][i]+shift[k];         
         else if(shift[k]>26)
            loopshift(shift, message, encrypted, k, i);
      }
      if(encrypted[k][i]<'A' || encrypted[k][i]>'z')
         ZandAcontrol(message, encrypted, k, i);
      if(encrypted[k][i]>'Z' && encrypted[k][i]<'a')
         ZandAcontrol(message, encrypted, k, i);
      i++;
   }
   }
   else if(shift[k]==0 || shift[k]==26)
      cout<<"No Change to the Message!"<<endl;
}
// this function prints the encrypted message in the enter message function
void printmessage(char message[][100], char encrypted[][100], int &k)
{
    cout<<encrypted[k];
    cout<<endl;
    k++;
}   
// this function calls up the menu which will loop until the user chooses to exit (#4) and I used if elses for each selection to call the necessary functions for each and then bring the menu up after 
int menu(char message[][100], char encrypted[][100], int &k, int shift[])
{
   int selection=0, key;
   cout<<"Welcome to the Message Center! How would you like to proceed?"<<endl;
   while(selection!=4)
   {
   for(int i=0; i<60; i++)
      cout<<"-";
   cout<<endl<<"1) Enter a message"<<endl;
   cout<<"2) Retrieve a message"<<endl;
   cout<<"3) Display ALL stored encrypted messages"<<endl;
   cout<<"4) Exit the message center"<<endl;
   cout<<"Enter your selection:";
   cin>>selection;
   if(selection==1)
   { 
      if(k>49)
         cout<<"You've reached the message limit!!!! Please select another option:"<<endl;
      else if(k<49)
         entermessage(message, encrypted, k, shift);
         k++;
   }   
   else if(selection==2)
   {
      cout<<"Enter the key for the encrypted message(s) you'd like to retrieve:"<<endl;
      cin>>key;
      for(int w=0; w<50; w++)
      {   
         if(key==shift[w])
         {
//            for(int q=0; message[k][q]!='\0'; q++)
               cout<<message[w];
            cout<<endl;
         }
      }
   }
   else if(selection==3)
   {
      for(int i=0; i<k; i++)
      {
         cout<<"Message #"<<i+1<<":";
         for(int j=0; encrypted[k][j]!='\0'; j++)
            cout<<encrypted[i][j];
         cout<<endl;
      }
   }
   }
   return 0;
} 
// this function appears if the user picks option 1, which calls the other functions to read in the message and the shift value, then encrypt and print back out the encrypted message
void entermessage( char message[][100], char encrypted[][100], int &k, int shift[])
{
   cout<<"Please input the word or sentence that you'd like to be encrypted:"<<endl;
   readin(message, k);
   cout<<"Please input the non-zero shift value for your message:"<<endl;
   cin>>shift[k];
   encrypt(message, encrypted, shift, k);
   printmessage(message, encrypted, k);  
}
// This function is to control the shift if the value is outside of 26 or -26 by subtracting or adding 26 (respectively) until the shift value is within bounds
void loopshift( int shift[], char message[][100], char encrypted[][100], int &k, int i)
{
   if(shift[k]>26)
   {
      while(shift[k]>26)
      {
         shift[k]-=26;
      }
      encrypted[k][i]=message[k][i]-shift[k];  
   }
   else if(shift[k]<-26)
   {
      while(shift[k]<-26)
      {
         shift[k]+=26;
      }
      encrypted[k][i]=message[k][i]+shift[k];
   }
}
// I wrote this function to make sure the encrypted values stay as alphabetical values rather than other characters. I used nested if elses to change the value of the encrypted letter to make sure it is alphabetical
void ZandAcontrol(char message[][100], char encrypted[][100], int &k, int i)
{
   if((message[k][i]>='A' && message[k][i]<='Z') || (message[k][i]>='a' && message[k][i]<='z'))
   {
   if(encrypted[k][i]<'A' || encrypted[k][i]>'z')
   {
      if(encrypted[k][i]>'z')
      {   
         encrypted[k][i]=encrypted[k][i]-'z'-1+'a';
      }
      if(encrypted[k][i]<'A')
      {
         encrypted[k][i]=encrypted[k][i]-'z'-1+'a';
      }
   }
   else if(encrypted[k][i]>'Z' && encrypted[k][i]<'a')
   {
      if(encrypted[k][i]>'Z')
      {  
         encrypted[k][i]=encrypted[k][i]-'z'-1+'a';
      }
      if(encrypted[k][i]<'a')
      {
         encrypted[k][i]=encrypted[k][i]-'z'-1+'a';
      }
   }
   }
}

 
