#include <iostream>
#include <fstream>
#include <string> 
#include <istream>
#include <sstream>
#include "CommunicationNetwork.h"
//Dominic B
//Assignment 4
//Hoenigman	
//Worked with Eric W

using namespace std;

void CommunicationNetwork::addCity(string cityPrevious, string cityNew)
{
	City *tmp = head;
	string message;
	while(tmp -> cityName != cityPrevious)
	{
		tmp = tmp -> next;
	}
	City *x = new City(cityNew, NULL, message);
	x -> next = tmp -> next;
	tmp -> next = x;
	
}
int CommunicationNetwork::printMenu()
{
	int n;
	cout <<	"======Main Menu======"	<< endl;					
	cout <<	"1. Build Network" << endl;					
	cout <<	"2. Print Network Path"	<< endl;					
	cout <<	"3. Transmit Message Coast-To-Coast" <<	endl;					
	cout <<	"4. Add City" << endl;	
	cout <<	"5. Quit" << endl;	
	cin >> n;
	return n;
}
void CommunicationNetwork::buildNetwork()
{
	string message;
	City *x = new City("Los Angeles", NULL, message);
	City *x2 = new City("Phoenix", NULL, message);
	x -> next = x2;
	City *x3 = new City("Denver", NULL, message);
	x2 -> next = x3;
	City *x4 = new City("Dallas", NULL, message);
	x3 -> next = x4;
	City *x5 = new City("St. Louis", NULL, message);
	x4 -> next = x5;
	City *x6 = new City("Chicago", NULL, message);
	x5 -> next = x6;
	City *x7 = new City("Atlanta", NULL, message);
	x6 -> next = x7;
	City *x8 = new City("Washington, D.C.", NULL, message);
	x7 -> next = x8;
	City *x9 = new City("New York", NULL, message);
	x8 -> next = x9;
	City *x10 = new City("Boston", NULL, message);
	x9 -> next = x10;
	
	City *tmp = x;
	cout << "===CURRENT PATH===" << endl;
	while(tmp != NULL)
	{	
		cout << tmp->cityName << " -> "; //for all nodes in network						
		tmp = tmp -> next;
	}
	cout << "NULL" << endl;	
	cout << "==================" << endl;
	head = x;
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
					sender->message = check;
					cout<<sender->cityName<<" received "<<sender->message<<endl;	
					sender -> message.empty();					
					sender = sender -> next;
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
	cout << "===CURRENT PATH===" << endl;
	while(tmp != NULL)
	{	
		cout << tmp->cityName << " -> "; //for all nodes in network						
		tmp = tmp -> next;
	}
	cout << "NULL" << endl;	
	cout << "==================" << endl;
}

CommunicationNetwork::CommunicationNetwork(){}
CommunicationNetwork::~CommunicationNetwork(){}

