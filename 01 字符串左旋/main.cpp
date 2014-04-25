#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

void LeftString(string &strValue,int nCount)
{
	int nLen = strValue.length();
	int nRealCount = nCount % nLen;
	char strTemp;
	
	if ((nLen == 0) && (nRealCount <= 0))
		return ;
		
	for (int i = 0; i < nRealCount/2; i++)
	{
		strTemp = strValue[nRealCount-i-1];
		strValue[nRealCount-i-1] = strValue[i];
		strValue[i] = strTemp;
	}
	
	for (int i = 0; i < (nLen-nRealCount)/2; i++)
	{
		strTemp = strValue[nLen-i-1];
		strValue[nLen-i-1] = strValue[i+nRealCount];
		strValue[i+nRealCount] = strTemp;
	}
		
	for (int i = 0; i < nLen/2; i++)
	{
		strTemp = strValue[nLen-i-1];
		strValue[nLen-i-1] = strValue[i];
		strValue[i] = strTemp;
	}
}

int main(int argc, char** argv) 
{	
	string strTest = "abcdefghijklmnopqrstuvwxyz";
	
	LeftString(strTest,35);
	
	cout << strTest << endl;
	
	return 0;
}
