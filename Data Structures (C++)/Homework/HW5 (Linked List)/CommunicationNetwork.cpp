#include <iostream>
#include <fstream>
#include <string> 
#include <istream>
#include <sstream>
#include "CommunicationNetwork.h"
//Dominic B
//Assignment 5
//Hoenigman	
//Worked with Eric W

using namespace std;

void CommunicationNetwork::deleteCity(string cityToD)
{
	City *tmp = head;
	string message;
	City *prev = head;
	City *next = head;
	while(tmp -> cityName != cityToD)
	{
		tmp = tmp -> next;
	}
	if(cityToD == tail -> cityName)
	{
		prev = tmp -> previous;
		next = tmp -> next;
		prev -> next = next;
		tail = prev;
	}
	else if(cityToD == head -> cityName)
	{
		prev = tmp -> previous;
		next = tmp -> next;
		next -> previous = prev;
		head = next;
	}
	else if(tmp -> cityName == cityToD)
	{
		prev = tmp -> previous;
		next = tmp -> next;
		prev -> next = next;
		next -> previous = prev;	
	}
	delete tmp;
}
void CommunicationNetwork::deleteNetwork()
{	
	City *tmp = head;
	while(tmp != NULL)
	{
		City *tmp1 = tmp;
		tmp -> next = tmp1 -> next;
		cout<<"deleting "<<tmp->cityName<<endl;	
		delete tmp1;
		tmp = tmp -> next;
	}
	head = NULL;
}

void CommunicationNetwork::addCity(string cityPrevious, string cityNew)
{
	City *tmp = head;
	string message;
	City *x = new City(cityNew, NULL, NULL, message);
	if(cityPrevious == "First")
	{
		head = x;
		x -> next = tmp;
		tmp -> previous = x;	
	}
	else
	{
		while(tmp -> cityName != cityPrevious)
		{
			tmp = tmp -> next;
		}
		if(tmp -> cityName == cityPrevious)
		{
			x -> next = tmp -> next;
			x -> previous = tmp;
			tmp -> next = x;
			
		}
		if(cityPrevious == tail -> cityName)
		{
			tail = x;
		}
	}
}
int CommunicationNetwork::printMenu()
{
	int n;
	cout <<	"======Main Menu======"	<< endl;					
	cout <<	"1. Build Network" << endl;					
	cout <<	"2. Print Network Path"	<< endl;					
	cout <<	"3. Transmit Message Coast-To-Coast-To-Coast" <<	endl;					
	cout <<	"4. Add City" << endl;	
	cout <<	"5. Delete City" << endl;	
	cout <<	"6. Clear Network" << endl;	
	cout <<	"7. Quit" << endl;	
	cin >> n;
	return n;
}
void CommunicationNetwork::buildNetwork()
{
	string message;
	City *x = new City("Los Angeles",NULL, NULL, message);
	City *x2 = new City("Phoenix", NULL, x, message);
	x -> next = x2;
	City *x3 = new City("Denver", NULL, x2, message);
	x2 -> next = x3;
	City *x4 = new City("Dallas", NULL, x3, message);
	x3 -> next = x4;
	City *x5 = new City("St. Louis", NULL, x4, message);
	x4 -> next = x5;
	City *x6 = new City("Chicago", NULL, x5, message);
	x5 -> next = x6;
	City *x7 = new City("Atlanta", NULL, x6, message);
	x6 -> next = x7;
	City *x8 = new City("Washington, D.C.", NULL, x7, message);
	x7 -> next = x8;
	City *x9 = new City("New York", NULL, x8, message);
	x8 -> next = x9;
	City *x10 = new City("Boston", NULL, x9, message);
	x9 -> next = x10;
	
	City *tmp = x;
	cout << "===CURRENT PATH===" << endl;
	cout << "NULL <- ";
	while(tmp -> next != NULL)
	{	
		cout << tmp->cityName << " <-> "; //for all nodes in network						
		tmp = tmp -> next;
	}
	cout << tmp -> cityName << " -> ";
	cout << "NULL" << endl;	
	cout << "==================" << endl;
	head = x;
	tail = x10;
}
void CommunicationNetwork::transmitMsg(char* file) //this is like a string
{
	ifstream filename;
	filename.open(file);//Open file
	string check;
	if (filename.is_open())
	{
		while (filename>>check) //read each line
		{
			City *sender = head;
			if(sender != NULL)
			{
				while(sender != NULL)
				{	
					sender-> message = check;
					cout<<sender->cityName<<" received "<<sender->message<<endl;	
					sender -> message.empty();					
					sender = sender -> next;
				}
				sender = tail;
				sender = sender -> previous;
				while(sender != NULL)
				{
					sender-> message = check;
					cout<<sender->cityName<<" received "<<sender->message<<endl;	
					sender -> message.empty();					
					sender = sender -> previous;;
				}
			}
			else
			{
				cout << "Empty list" << endl;
			}
			
			
		}
	}
}
void CommunicationNetwork::printNetwork()
{
	City *tmp = head;
	if(tmp == NULL)
	{
		cout << "===CURRENT PATH===" << endl;
		cout << "NULL" << endl;
		cout << "==================" << endl;
	}
	else
	{
		cout << "===CURRENT PATH===" << endl;
		cout << "NULL <- ";
		while(tmp -> next != NULL)
		{	
			cout << tmp->cityName << " <-> "; //for all nodes in network						
			tmp = tmp -> next;
		}
		cout << tmp -> cityName << " -> ";
		cout << "NULL" << endl;	
		cout << "==================" << endl;
	}
}

CommunicationNetwork::CommunicationNetwork()
{	
}
CommunicationNetwork::~CommunicationNetwork()
{
	
}

