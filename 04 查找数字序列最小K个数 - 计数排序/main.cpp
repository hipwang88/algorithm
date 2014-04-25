#include <iostream>
#include <time.h>
#include <memory.h>
#include <stdlib.h>
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
	
	return pArray;
}

void CountingSort(int *pArray,const int nSize,const int nArea)
{
	int *pArray_Copy = new int[nSize];
	int *pArray_Area = new int[nArea];
	
	memset(pArray_Copy,0,nSize*sizeof(int));
	memset(pArray_Area,0,nArea*sizeof(int));
	
	for (int i = 0; i < nSize; ++i)
	{
		pArray_Area[pArray[i]] += 1;
	}
	
	for (int i = 1; i < nArea; ++i)
	{
		pArray_Area[i] += pArray_Area[i-1];
	}
	
	for (int i = nSize-1; i >=0; --i)
	{
		pArray_Copy[pArray_Area[pArray[i]]] = pArray[i];
		pArray_Area[pArray[i]]--;
	}
	
	for (int i =0; i < nSize; ++i)
		pArray[i] = pArray_Copy[i];
}

int *FindMininumKItems(int *pArray,const int K)
{
	int *pKItems = new int[K];
	memset(pKItems,0,sizeof(int)*K);
	
	for (int i = 0; i < K; ++i)
		pKItems[i] = pArray[i];
		
	return pKItems;
}

int main(int argc, char** argv) 
{
	int *pArray = createArray(100,120);
	int *pKItems = new int[10];
	
	DisplayArray(pArray,100);
	CountingSort(pArray,100,120);
	DisplayArray(pArray,100);
	
	pKItems = FindMininumKItems(pArray,10);
	DisplayArray(pKItems,10);
	
	return 0;
}
