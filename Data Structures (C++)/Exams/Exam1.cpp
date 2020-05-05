#include <iostream>

using namespace std;
//Dominic B
//Function that removes all even numbers from an array. Take length of array, and a pointer for number of odd numbers found 
//as argument and return pointer to new array. If not odd numbers print "No odds found." and return NULL.

int *removeEvens(int *a, int length, int *oddsfound)
{
	int newLen = 0;
	int oddsFound = 0;
	
	for (int i=0; i<=length; i++)
	{
		if (a[i] % 2 != 0)
		{
			oddsFound++;
		}
	}
	int *arrTemp = new int[oddsFound];
	for (int i=0; i<=length; i++)
	{
		if (a[i] % 2 != 0)
		{
			arrTemp[newLen]= a[i];
			newLen++;
		}
    } 
    for(int i=0; i<newLen; i++)
	{
		cout << arrTemp[i] << endl;
	}
	if(oddsFound == 0)
	{
		cout << "No odds found" <<endl;
	}
	return arrTemp;
}
