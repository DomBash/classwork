#include <iostream>
#include "MovieTree.h"
//Dominic B
//Assignment 8
//Hoenigman	
//Worked with Eric W

using namespace std;

int main (int argc, char *argv[])
{
	bool quit = false;
	string title;
	MovieTree mt;
	mt.buildTree(argv[1]);
	while(quit != true)
	{
		int n = mt.printMenu();
		if(n == 1)
		{
			cout << "Enter title:" << endl; 
			cin.ignore();
			getline(cin, title);
			mt.findMovie(title);
		}
		else if(n == 2)
		{
			cout << "Enter title:" << endl; 
			cin.ignore();
			getline(cin, title);
			mt.rentMovie(title);
		}
		else if(n == 3)
		{
			mt.printMovieInventory();
		}
		else if(n == 4)
		{
			cout << "Enter title:" << endl; 
			cin.ignore();
			getline(cin, title);
			mt.deleteMovieNode(title);
		}
		else if(n == 5)
		{	
			cout << "Tree contains: " << mt.countMovieNodes() << " movies." << endl; 
		}
		else if(n == 6)
		{	
			cout << "Goodbye!" << endl;
			mt.DeleteAll();
			quit = true;
		}
		
	}
}
