/*
prompt user for k
store in k
check k
if k bad repeat
prompt for  n
store n
check
repeat if bad
array
loop # time steps
store value in array at timestep
print values
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
	const int ROWS = 11;
	double array1[ROWS];
	
	double k = 0;
	int n = 0;

	cout << "Enter the constant of proportionality [0.0-1.0]:" << endl;
	cin >> k;
	
	while(k > 1 || k < 0)
	{
		cout << " Value not in range. Try again." << endl;
		cout << "Enter the constant of proportionality [0.0-1.0]:" << endl;
		cin >> k;
	
	}

	cout << "Enter the size of the initial population [1-1000]:" << endl;
	cin >> n;
	
	while(n > 1000 || n < 1)
	{
		cout << "Value not in range. Try again." << endl;
		cout << "Enter the size of the initial population [1-1000]:" << endl;
		cin >> n;
	
	}
	for(int i=0; i<ROWS; i++)
	{
		array1[i]=(double)(n*exp((double)i*k));
	}

	cout << setw(34);
	cout << endl << "Bacterial Growth Summary" << endl;
	cout << endl;
	cout << setw(15) << "Hour" << setw(18) << "Population" << endl;
	cout << setw(15) << "----" << setw(18) << "----------" << endl;
	
	for(int i=0; i<ROWS; i++)
	{
		cout << setw(12) << i << setw(20) << setprecision(6) << array1[i] << endl;
	}
	cout << endl;
	return 0;	
}
