#include <iostream>
#include "CommunicationNetwork.h"
//Dominic B
//Assignment 5
//Hoenigman	
//Worked with Eric W

using namespace std;

int main (int argc, char *argv[])
{
	bool quit = false;
	bool netBuilt = false;
	while(quit != true)
	{
		CommunicationNetwork c;
		int n = c.printMenu();
		//cout << n << endl;
		if(n == 1)
		{
			c.buildNetwork();
			netBuilt = true;
		}
		else if(n == 2)
		{
			c.printNetwork();
		}
		else if(n == 3)
		{
			c.transmitMsg(argv[1]);
		}
		else if(n == 4)
		{
			string cityNew, cityPrevious;
			cout << "Enter a city name: " << endl;
			cin.ignore();
			getline(cin, cityNew);
			cout << "Enter a previous city name: " <<endl;
			getline(cin, cityPrevious);
			c.addCity(cityPrevious, cityNew);
		}
		else if(n == 5)
		{	
			string cityToD;
			cout << "Enter a city name: " << endl;
			cin.ignore();
			getline(cin, cityToD);
			c.deleteCity(cityToD);
		}
		else if(n == 6)
		{	
			c.deleteNetwork();
			netBuilt = false;
		}
		else if(n == 7)
		{	
			cout << "Goodbye!" << endl;
			if(netBuilt == true)
			{
				c.deleteNetwork();
			}
			quit = true;
		}
		
	}
}
