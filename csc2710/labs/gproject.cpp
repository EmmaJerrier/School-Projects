/*
Emma Jerrier
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sys/time.h>
#include <string>

using namespace std;

void loadArray(string, int[], int);
void exchangesort(int n, int s[]);
void selectionsort(int n, int s[]);

timeval startTime, stopTime;
double start, stop, diff;

int MAX = 10000;
int exchangeSwap=0;
int exchangeComp=0;
int selectSwap=0;
int selectComp=0;

int main()
{
   int array[MAX], n, userArrayChoice;
   string filename = "";
// took from hannahs to read in filename and make sure values are correct
   cout<<"To hardcode an array, enter 0. To enter a file, enter 1."<<endl;
   cin>> userArrayChoice;
   cout<<endl<<endl;

   if(userArrayChoice==0)
   {
      cout<<"How many numbers will be in your array?"<<endl;
      cin>>n;

      int userArray[n];
      cout<<endl<<endl;
      
      cout<<"Input the numbers in your array"<<endl;
      for(int i=0; i<n; i++)
         cin>>userArray[i];
      cout<<endl<<endl;
 
      exchangesort(n, userArray);
      cout<<endl<<endl;
      selectionsort(n, userArray);
    } 
 
   
   if(userArrayChoice==1)
   {
      cout<<"Enter the name of the file with random Numbers: ";
      cin>>filename;

      ifstream my_file;
      my_file.open(filename);
      if(!my_file)
         cout<<"No such file!";
      else
      {
         cout<<endl<<endl;
         cout<<"Enter the number of random numbers (max=10,000) = ";
         cin>>n;
      }
      cout<<endl<<endl;
      loadArray(filename, array, n);

      exchangesort(n, array);
      cout<<endl<<endl;
      selectionsort(n, array);
   }
   return 0;
}

void loadArray(string filename, int array[], int n)
{
   ifstream my_file;
   my_file.open(filename);
   for(int i=0; i<n; i++)
      my_file>>array[i];
   my_file.close();

}

void exchangesort(int n, int s[])
{
   int i, j, temp;

   gettimeofday(&startTime, NULL);

   for(i=0; i<=n; i++){
      exchangeComp+=1;
      for(j=i+1; j<=n; j++){
// made it +=2 because that way it will always count the if as a comparison rather than only if the if statement executes
         exchangeComp+=2;
         if(s[j]<s[i]){
            swap(s[i], s[j]);
            exchangeSwap+=1;}
      }
   }
   gettimeofday(&stopTime, NULL);
   start = startTime.tv_sec + (startTime.tv_usec/10000000.0);
   stop = stopTime.tv_sec + (stopTime.tv_usec/10000000.0);
   diff = stop - start;
  
   cout<<"Analyzing Exchange Sort: "<<endl;
   cout<<"n = "<<n<<endl;
   cout<<"Number of swaps: "<<exchangeSwap<<endl;
   cout<<"Basic operations: "<<exchangeComp<<endl;
   cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
   cout<<endl;
}

void selectionsort(int n, int s[])
{
   int i,j,smallest;

   gettimeofday(&startTime, NULL);

   for(i=0; i<=n-1; i++)
   {
      selectComp+=1;
      smallest=i;
      for(j=i+1; j<=n; j++){
// made it +=2 because that way it will always count the if as a comparison rather than only if the if statement executes
         selectComp+=2;
         if(s[j]<s[smallest]){
            smallest=j;
         }
      }
      swap(s[i],s[smallest]);
      selectSwap++;
   }

   gettimeofday(&stopTime, NULL);
   start = startTime.tv_sec + (startTime.tv_usec/10000000.0);
   stop = stopTime.tv_sec + (stopTime.tv_usec/10000000.0);
   diff = stop - start;
  
   cout<<"Analyzing Selection Sort: "<<endl;
   cout<<"n = "<<n<<endl;
   cout<<"Number of swaps: "<<selectSwap<<endl;
   cout<<"Basic operations: "<<selectComp<<endl;
   cout<<"Time = "<<setprecision(10)<<diff<<" seconds"<<endl;
   cout<<endl;
}
