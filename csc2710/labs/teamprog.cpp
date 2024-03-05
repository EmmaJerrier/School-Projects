#include <iostream>
#include <iomanip>

using namespace std;
void exchangesort(int n, int s[], int& count, int& comp);
void selectionsort(int n, int s[], int& count, int& comp);
void print(int array[], int cnt);
void fillArray(int s[], int size);

int main()
{
   int s[100],r[100];
   int countex, countsel, compEx, compSel;
   fillArray(s, 100);
   fillArray(r, 100);
   exchangesort(100, s, countex, compEx);
   cout<<"# of swaps: "<<countex<<endl;
   cout<<"# of compares: "<<compEx<<endl;
   print(s, 100);
   cout<<endl<<endl;
   selectionsort(100, r, countsel, compSel);
   cout<<"# of swaps: "<<countsel<<endl;
   cout<<"# of compares: "<<compSel<<endl;
   print(r, 100);
   

   return 0;
}

void exchangesort(int n, int s[], int& count, int& comp)
{
   int i, j, temp;
   count=0;
   comp=0;
   for(i=0; i<=n; i++)
      for(j=i+1; j<=n; j++){
         if(s[j]<s[i]){
            swap(s[i], s[j]);
            count++;}
         comp++;}
}

void selectionsort(int n, int s[], int& count, int& comp)
{
   int i,j,smallest;
   count=0;
   comp=0;
   for(i=0; i<=n-1; i++)
   {
      smallest=i;
      for(j=i+1; j<=n; j++){
         if(s[j]<s[smallest])
            smallest=j;
         comp++;}
      swap(s[i],s[smallest]);
      count++;
   }

}

void print(int array[], int cnt)
{  
   for(int i=0; i<cnt; i++)
      cout<<array[i]<<" ";
   cout<<endl;
}

void fillArray(int s[], int size)
{
   for(int i=0; i<size; i++)
   {
      int num=rand()%100;
      s[i]=num;
   }
}
