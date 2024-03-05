/* 
Emma Jerrier
11/4/2021
CSC1710
~/csc1710/lab10/funWithFunctions.cpp
We had to use multiple functions and nest them in order to calculate the distance between two points, the radius, circumference, and the area. We also had to do overloaded functions and with default parameters
Assisted by: Dr. Titus, Marcus, and Janine
*/

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;
// declared my constant global variable
const double PI=3.141592;
// declared each of my prototypes - I originally had trouble because I didn't have my variables there so it didn't compile
double distance(double x1, double x2, double y1, double y2);
double radius(double x1, double x2, double y1, double y2);
// declared rad=1 as a default for both circumference and area
double circumference(double rad=1);
double area(double rad=1);
// wrote overloaded functions for both distance and radius
double distance(double x2, double y2);
double radius(double x2, double y2);

int main()
{
// declared variables
double x1, y1, x2, y2, rad;
// asked user for input of the points
   cout<<"Please input the X and Y coordinates of the first point:"<<endl;
   cin>>x1>>y1;
   cout<<"Please input the X and Y coordinates of the second point:"<<endl;
   cin>>x2>>y2;
// calling the distance function
   cout<<"The distance between the two points is "<<distance(x1, x2, y1, y2)<<endl;
// calling the radius function
   cout<<"The radius of the circle between the point ("<<x1<<" , "<<y1<<") as the center and the point ("<<x2<<" , "<<y2<<") is "<<radius(x1, x2, y1, y2)<<endl;
   rad=radius(x1, x2, y1, y2);
// calling the circumference function
   cout<<"The circumference of this circle is "<<circumference(rad)<<endl;   
// calling the area function
   cout<<"The area of this circle is "<<area(rad)<<endl;
//testing default rad=1 for my circumference and my area
   cout<<"The circumference of this circle with a radius of 1 is "<<circumference()<<endl;
   cout<<"The area of the circle with a radius of 1 is "<<area()<<endl;
// calling the overloaded distance function
   cout<<"The distance between your first point and the origin (0,0) is "<<distance(x1, y1)<<endl;
   cout<<"The distance between your second point and the origin (0,0) is "<<distance(x2, y2)<<endl;
// calling the overloaded radius function
   cout<<"The radius of the circle between your first point and the origin (0,0) is "<<radius(x1, y1)<<endl; 
   cout<<"The radius of the circle between your second point and the origin (0,0) is "<<radius(x2, y2)<<endl; 
   

}
// In this function I had to call preexisting functions from the cmath library to do the calculation
double distance(double x1, double x2, double y1, double y2)
{
   double dist=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
   return dist;
}
// In this function I had to call the distance function within it 
double radius(double x1, double x2, double y1, double y2)
{
   double rad=distance(x1, x2, y1, y2);
   return rad;
}
// in this function I just had to pass in my value from the radius function as PI was a global variable
double circumference(double rad)
{
   double circumf=2*PI*rad;
   return circumf;
}
// in this function I just had to pass in my value from the radius function as PI was a global variable and use functions from the cmath library
double area(double rad)
{
   double a=PI*(pow(rad,2));
   return a;
}
//This is just an overloaded version so I took a set of variables out
double distance(double x2, double y2)
{
   double dist=sqrt(pow(x2,2)+pow(y2,2));
   return dist;
}
// overloaded function so i took out a set of variables
double radius(double x2, double y2)
{
   double rad=distance(x2, y2);
   return rad;
}

// This is my favorite class :)
