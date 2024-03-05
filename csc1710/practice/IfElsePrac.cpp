#include <iostream>
using namespace std; 

int main()
{
double x, y, z, largest;

   cin>>x;
   cin>>y;
   cin>>z;

   if(x>z && x>y)
      largest = x;
   else if(y>z && y>x)
      largest = y;
   else if(z>x && z>y)
      largest = z;
 
   cout<<largest<<endl;

   return 0;
}
