/*
Name: Emma Jerrier
Date: December 9th 2021
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
// I was stuck on this for forever because I thought I needed to pass the pixel struct in
int loadimage(string filename, imageType &image1);

int main()
{
   string filename;
   imageType image1;

   loadimage(filename, image1); 

   return 0;

} 


int loadimage(string filename, imageType &image1)
{
   ifstream inFile;
   ofstream outFile;
   int i=0, j=0, k=0;
   cout<<"Please input your filename:"<<endl;
   cin>>filename;


   inFile.open(filename);
   if(!inFile)
   {
      cout<<"Cannot open the input file. Program will terminate."<<endl;
      return 1;
   }

   outFile.open("BWimage.pgm");


   getline(inFile, image1.type);
   getline(inFile, image1.comment);
   inFile>>image1.width;
   inFile>>image1.height;
   if(image1.width*image1.height>640000)
   {
      cout<<"Your image has exceeded the image size. Program will terminate."<<endl;
      return 1;
   }
   inFile>>image1.colormax;


   outFile<<"P6"<<endl;
   outFile<<image1.comment<<endl;
   outFile<<image1.width<<" "<<image1.height<<endl;
   outFile<<image1.colormax<<endl;



   inFile>>image1.image[i][j].red;
   inFile>>image1.image[i][j].green;
   inFile>>image1.image[i][j].blue;
   for(i=1; i<=image1.width; i++)
   {
      for(j=1; j<=image1.height; j++)
      {
         unsigned char red, green, blue;
         inFile>>image1.image[i][j].red;
         inFile>>image1.image[i][j].green;
         inFile>>image1.image[i][j].blue;

         for(int k=0; k<image1.width; k++)
         {
            outFile<<static_cast<int>((image1.image[i][j].red+image1.image[i][j].green+image1.image[i][j].blue)/3);
         }
      }
   }

   inFile.close();
   outFile.close();

   return 0;
}
