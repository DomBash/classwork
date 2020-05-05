#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <istream>
#include <cstdlib>
#include "MovieTree.h"
//Dominic B
//Assignment 8
//Hoenigman	
//Worked with Eric W

using namespace std;

int MovieTree::printMenu()
{
	int n;
	cout << "======Main Menu======" << endl;
	cout << "1. Find a movie" << endl;
	cout << "2. Rent a movie" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Delete a movie" << endl;
	cout << "5. Count the movies" << endl;
	cout << "6. Quit" << endl; 
	cin >> n;
	return n;
}
void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}
void MovieTree::printMovieInventory(MovieNode * node)
{
	if(node -> leftChild != NULL)
	{
		printMovieInventory(node -> leftChild);
	}
	cout << "Movie: " << node -> title << " " << node -> quantity << endl;
	if(node -> rightChild != NULL)
	{
		printMovieInventory(node -> rightChild);
	}
}
int MovieTree::countMovieNodes()
{	
	int count = 0;
	int* c = 0;
	c = &count;
	countMovieNodes(root, c);
	return count;
}
void MovieTree::countMovieNodes(MovieNode *node, int* c)
{
	
	if(node -> leftChild != NULL)
	{
		countMovieNodes(node -> leftChild, c);
	}
	*c = *c + 1;
	if(node -> rightChild != NULL)
	{
		countMovieNodes(node -> rightChild, c);
	}
}
void MovieTree::deleteMovieNode(string title)
{
	//cout << title << endl;
	MovieNode* foundMovie = search(title);
	if(foundMovie == NULL)
	{
		cout << "Movie not found." << endl;
	}
	else if(foundMovie -> leftChild == NULL)
	{
		if(foundMovie -> rightChild == NULL)
		{
			if(foundMovie -> parent -> leftChild == foundMovie)
			{
				foundMovie -> parent -> leftChild = NULL;
			}
			else
			{
				foundMovie -> parent -> rightChild = NULL;
			}
		}
		else
		{
			if(foundMovie -> parent -> rightChild == foundMovie)
			{
				foundMovie -> parent -> rightChild = foundMovie -> rightChild;
			}
			else
			{
				foundMovie -> parent -> leftChild = foundMovie -> rightChild;
			}
			foundMovie -> rightChild -> parent = foundMovie -> parent;
		}
	}
	else
	{	
		//cout << min -> title << " - " << foundMovie -> title << endl;
		MovieNode* min = treeMinimum(foundMovie -> rightChild);
		if(min == foundMovie -> rightChild)
		{
			if(foundMovie -> parent -> leftChild == foundMovie)
			{
				foundMovie -> parent -> leftChild = min;
			}
			else
			{
				foundMovie -> parent -> rightChild = min;
			}
			min -> parent = foundMovie -> parent;
			min -> leftChild = foundMovie -> leftChild;
			if(min -> leftChild != NULL)
			{
				min -> leftChild -> parent = min;
			}
		}
		else
		{
			min -> parent -> leftChild = min -> rightChild;
			if(min -> rightChild != NULL)
			{
				min -> rightChild -> parent = min -> parent;
			}
			min -> parent = foundMovie -> parent;
			if(foundMovie -> parent -> leftChild == min)
			{
				foundMovie -> parent -> leftChild = min;
			}
			else
			{
				foundMovie -> parent -> rightChild = min;
			}
			min -> leftChild = foundMovie -> leftChild;
			min -> rightChild = foundMovie -> rightChild;
			if(foundMovie -> rightChild != NULL)
			{
				foundMovie -> rightChild -> parent = min;
			}
			if(foundMovie -> leftChild != NULL)
			{
				foundMovie -> leftChild -> parent = min;
			}
		}
		delete foundMovie;
}
	
}
void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity)
{
	cout << "Adding: " << title << endl;
}
MovieNode* MovieTree::search(string title)
{
	MovieNode* foundMovie = root;
	while(foundMovie != NULL)
	{
		if(foundMovie -> title < title)
		{
			foundMovie = foundMovie -> rightChild;
		}
		else if(foundMovie -> title > title)
		{
			foundMovie = foundMovie -> leftChild;
		}
		else
		{
			return foundMovie;
		}
	}
	return NULL;
}
void MovieTree::findMovie(string title)
{
	MovieNode* foundMovie = search(title);
	if(foundMovie != NULL)
	{
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking:" << foundMovie -> ranking << endl;
		cout << "Title:" << foundMovie -> title << endl;
		cout << "Year:" << foundMovie -> year << endl;
		cout << "Quantity:" << foundMovie -> quantity << endl;
	}
	else
	{
		cout << "Movie not found." << endl; 
	}
	
}
void MovieTree::rentMovie(string title)
{
	MovieNode* foundMovie = search(title);
	if(foundMovie != NULL)
	{
		//If movie is in stock
		foundMovie -> quantity--;
		cout << "Movie has been rented." << endl;
		cout << "Movie Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking:" << foundMovie -> ranking << endl;
		cout << "Title:" << foundMovie -> title << endl;
		cout << "Year:" << foundMovie -> year << endl;
		cout << "Quantity:" << foundMovie -> quantity << endl;
		if(foundMovie -> quantity == 0)
		{
			deleteMovieNode(title);
		}
	}
	else
	{
		cout << "Movie not found." << endl; 
	}
}
void MovieTree::buildTree(char* file) 
{
	string line;
	root = NULL;
	ifstream filename;
	filename.open(file);//Open file
	if(filename.is_open())
	{
		while (getline(filename,line))//read each line
		{
			MovieNode* x = new MovieNode();
			
			int delimiter = line.find(",");//find , in the line
			x -> ranking = atoi (line.substr(0,delimiter).c_str());
			
			line = line.substr(delimiter+1);
			delimiter = line.find(",");
			x -> title = line.substr(0,delimiter);
			
			line = line.substr(delimiter+1);
			delimiter = line.find(",");
			x -> year = atoi (line.substr(0,delimiter).c_str());
			
			line = line.substr(delimiter+1);
			delimiter = line.find(",");
			x -> quantity = atoi (line.substr(0,delimiter).c_str());
			
			MovieNode* tmp = root;
			MovieNode* parent = NULL;
			while(tmp != NULL)
			{
				parent = tmp;
				if(x -> title < tmp -> title)
				{
					tmp = tmp -> leftChild;
				}
				else
				{
					tmp = tmp -> rightChild;
				}
			}
			if(parent == NULL)
			{
				root = x;
			}
			else if(x -> title < parent -> title)
			{
				parent -> leftChild = x;
				x -> parent = parent;
			}
			else
			{
				parent -> rightChild = x;
				x -> parent = parent;
			}
			x -> leftChild = NULL;
			x -> rightChild = NULL;
		}
	}
	filename.close();
}
void MovieTree::DeleteAll(MovieNode * node)
{
	if(node -> leftChild != NULL)
	{
		DeleteAll(node -> leftChild);
	}
	if(node -> rightChild != NULL)
	{
		DeleteAll(node -> rightChild);
	}
	cout << "Deleting: " << node -> title << endl; 
	delete node;
}
void MovieTree::DeleteAll()
{
	DeleteAll(root);
}
MovieNode* MovieTree::treeMinimum(MovieNode *node)
{
	while(node -> leftChild != NULL)
	{
		//cout << "- " << node -> title << endl;
		node = node -> leftChild;
	}
	return node;
}
MovieTree::MovieTree()
{	
}
MovieTree::~MovieTree()
{	
}


