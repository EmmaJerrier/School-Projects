#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//int max = 10000;

struct heap
{
int heapsize;
int S[10000];
};

int comparecounter = 0;

void siftDown(heap& H, int i, int maxnum);
int root(heap& heap, int maxnum);
void removeKeys(int n, heap& H, int S[], int maxnum);
void makeHeap(int n, heap& heap, int maxnum);
void heapSort(int n, heap& H, int S[], int maxnum);

int main()
{
	//cout << "I got here";	
	int maxnum = 5;
	int choice;
	int array[maxnum];	


	cout << "How many numbers?" << endl;	
	cin >> maxnum;

	cout << "Do you want to hardcode it or enter a file? 0 for hardcode, 1 for file." << endl;
	cin >> choice;

	if (choice == 0)
	{
		//cout << "How many numbers do you want to input?" << endl;
		//cin >> maxnum;

		//cout << "the array size is " << maxnum << endl;
		
		struct heap H = {maxnum};

		cout << "Please enter in " << maxnum << " numbers" << endl;
		for (int i = 0; i < maxnum; i++)
		{
			cin >> H.S[i];
			//cout << endl;
		}
		//heap H = {10, {10, 1, 9, 2, 8, 3, 7, 6, 4, 5}};
		//struct heap H = {maxnum};
		/*for (int i = 0; i<maxnum; i++)
		{
			H.S[i] = array[i];
		}*/
		//H.S[10] = array[10];

		//output the array to see if it input right
		/*cout << endl << "The beginning array: ";
		for (int i = 0; i<maxnum; i++)
		{
			cout << H.S[i] << " ";
		}
		cout << endl << endl;
		*/
		//cout << "I got here";

		//makeHeap(9, H);
		heapSort(maxnum-1, H, array, maxnum);

		//cout << "I got here";

		//output the array to see if it's sorted
		cout << "the end array: ";
		for (int i = 0; i<maxnum; i++)
		{
			cout << H.S[i] << " ";
		}
		cout << endl << endl;
		cout << "This program compared numbers " << comparecounter << " times." << endl;
		cout << "The size of the array is " << maxnum << endl;
	}

	else
	{
		string filename="";
		cout << "enter the name of the file: ";
		cin >> filename;
		
		struct heap H = {maxnum};

		ifstream my_file;
		my_file.open(filename);

		//cout << "How big is this file?" << endl; 
		//cin >> maxnum;
		
		cout << endl << "the array is " << maxnum << " entries long" << endl << endl;

		for (int i = 0; i < maxnum; i++)
		{
			my_file >> H.S[i];
		}

		my_file.close();

		//struct heap H = {maxnum};
		/*for (int i = 0; i<maxnum; i++)
		{
			H.S[i] = array[i];
		}*/

		//output the array to see if it input right
		cout << endl << "The beginning array: ";
		for (int i = 0; i<maxnum; i++)
		{
			cout << H.S[i] << " ";
		}
		cout << endl << endl;
	
		heapSort(maxnum-1, H, array, maxnum);

		//cout << "I got here";

	//output the array to see if it's sorted
	cout << "the end array: ";
	for (int i = 0; i<maxnum; i++)
	{
		cout << H.S[i] << " ";
	}
	cout << endl << endl;
	cout << "This program compared numbers " << comparecounter << " times." << endl;
	cout << "The number of entries is " << maxnum << endl;
	}
return 0;
}


void siftDown(heap& H, int i, int maxnum)
{
	int parent = i;
	int bigChild;
	int siftkey = H.S[i];
	bool found = false;

	//siftkey = H.S[i];
	//parent = i;
	//found = false;

	while (parent*2 <= H.heapsize && !found)
	{
		comparecounter++;
		if (parent*2 < H.heapsize && H.S[parent*2] < H.S[parent*2+1])
			{bigChild = parent*2 + 1;}
		else
			{bigChild = parent*2;}

		comparecounter++;
		if (siftkey < H.S[bigChild])
			{
			H.S[parent] = H.S[bigChild];
			parent = bigChild;
			
			/*cout << "this is step " << comparecounter << ": ";
			for (int i = 0; i<maxnum; i++)
				{
					cout << H.S[i] << " ";
				}
			cout << endl << endl;
			*/

			/*cout << "this is the parent: " << parent << endl;
			cout << "this is at parent: " << H.S[parent] << endl;
			cout << "this is at bigchild: " << H.S[bigChild] << endl;
			cout << "this is the bigChild: " << bigChild << endl;
			cout << "this is the siftkey: " << siftkey << endl;
			cout << "I have swapped " << swapcounter << " times" << endl << endl;
			cout << "I got here";*/
			}
		else
			found = true;
	}
	H.S[parent] = siftkey;
}

int root(heap& H, int maxnum)
{
	int keyOut;
	//int size = H.heapsize;

	keyOut = H.S[0];
	H.S[0] = H.S[H.heapsize];
	H.heapsize = H.heapsize - 1;
	//H.heapsize--;
	siftDown(H,0, maxnum);
	return keyOut;
}

void removeKeys(int n, heap& H, int S[], int maxnum)
{	
	for (int i = n; i >= 0; i--)
		{S[i] = root(H, maxnum);}
}

void makeHeap(int n, heap& H, int maxnum)
{
	H.heapsize = n;
	for (int i=floor(n/2); i>= 0; i--)
		{siftDown(H, i, maxnum);}
}

void heapSort (int n, heap& H, int S[], int maxnum)
{
	makeHeap(n, H, maxnum);
	removeKeys(n, H, H.S, maxnum);
}
