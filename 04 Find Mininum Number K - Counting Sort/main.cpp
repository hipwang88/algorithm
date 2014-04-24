#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void DisplayArray(int *pArray,int nSize)
{
	for (int i = 0; i < nSize; ++i)
		cout << pArray[i] <<' ';
	cout << endl;
}

int *createArray(int nCount,int nArea)
{
	int *pArray = new int[sizeof(int)*nCount];
	srand((int)time(NULL));
	for (int i = 0; i < nCount; ++i)
		pArray[i] = rand() % nArea;
}

void CountingSort(int *pArray,const int nSize,const int nArea)
{
	int *pArray_Copy = new int[nSize];
	int *pArray_Area = new int[nArea];
	memset(pArray_Copy,0,nSize);
	memset(pArray_Area,0,nSize);
	
	for (int i = 0; i < nSize; ++i)
	{
		pArray_Area[pArray[i]] += 1;
	}
	
	for (int i = 1; i < nArea; ++i)
	{
		pArray_Area[i] += pArray_Area[i-1];
	}
}

int main(int argc, char** argv) 
{
	int *pArray = createArray(50,60);
	
	DisplayArray(nArray,50);
	CountingSort(nArray,50,60);
	DisplayArray(nArray,5);
	
	return 0;
}
