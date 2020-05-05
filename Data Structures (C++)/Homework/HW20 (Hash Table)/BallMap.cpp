#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <istream>
#include <cstdlib>
#include <vector>
#include "BallMap.h"
//Dominic B
//Final Project
//Hoenigman	
//Worked with Eric W

using namespace std;

int BallMap::printMenu()
{
	int n;
	cout << "======Main Menu======" << endl;
	cout << "1. Query hash table" << endl;
	cout << "2. Quit Program" << endl;
	cin >> n;
	return n;
}

void BallMap::buildTable(char* file) 
{
	string line;
	bool count = 0;
	ifstream filename;
	filename.open(file);//Open file
	if(filename.is_open())
	{
		while (getline(filename,line))//read each line
		{
			if(count != 0)
			{
				
				PlayerNode* x = new PlayerNode();
				yearS* y = new yearS();
				
				int delimiter = line.find(",");//find , in the line
				y -> year = atoi(line.substr(0,delimiter).c_str());
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				y -> team = line.substr(0,delimiter);
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				y -> state = line.substr(0,delimiter);
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				y -> sal = atoi (line.substr(0,delimiter).c_str());
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x -> fName = line.substr(0,delimiter);
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x -> lName = line.substr(0,delimiter);
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x -> born = atoi (line.substr(0,delimiter).c_str());
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x ->  country = line.substr(0,delimiter);
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x -> weight = atoi (line.substr(0,delimiter).c_str());
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x -> height = atoi (line.substr(0,delimiter).c_str());
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x ->  bats = line.substr(0,delimiter);
				
				line = line.substr(delimiter+1);
				delimiter = line.find(",");
				x -> throws = line.substr(0,delimiter);
				
				x -> TnS.push_back(y);
				
				//GC++;
				x -> sum = hashSum(x -> fName, x -> lName);
				
				chainAdd(x,y);
				addrAdd(x,y);
			}
			else
			{
				count = 1;
			}
		}
	}
	cout << "Hash table size: " << arrSize << endl;
	cout << "Collisions using open addressing: " << aCollisions << endl;
	cout << "Collisions using chaining: " << cCollisions << endl;
	cout << "Search operations using open addressing: " << aOps << endl;
	cout << "Search operations using chaining: " << cOps << endl;
	//cout << GC << endl;
	//cout << arrSize << endl;
	filename.close();
}
void BallMap::chainAdd(PlayerNode* x, yearS* y)
{
	int sum = x -> sum;
	bool found = false;
	if(chainArray[sum] != NULL)
	{
		if(chainArray[sum] -> lName == x -> lName && chainArray[sum] -> fName == x -> fName && chainArray[sum] -> born == x -> born)
		{
			chainArray[sum] -> TnS.push_back(y);
		}
		else if(chainArray[sum] -> next != NULL)
		{
			PlayerNode* tmp = chainArray[sum];
			while(tmp -> next != NULL)
			{
				tmp = tmp -> next;
				if(tmp -> lName == x -> lName && tmp -> fName == x -> fName && tmp -> born == x -> born)
				{
					found = true;
					tmp -> TnS.push_back(y);
				}
			}
		}
		if(found == false)
		{
			cCollisions++;
			PlayerNode* tmp = chainArray[sum];
			while(tmp -> next != NULL)
			{
				cOps++;
				tmp = tmp -> next;
			}
			tmp -> next = x;
		}
	}
	else
	{
		chainArray[sum] = x;
	}
}
int BallMap::hashSum(string first, string last)
{
	int sum = 0;
	string key = first + last;
	int length = key.length();
	for(int i = 0; i < length; i++)
	{
		sum = sum + int(key[i]);
	}
	sum = sum % arrSize;
	return sum;
}
void BallMap::addrAdd(PlayerNode* x, yearS* y)
{
	int sum = x -> sum;
	if(addrArray[sum].born != 0)
	{
		if(addrArray[sum].lName == x -> lName && addrArray[sum].fName == x -> fName && addrArray[sum].born == x -> born)
		{
			addrArray[sum].TnS.push_back(y);
		}
		else
		{
			aCollisions++;
			bool found = false;
			while(found == false)
			{
				aOps++;
				sum++;
				if(sum == arrSize)
				{
					sum = 0;
				}
				if(addrArray[sum].born == 0)
				{
					addrArray[sum] = *x;
					found = true;
				}
				else if(addrArray[sum].lName == x -> lName && addrArray[sum].fName == x -> fName && addrArray[sum].born == x -> born)
				{
					addrArray[sum].TnS.push_back(y);
					found = true;
				}
			}
			if(found == false)
			{
				addrArray[sum] = *x;
			}
		}
	}
	else
	{
		GC++;
		addrArray[sum] = *x;
	}
}
void BallMap::findPlayer(string first, string last)
{
	cOps = 0;
	aOps = 0;
	int sum = hashSum(first, last);
	int ogSum = sum;
	bool found = false;
	while(found == false)
	{
		if(addrArray[sum].lName == last && addrArray[sum].fName == first)
		{
			cout << endl;
			cout << "Search operations using open addressing: " << aOps << endl;
			cout << endl;
			cout << "First Name: " << addrArray[sum].fName << endl;
			cout << "Last Name: " << addrArray[sum].lName << endl;
			cout << "Year born: " << addrArray[sum].born<< endl;
			cout << "Country born: " << addrArray[sum].country << endl;
			cout << "Weight: " << addrArray[sum].weight << endl;
			cout << "Height: " << addrArray[sum].height << endl;
			cout << "Bats: " << addrArray[sum].bats << endl;
			cout << "Throws: " << addrArray[sum].throws<< endl;
			cout << "Teams and Salary:" << endl;
			int size = addrArray[sum].TnS.size();
			for(int i = 0; i < size; i++)
			{
				cout << addrArray[sum].TnS[i] -> team;
				cout << ", " << addrArray[sum].TnS[i] -> year;
				cout << ", " << addrArray[sum].TnS[i] -> sal;
				cout << ", " << addrArray[sum].TnS[i] -> state;
				cout << endl;
			}
			found = true;
		}
		else
		{
			aOps++;
			sum++;
			if(sum == ogSum)
			{
				cout << "Player not found" << endl;
				return;
			}
			if(sum == arrSize)
			{
				sum = 0;
			}
		}	
	}
	sum = ogSum;
	found = false;
	PlayerNode* tmp = chainArray[sum];
	while(found == false)
	{
		if(tmp -> lName == last && tmp -> fName == first)
		{
			cout << endl;
			cout << "Search operations using chaining: " << cOps << endl;
			cout << endl;
			cout << "First Name: " << tmp -> fName << endl;
			cout << "Last Name: " << tmp -> lName << endl;
			cout << "Year born: " << tmp -> born << endl;
			cout << "Country born: " << tmp -> country << endl;
			cout << "Weight: " << tmp -> weight << endl;
			cout << "Height: " << tmp -> height << endl;
			cout << "Bats: " << tmp -> bats << endl;
			cout << "Throws: " << tmp -> throws << endl;
			cout << "Teams and Salary:" << endl;
			int size = tmp -> TnS.size();
			for(int i = 0; i < size; i++)
			{
				cout << tmp -> TnS[i] -> team;
				cout << ", " << tmp -> TnS[i] -> year;
				cout << ", " << tmp -> TnS[i] -> sal;
				cout << ", " << tmp -> TnS[i] -> state;
				cout << endl;
			}
			found = true;
		}
		else
		{
			cOps++;
			tmp = tmp -> next;
			if(tmp -> next == NULL)
			{
				cout << "Player not found" << endl;
				found = true;
			}
		}
	}	
}
BallMap::BallMap(char* size)
{	
	
	arrSize = atoi(size);
	cCollisions = 0;
	aCollisions = 0;
	cOps = 0;
	aOps = 0;
	GC = 0;
	chainArray = new PlayerNode* [arrSize];
	addrArray = new PlayerNode [arrSize];
}
BallMap::~BallMap()
{	
}
