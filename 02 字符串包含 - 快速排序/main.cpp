#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int partition(string &strValue,int lo,int hi)
{
	char key = strValue[hi];
	int index = lo-1;
	
	for (int i = lo; i < hi; ++i)
	{
		if (key >= strValue[i])
		{
			++index;
			swap(strValue[index],strValue[i]);
		}
	}
	swap(strValue[index+1],strValue[hi]);
	
	return index+1;
}

void quicksort(string &strValue,int lo,int hi)
{
	if (lo < hi)
	{
		int k = partition(strValue,lo,hi);
		quicksort(strValue,lo,k-1);
		quicksort(strValue,k+1,hi);
	}
}

bool IsStringInclude(string strA,string strB)
{
	int posA = 0,posB = 0;
	int nLenA = strA.length();
	int nLenB = strB.length();
	
	if (nLenA < nLenB)
		return false;
	
	while (posA < nLenA && posB < nLenB)
	{
		while (strA[posA] < strB[posB] && posA < nLenA-1)
			posA++;
			
		if (strA[posA] != strB[posB])
			break;
			
		posB++;
	}
	
	if (posB == nLenB)
		return true;
	else
		return false;
}

int main(int argc, char** argv) 
{
	string strA,strB;
	
	cin >> strA >> strB;
	
	quicksort(strA,0,strA.length()-1);
	quicksort(strB,0,strB.length()-1);
	cout << IsStringInclude(strA,strB) << endl;
	
	return 0;
}
