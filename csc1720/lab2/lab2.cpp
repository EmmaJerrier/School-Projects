/*
Emma Jerrier
January 17th 2022
CSC1720
~/csc1720/lab2
This lab, we had to create an array of 2 structs, dateType and personType and using functions to load in the information using File I/O and by asking the user for the current date, calculate the person's age. We also had to write a function to prompt the user fr a specific age and output anyone who is that age. Finally, we had to use printInfo to output one person's name, ID number, birth date and age.
compile : g++ lab2.cpp
execute : ./a.out
*/

#include<iostream>
#include<fstream>

using namespace std;

struct dateType
{
   int month;
   int day;
   int year;
};

struct personType
{
   string firstname;
   string lastname;
   int idNumber;
   dateType birthdate;
};

int loadInfo(personType personInfo[]);
void readDate(dateType &current);
void calcAge(int count, int dates[], dateType &current, personType personInfo[]); 
void searchAge(int count, int dates[], personType personInfo[], dateType &current);
void printInfo(int dates[], personType personInfo[], int i);
int main()
{
   personType personInfo[50];
   dateType current;
   int dates[50];
   int count;
   count=loadInfo(personInfo);
   readDate(current);
//   calcAge(count, dates, current, personInfo);
   searchAge(count, dates, personInfo, current);

   return 0;
}

/*
loadInfo - this function will ask for the filename, open the file, read in the name, id and birthday of each person in the array and then close the file after
Precondition: personInfo[] is declared so the struct is used to fill the array, currently unloaded
Postcondition: the function will return count (the number of rows in the array) and the file will be fully loaded 
*/
int loadInfo(personType personInfo[])
{
   string filename;
   ifstream inFile;
   int i=0, count;
   cout<<"Please input your filename:"<<endl;
   cin>>filename;
   inFile.open(filename);
   if(!inFile)
   {
      cout<<"Cannot open the input file. Program will terminate."<<endl;
      return 1;
   }

   while(inFile)
   {   
   while(inFile && i<50)
   {
      inFile>>personInfo[i].firstname;
      inFile>>personInfo[i].lastname;
      inFile>>personInfo[i].idNumber;
      inFile>>personInfo[i].birthdate.month;
      inFile>>personInfo[i].birthdate.day;
      inFile>>personInfo[i].birthdate.year;
      i++;
   }
   }
   inFile.close();
   count = i;
   return count;
}

/*
readDate - this function asks the user for the current date and stores it in a variable from the dateType struct
Precondition: current is passed by reference so when the user inputs the date in this function it updates everywhere
Postcondition: this passes the current month day and year to main 
*/
void readDate(dateType &current)
{
   cout<<"Enter today's date in integer value:"<<endl;
   cout<<"Month: ";
   cin>>current.month;
   cout<<"Day: ";
   cin>>current.day;
   cout<<"Year: ";
   cin>>current.year;
}

/*
calcAge - this function calculates each person's age from the personInfo array, I used if elses to go step by step, determining the age based on the month values and days, so each age is accurate
Precondition: count is passed in which determines the number of rows, dates[] is passed in and will be used to store the ages in a parallel array from person info and current and personInfo are passed in to do the age calculations
Postcondition: this function will fill the dates array with the ages of each of the individuals in a parallel array
*/
void calcAge(int count, int dates[], dateType &current, personType personInfo[])
{
   int age;
   int i=0;
   while(i<count)
   {
      age=current.year-personInfo[i].birthdate.year;
      if(personInfo[i].birthdate.month>current.month)
         dates[i]=age-1;
      else if(personInfo[i].birthdate.month==current.month)
         if(personInfo[i].birthdate.day>current.day)
            dates[i]=age-1;
         else if(personInfo[i].birthdate.day<current.day)
            dates[i]=age;
         else
            dates[i]=age;
      else if(personInfo[i].birthdate.month<current.month)
         dates[i]=age;
      i++;
   }
}

/*
searchAge - this function prompts the user for a specific age and uses an if statement to test each value in the dates array and then calls the printInfo function to print that specific individuals information
Precondition: all the values passed in are already full and will not be modified but they'll be used and searched through
Postcondition: this function will call the print function to print each individuals's information
*/
void searchAge(int count, int dates[], personType personInfo[], dateType &current)
{
   int age, i=0;
   calcAge(count, dates, current, personInfo);
   cout<<"Please enter the age you would like to search for:";
   cin>>age;
   cout<<endl;
   while(i<count)
   {
      if(dates[i]==age)
      {
         printInfo(dates, personInfo, i);
         i++;
      }
      else
         i++; 
   }

}
/*
printInfo - this function prints an individual person's name, id number, birth day and age
precondition: all arrays and variables are full/declared and initialized, and nothing will change
postcondition: it will print one row of information for a single individual
*/
void printInfo(int dates[], personType personInfo[], int i)
{
   cout<<personInfo[i].firstname<<" "<<personInfo[i].lastname<<" "<<personInfo[i].idNumber<<" "<<personInfo[i].birthdate.month<<"/"<<personInfo[i].birthdate.day<<"/"<<personInfo[i].birthdate.year<<" "<<dates[i]<<endl;
}


