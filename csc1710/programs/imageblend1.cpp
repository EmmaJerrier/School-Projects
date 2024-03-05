/*
Name: Emma Jerrier
Date: October 21st 2021
*/
#include<fstream>
#include<iostream>
#include<string>

using namespace std;
struct pixel
{
   short int red;
   short int green;
   short int blue;
};
struct imageType
{
   string type;
   string comment;
   int width, height, colormax;
   pixel image[800][800];
};

int main()
{
// I declared my variables that I knew I would be reading in from the image file
   string filename;
   imageType image1;
   int i=0, j=0;
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

   getline(inFile, image1.type);
   getline(inFile, image1.comment);
   inFile>>image1.width;
   inFile>>image1.height;
   inFile>>image1.colormax;

// Had to put P2 rather than taking from the other file because the image type changed

   outFile<<"P2"<<endl;
   outFile<<image1.comment<<endl;
   outFile<<image1.width<<" "<<image1.height<<endl;
   outFile<<image1.colormax<<endl;

   
   
   inFile>>image1.image[i][j].red;
   inFile>>image1.image[i][j].green;
   inFile>>image1.image[i][j].blue;
   for(i=1; i<image1.width; i++)
   {
      for(j=1; j<image1.height; j++)
      {
         inFile>>image1.image[i][j].red;
         inFile>>image1.image[i][j].green;
         inFile>>image1.image[i][j].blue;

         outFile<<static_cast<int>(image1.image[i][j].red*(.3)+image1.image[i][j].green*(.6)+image1.image[i][j].blue*(.1))<<endl;

      }
   }

   inFile.close();
   outFile.close();

  return 0;

} 
