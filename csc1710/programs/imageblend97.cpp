/*
Name: Emma Jerrier
Date: December 9th 2021
We had to create a program to read in and blend two images using structs, arrays, and functions. 
I did a 97 level + 3 percent bonus - so 100 percent max
This has been my favorite class this year!!!
*/
#include<fstream>
#include<iostream>
#include<string>

using namespace std;
// declared both my structs 
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
// my function prototypes 
int loadimage(string filename, imageType &image1);
void outputimage(string opfilename, imageType &image1, imageType &image2);

int main()
{
// I declared my variables that I knew I would be reading in from the image file
   string filename, opfilename;
   imageType image1;
   imageType image2;
   int i=0, j=0;
  // I load each image with the function then output the two blended images depending on the user input
   loadimage(filename, image1); 
   loadimage(filename, image2);
   outputimage(opfilename, image1, image2);

  return 0;

} 
// this function loads in the imae and takes the type, comment, width, height, and colormax and reads in all the pixels
int loadimage(string filename, imageType &image1)
{
   ifstream inFile;
   int i=0, j=0;
   cout<<"Please input your filename:"<<endl;
   cin>>filename;
// an if incase they type the wrong filename in and it will end the program
   inFile.open(filename);
   if(!inFile)
   {
      cout<<"Cannot open the input file. Program will terminate."<<endl;
      return 1;
   }
 // reading in the data before the pixel values
   getline(inFile, image1.type);
   getline(inFile, image1.comment);
   inFile>>image1.width;
   inFile>>image1.height;
   inFile>>image1.colormax;
// reading in each pixel with a nested loop
   if(image1.width*image1.height>800*800)
   {
      cout<<"File too large. Program will terminate..."<<endl;
      return 1;
   }

   for(i=0; i<image1.height; i++)
   {
      for(j=0; j<image1.width; j++)
      {
         inFile>>image1.image[i][j].red;
         inFile>>image1.image[i][j].green;
         inFile>>image1.image[i][j].blue;
   
      }
   }
   inFile.close();
   return 0;
}
// this function reads in both images and will take an input from the user on how much to blend it
void outputimage(string opfilename, imageType &image1, imageType &image2)
{
   ofstream outFile;
   double blend;
   cout<<"Please input your output filename:"<<endl;
   cin>>opfilename;
// this takes the percentage from the user on the blend amount and checks to make sure its in the right range
   cout<<"Enter the percentage you want the first image to be blended between 0 and 1:"<<endl;
   cin>>blend;   
   while(blend>1 || blend<0)
   {
      cout<<"Improper blending value, try again: "<<endl;
      cin>>blend;
   }
   outFile.open(opfilename);

//I read in the image type, comment, width, height, and color max before starting the loop so the calculations wouldn't include these numbers or senteces

   outFile<<"P6"<<endl;
   outFile<<image1.comment<<endl;
   outFile<<image1.width<<" "<<image1.height<<endl;
   outFile<<image1.colormax<<endl;


// it gets a little funky here, we'll never truly understand why haha, it blends slightly off but should be correct mathwise
// nested loops to outfile the RGB values for each pixel
  for(int i=0; i<image1.height; i++)
   {
      for(int j=0; j<image1.width; j++)
      {
         outFile<<static_cast<unsigned char>((image1.image[i][j].red*blend)+(image2.image[i][j].red*(1-blend)));
         outFile<<static_cast<unsigned char>((image1.image[i][j].green*blend)+(image1.image[i][j].green*(1-blend)));
         outFile<<static_cast<unsigned char>((image1.image[i][j].blue*blend)+(image1.image[i][j].blue*(1-blend)));
      }
   }


   outFile.close();
}
