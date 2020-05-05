#include <iostream>
#include "Queue.h"
//Dominic B
//Assignment 6
//Hoenigman	
//Worked with Eric W

using namespace std;

int main (int argc, char *argv[])
{
	bool quit = false;
	string input;
	Queue qs(10);
	while(quit != true)
	{
		int n = qs.printMenu();
		if(n == 1)
		{
			cout << "word: ";
			cin.ignore();
			getline(cin, input);
			qs.enqueue(input);
		}
		else if(n == 2)
		{
			qs.dequeue();
		}
		else if(n == 3)
		{
			qs.printQueue();
		}
		else if(n == 4)
		{
			cout << "sentence: ";
			cin.ignore();
			getline(cin, input);
			qs.enqueue(input);
		}
		else if(n == 5)
		{	
			cout << "Goodbye!" << endl;
			quit = true;
		}
		
	}
}
