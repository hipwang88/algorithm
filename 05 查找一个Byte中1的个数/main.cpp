#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	srand((int)time(NULL));
	int num = rand();
	int nCount = 0;
	
	cout << "Byte: 0x" << setbase(16) << num << " Count(1) = ";
	
	/*
		00100000 -1 = 00011111
		00100000 & 00011111 = 0
	*/
	while (num)
	{
		num &= (num-1);
		++nCount;
	}
	
	cout << nCount << endl;
	
	return 0;
}
