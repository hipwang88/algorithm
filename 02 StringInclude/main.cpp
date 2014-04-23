#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool IsStringInclude(string strA,string strB)
{
	int nLenA = strA.length();
	int nLenB = strB.length();
	
	if (nLenA < nLenB)
		return false;
	
	return true;
}

int main(int argc, char** argv) 
{
	string strA,strB;
	
	cin >> strA >> strB;
	
	cout << IsStringInclude(strA,strB) << endl;
	
	return 0;
}
