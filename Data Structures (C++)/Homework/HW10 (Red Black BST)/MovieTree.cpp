#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <istream>
#include <cstdlib>
#include "MovieTree.h"
//Dominic B
//Assignment 10
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
	cout << "6. Count the longest path" << endl;
	cout << "7. Quit" << endl;
	cin >> n;
	return n;
}
void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}
void MovieTree::printMovieInventory(MovieNode * node)
{
	if(node -> leftChild != nil)
	{
		printMovieInventory(node -> leftChild);
	}
	cout << "Movie: " << node -> title << " " << node -> quantity << endl;
	if(node -> rightChild != nil)
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
	
	if(node -> leftChild != nil)
	{
		countMovieNodes(node -> leftChild, c);
	}
	*c = *c + 1;
	if(node -> rightChild != nil)
	{
		countMovieNodes(node -> rightChild, c);
	}
}
void MovieTree::deleteMovieNode(string title)
{
	//cout << title << endl;
	MovieNode* foundMovie = search(title);
	if(foundMovie == nil)
	{
		cout << "Movie not found." << endl;
	}
	else if(foundMovie -> leftChild == nil)
	{
		if(foundMovie -> rightChild == nil)
		{
			if(foundMovie -> parent -> leftChild == foundMovie)
			{
				foundMovie -> parent -> leftChild = nil;
			}
			else
			{
				foundMovie -> parent -> rightChild = nil;
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
			if(min -> leftChild != nil)
			{
				min -> leftChild -> parent = min;
			}
		}
		else
		{
			min -> parent -> leftChild = min -> rightChild;
			if(min -> rightChild != nil)
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
			if(foundMovie -> rightChild != nil)
			{
				foundMovie -> rightChild -> parent = min;
			}
			if(foundMovie -> leftChild != nil)
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
	while(foundMovie != nil)
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
	return nil;
}
void MovieTree::findMovie(string title)
{
	MovieNode* foundMovie = search(title);
	if(foundMovie != nil)
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
	if(foundMovie != nil)
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
	root = nil;
	ifstream filename;
	filename.open(file);//Open file
	if(filename.is_open())
	{
		while (getline(filename,line))//read each line
		{
			MovieNode* x = new MovieNode();
			x -> isRed = true;
			
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
			MovieNode* parent = nil;
			x -> leftChild = nil;
			x -> rightChild = nil;
			while(tmp != nil)
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
			if(parent == nil)
			{
				//x -> isRed = false;
				x -> parent = nil;
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
			rbAddFixup(x);
		}
	}
	filename.close();
}
void MovieTree::DeleteAll(MovieNode * node)
{
	if(node -> leftChild != nil)
	{
		DeleteAll(node -> leftChild);
	}
	if(node -> rightChild != nil)
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
	while(node -> leftChild != nil)
	{
		//cout << "- " << node -> title << endl;
		node = node -> leftChild;
	}
	return node;
}
void MovieTree::rbAddFixup(MovieNode * node)
{
	MovieNode *x = node;
	while(x != root && x -> parent -> isRed == true)
	{
		if(x -> parent == x -> parent -> parent -> leftChild)
		{
			MovieNode* uncle = x -> parent -> parent -> rightChild;
			if(uncle -> isRed == true)
			{
				x -> parent -> isRed = false;
				if(uncle != nil)
				{
					uncle -> isRed = false;
				}
				x -> parent -> parent -> isRed = true;
				x = x -> parent -> parent;
			}
			else
			{
				if(x == x -> parent -> rightChild)
				{
					x = x -> parent;
					leftRotate(x);
					x -> parent -> isRed = false;
					x -> parent -> parent -> isRed = true;
					rightRotate(x -> parent -> parent);
				}
				else
				{
					x = x -> parent;
					rightRotate(x);
					x -> parent -> isRed = false;
					x -> parent -> parent -> isRed = true;
					leftRotate(x -> parent -> parent);
				}
			}
		}
		else
		{
			MovieNode* uncle = x -> parent -> parent -> leftChild;
			if(uncle -> isRed == true)
			{
				x -> parent -> isRed = false;
				if(uncle != nil)
				{
					uncle -> isRed = false;
				}
				x -> parent -> parent -> isRed = true;
				x = x -> parent -> parent;
			}
			else
			{
				if(x == x -> parent -> leftChild)
				{
					x = x -> parent;
					rightRotate(x);
					x -> parent -> isRed = false;
					x -> parent -> parent -> isRed = true;
					leftRotate(x -> parent -> parent);
				}
				else
				{
					x = x -> parent;
					leftRotate(x);
					x -> parent -> isRed = false;
					x -> parent -> parent -> isRed = true;
					rightRotate(x -> parent -> parent);
				}
			}
		}
	}
	root -> isRed = false;
}
void MovieTree::leftRotate(MovieNode * x)
{
	if(x -> rightChild == nil)
	{
		return;
	}
	else
	{
		MovieNode* y = x -> rightChild;
		if(y -> leftChild != nil)
		{
			x -> rightChild = y -> leftChild;
			y -> leftChild -> parent = x;
		}
		else
		{
			x -> rightChild = nil;
		}
		if(x -> parent != nil)
		{
			y -> parent = x -> parent;
		}
		if(x -> parent == nil)
		{
			root = y;
		}
		else
		{
			if(x == x -> parent -> leftChild)
			{
				x -> parent -> leftChild = y;
			}
			else
			{
				x -> parent -> rightChild = y;
			}
		}
		y -> leftChild = x;
		x -> parent = y;
	}
}
void MovieTree::rightRotate(MovieNode * x)
{
	/*MovieNode* x = y -> leftChild;
	cout << "1" << endl;
	y -> leftChild = x -> rightChild;
	if(x -> rightChild != nil)
	{
		x -> rightChild -> parent = y;
	}
	x -> parent = y -> parent;
	if(y -> parent == nil)
	{
		root = x;
	}
	else if(y == (y-> parent -> leftChild))
	{
		y -> parent -> leftChild = x;
	}
	else
	{
		y -> parent -> rightChild = x;
	}
	x -> rightChild = y;
	y -> parent = x;*/
	if(x -> leftChild == nil)
	{
		return;
	}
	else
	{
		MovieNode *y = x -> leftChild;
		if(y -> rightChild != nil)
		{
			x -> leftChild = y -> rightChild;
			y -> rightChild -> parent = x;
		}
		else
		{
			x -> leftChild = nil;
		}
		if(x -> parent != nil)
		{
			y -> parent = x -> parent;
		}
		if(x -> parent == nil)
		{
			root = y;
		}
		else
		{
			if(x == x -> parent -> leftChild)
			{
				x -> parent -> leftChild = y;
			}
			else
			{
				x -> parent -> rightChild = y;
			}
		}
		y -> rightChild = x;
		x -> parent = y;
	}
}
void MovieTree::rbDelete(MovieNode * z)
{
	bool nodeColor = z -> isRed;
	MovieNode* x;
	if(z != root)
	{
		if(z -> leftChild == nil && z -> rightChild == nil)
		{
			x = z -> parent -> leftChild;
			z -> parent -> leftChild = nil;
		}
		else if(z -> leftChild != nil && z -> rightChild != nil)
		{
			MovieNode* min = treeMinimum(z -> rightChild);
			nodeColor = min -> isRed;
			x = min -> rightChild;
			x -> parent = min;
			if(min == z -> rightChild)
			{
				z -> parent -> leftChild = min;
				min -> parent = z -> parent;
				min -> leftChild = z -> leftChild;
				min -> leftChild -> parent = min;
			}
			else
			{
				min -> parent -> leftChild = min -> rightChild;
				min -> rightChild -> parent = min -> parent;
				min -> parent = z -> parent;
				z -> parent -> leftChild = min;
				min -> leftChild = z -> leftChild;
				min -> rightChild = z -> rightChild;
				z -> rightChild -> parent = min;
				z -> leftChild -> parent = min;	
			}
			min -> isRed = z -> isRed;
		}
		else
		{
			x = z -> leftChild;
			z -> parent -> leftChild = x;
			x -> parent = z -> parent;
		}
	}
	else
	{
		root = nil;
	}
	if(nodeColor == false)
	{
		rbDeleteFixup(x);
	}
	delete z;
}
void MovieTree::rbDeleteFixup(MovieNode * node)
{
	MovieNode* s;
	while(node != root && node -> isRed == false)
	{
		if(node == node -> parent -> leftChild)
		{
			s = node -> parent -> rightChild;
			if(s -> isRed == true)
			{
				s -> isRed = false;
				node -> parent -> isRed = true;
				leftRotate(node -> parent);
				s = node -> parent -> rightChild;
			}
			if(s -> leftChild -> isRed == false && s -> rightChild -> isRed == false)
			{
				s -> isRed = true;
				node = node -> parent;
			}
			else if(s -> leftChild -> isRed == true && s -> rightChild -> isRed == false)
			{
				s -> leftChild -> isRed = false;
				s -> isRed = true;
				rightRotate(s);
				s = node -> parent -> rightChild;
			}
			else
			{
				s -> isRed = node -> parent -> isRed;
				node -> parent -> isRed = false;
				s -> rightChild -> isRed = false;
				leftRotate(node -> parent);
				node = root;
			}
		}
		else
		{
			s = node -> parent -> leftChild;
			if(s -> isRed == true)
			{
				s -> isRed = false;
				node -> parent -> isRed = true;
				rightRotate(node -> parent);
				s = node -> parent -> leftChild;
			}
			if(s -> rightChild -> isRed == false && s -> leftChild -> isRed == false)
			{
				s -> isRed = true;
				node = node -> parent;
			}
			else if(s -> rightChild -> isRed == true && s -> leftChild -> isRed == false)
			{
				s -> rightChild -> isRed = false;
				s -> isRed = true;
				leftRotate(s);
				s = node -> parent -> leftChild;
			}
			else
			{
				s -> isRed = node -> parent -> isRed;
				node -> parent -> isRed = false;
				s -> leftChild -> isRed = false;
				rightRotate(node -> parent);
				node = root;
			}
		}
		node -> isRed = false;
	}	
}
bool MovieTree::isValid()
{
	rbValid(root);
	return 0;
}
// Returns 0 if the tree is invalid, otherwise returns the black node height. 
int MovieTree::rbValid(MovieNode * node)
{
    int lh = 0;
    int rh = 0;

    // If we are at a nil node just return 1
    if (node == nil)
        return 1; 

    else
    {
        // First check for consecutive red links. 
        if (node->isRed)
        {
            if(node->leftChild->isRed || node->rightChild->isRed)
            {
                cout << "This tree contains a red violation" << endl;
                return 0;
            }
        }

        // Check for valid binary search tree. 
        if ((node->leftChild != nil && node->leftChild->title.compare(node->title) > 0) || (node->rightChild != nil && node->rightChild->title.compare(node->title) < 0))
        {
            cout << "This tree contains a binary tree violation" << endl;
            return 0;
        }

        // Deteremine the height of let and right children. 
        lh = rbValid(node->leftChild);
        rh = rbValid(node->rightChild);

        // black height mismatch 
        if (lh != 0 && rh != 0 && lh != rh)
        {
            cout << "This tree contains a black height violation" << endl;
            return 0;
        }

        // If neither height is zero, incrament if it if black. 
        if (lh != 0 && rh != 0)
        {
                if (node->isRed)
                    return lh;
                else
                    return lh+1;
        }

        else
            return 0;

    }
}
MovieTree::MovieTree()
{	
	MovieNode* nil = new MovieNode(0," ",0,0);
	nil -> parent = nil;
	nil -> leftChild = nil;
	nil -> rightChild = nil;
	nil -> isRed = false;
	
	root = nil;
}
MovieTree::~MovieTree()
{	
}


