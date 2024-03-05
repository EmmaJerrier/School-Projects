/*
Name: Emma Jerrier
Date: October 21st 2021
Assisted by: Mia Glenn
We had to create a program to convert an image from color to a greyscale image 
*/
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main()
{
// I declared my variables that I knew I would be reading in from the image file
   string filename, imagetype, comment;
   int width, height, colormax, red, green, blue;
   ifstream inFile;
   ofstream outFile;

   cout<<"Please input your filename:"<<endl;
   cin>>filename;

// I did an if statement in case I wasn't able to open the file (I got this statement the first few times I ran the program because I saved the beach image in the wrong place haha!)

   inFile.open(filename);
   if(!inFile)
   {
      cout<<"Cannot open the input file. Program will terminate."<<endl;
      return 1;
   }

   outFile.open("BWimage.pgm");

//I read in the image type, comment, width, height, and color max before starting the loop so the calculations wouldn't include these numbers or senteces

   getline(inFile, imagetype);
   getline(inFile, comment);
   inFile>>width;
   inFile>>height;
   inFile>>colormax;

// Had to put P2 rather than taking from the other file because the image type changed

   outFile<<"P2"<<endl;
   outFile<<comment<<endl;
   outFile<<width<<" "<<height<<endl;
   outFile<<colormax<<endl;

// Here I did a loop to read in three pixels (red, green, and blue) then do the calculations to turn those three values into one greyscale value

   while(inFile)
   {
      inFile>>red;
      inFile>>green;
      inFile>>blue;

      outFile<<static_cast<int>(red*(.3)+green*(.6)+blue*(.1))<<endl;
   }

   inFile.close();
   outFile.close();

  return 0;

} 
