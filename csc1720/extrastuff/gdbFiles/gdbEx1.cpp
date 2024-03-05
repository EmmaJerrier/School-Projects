/*
Example of reading until EOF
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 10
//Prototypes
void load(string x[], int &n);
void print(string x[], int n);
////////////////////////////////////////////////////////////////////
  int main()
  {
      string names[MAX];
      int count;
      count = 0;
      load(names, count);
      print(names, count);

      return 0;
  }
////////////////////////////////////////////////////////////////////
/*
  load - Loads input data for further use

  Precondition: An empty array and the number of items
    in the list are passed in by reference
  Postcondition: Loads information into the array and
    establishes number of members in the datafile
*/
void load(string x[], int &n)
  {
   ifstream inFile;
   string datafile;
   cout <<"Enter name of datafile: "<< endl;
   cin >> datafile;
   inFile.open(datafile);
   if(!inFile)
   {
      cout << "Cannot open the input file. Program will terminate." << endl;
   }
   //Load data into array until EOF
   inFile>>x[n];
   while(!inFile.eof() && n<MAX)
   {
       n++;
       inFile >> x[n];
//       n++;
   }
   inFile.close();
  }

////////////////////////////////////////////////////////////////////////////
/*
  print - prints list of names

  precondition: an array of names and the number of items
    are passed into the function
  postcondition: Outputs name
*/
void print(string x[], int n)
{
    for(int i=0; i < n; i++)
        cout <<"Name " << i << ": " << x[i] << endl;
}


