#include <iostream>
#include "CityGraph.h"
//Dominic B
//Assignment 10
//Hoenigman	
//Worked with Eric W

using namespace std;

int main (int argc, char *argv[])
{
	bool quit = false;
	CityGraph<string> cg;
	cg.buildGraph(argv[1]);
	while(quit != true)
	{
		int n = cg.printMenu();
		if(n == 1)
		{
			cg.displayEdges();
		}
		else if(n == 2)
		{
			cg.findDistricts();
		}
		else if(n == 3)
		{
			string start;
			string end;
			cout << "Enter a starting city:" << endl;
			cin.ignore();
			getline(cin, start);
			cout << "Enter an ending city:" << endl; 
			getline(cin, end);
			cg.shortestPath(start, end);
		}
		else if(n == 4)
		{	
			cout << "Shortest Distance" << endl;
		}
		else if(n == 5)
		{	
			cout << "Road Trip" << endl;
		}
		else if(n == 6)
		{	
			cout << "Goodbye!" << endl;
			quit = true;
		}
		
	}
}
