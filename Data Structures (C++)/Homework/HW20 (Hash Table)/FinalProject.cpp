#include <iostream>
#include "BallMap.h"
//Dominic B
//Final Project
//Hoenigman	
//Worked with Eric W

using namespace std;

int main (int argc, char *argv[])
{
	bool quit = false;
	string first, last;
	BallMap bm (argv[2]);
	bm.buildTable(argv[1]);
	while(quit != true)
	{
		int n = bm.printMenu();
		if(n == 1)
		{
			cout << "Enter first name:" << endl; 
			cin.ignore();
			getline(cin, first);
			cout << "Enter last name:" << endl;
			getline(cin, last);
			bm.findPlayer(first, last);
		}
		else if(n == 2)
		{	
			cout << "Goodbye!" << endl;
			quit = true;
		}
		
	}
}
