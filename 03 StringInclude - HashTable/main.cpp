#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool HashTable_StringInclude(string strA,string strB)
{
	bool bHash[26] = {false};
	int nStrNum = 0;
	int nLenA = strA.length();
	int nLenB = strB.length();
	
	if (nLenA < nLenB)
		return false;
		
	for (int i = 0; i < nLenB; ++i)
	{
		int nIndex = strB[i] - 'A';
		if (!bHash[nIndex])
		{
			bHash[nIndex] = true;
			++nStrNum;
		}
	}
	
	for (int i = 0; i < nLenA; ++i)
	{
		int nIndex = strA[i] - 'A';
		if (bHash[nIndex])
		{
			bHash[nIndex] = false;
			--nStrNum;
			
			if (nStrNum == 0)
				break;
		}
	}
	
	if (nStrNum == 0)
		return true;
	else 
		return false;
} 

int main(int argc, char** argv) 
{
	string strA,strB;
	cin >> strA >> strB;
	
	cout << HashTable_StringInclude(strA,strB) << endl;
	
	return 0;
}
