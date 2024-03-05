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
int loadimage(string filename, imageType &image1);

int main()
{
// I declared my variables that I knew I would be reading in from the image file
   string filename;
   imageType image1;
   int i=0, j=0;
   ofstream outFile;
  
   loadimage(filename, image1); 


   outFile.open("BWimage.ppm");

//I read in the image type, comment, width, height, and color max before starting the loop so the calculations wouldn't include these numbers or senteces

   outFile<<"P6"<<endl;
   outFile<<image1.comment<<endl;
   outFile<<image1.width<<" "<<image1.height<<endl;
   outFile<<image1.colormax<<endl;

   
   
  for(i=0; i<image1.height; i++)
   {
      for(j=0; j<image1.width; j++)
      {
         outFile<<static_cast<unsigned char>(image1.image[i][j].red);
         outFile<<static_cast<unsigned char>(image1.image[i][j].green);
         outFile<<static_cast<unsigned char>(image1.image[i][j].blue);
      }
   }


   outFile.close();

  return 0;

} 

int loadimage(string filename, imageType &image1)
{
   ifstream inFile;
   int i=0, j=0;
   cout<<"Please input your filename:"<<endl;
   cin>>filename;

   inFile.open(filename);
   if(!inFile)
   {
      cout<<"Cannot open the input file. Program will terminate."<<endl;
      return 1;
   }
   getline(inFile, image1.type);
   getline(inFile, image1.comment);
   inFile>>image1.width;
   inFile>>image1.height;
   inFile>>image1.colormax;


   inFile>>image1.image[i][j].red;
   inFile>>image1.image[i][j].green;
   inFile>>image1.image[i][j].blue;
   for(i=1; i<=image1.height; i++)
   {
      for(j=1; j<=image1.width; j++)
      {
         inFile>>image1.image[i][j].red;
         inFile>>image1.image[i][j].green;
         inFile>>image1.image[i][j].blue;
   
      }
   }
   inFile.close();
   return 0;
}
