/*
SET change to user cla
DISPLAY "CHANGE" cents in coins:
SET quarters to change/25
SET change%25
SET dimes to change/10
SET change%10
SET nickols change/5
SET pennies change%5
DISPLAY "quarters" quarters
DISPLAY "dimes" dimes
DISPLAY "nickels" nickels
DISPLAY "pennies" pennies
*/

#include <iostream>
#include <cstdlib>
using namespace std;


int main(int argc, char* argv[])
{
	int change = atoi(argv[1]);
	cout << change << endl;
	int quarters = change/25;
	change = change % 25;
	int dimes = change/10;
	change = change % 10;
	int nickels = change/5;
	int pennies = change % 5;
	cout << quarters << " quarters" << endl;
	cout << dimes << " dimes" << endl;
	cout << nickels << " nickels" << endl;
	cout << pennies << " pennies" << endl;
	return 0;
}


