#include <iostream>
#include <fstream>
#include <string> 
#include <istream>
#include <sstream>
#include "Queue.h"
//Dominic B
//Assignment 6
//Hoenigman	
//Worked with Eric W

using namespace std;

int Queue::printMenu()
{
	int n;
	cout <<	"======Main Menu====="	<< endl;					
	cout <<	"1. Enqueue word" << endl;					
	cout <<	"2. Dequeue word"	<< endl;					
	cout <<	"3. Print queue" <<	endl;					
	cout <<	"4. Enqueue sentence" << endl;	
	cout <<	"5. Quit" << endl;	
	cin >> n;
	return n;
}
void Queue::enqueue(string word)
{
	if(queueIsFull() == false)
	{
		size_t numWords = 1;
		for(size_t i = 0; i <= word.length(); i++)
		{
			if(word[i] == ' ')
			{
				numWords++;
			}
		}
		if(numWords > 1)
		{
			istringstream input(word);
			for(size_t i = 0; i < numWords; i++)
			{	
				if(queueIsFull() == false)
				{
					input >> word;
					arrayQueue[queueTail] += word;
					queueTail++;
					queueCount++;
					if(queueTail == 10)
					{
						queueTail = 0;
					}
					cout << "E: " << word << endl;
					cout << "H: " << queueHead << endl;
					cout << "T: " << queueTail << endl;
				}
				else
				{
					cout << "Queue is full." << endl;
				}
			}
		}
		else
		{
			arrayQueue[queueTail] = word;
			queueTail++;
			queueCount++;
			if(queueTail == 10)
			{
				queueTail = 0;
			}
			cout << "E: " << word << endl;
			cout << "H: " << queueHead << endl;
			cout << "T: " << queueTail << endl;	
		}
	}
	else
	{
		cout << "Queue is full." << endl;
	}
}
void Queue::dequeue()
{
	if(queueIsEmpty() == false)
	{
		string word = arrayQueue[queueHead];
		arrayQueue[queueHead].clear();
		queueHead++;
		queueCount--;
		if(queueHead == 10)
		{
			queueHead = 0;
		}
		cout << "H: " << queueHead << endl;
		cout << "T: " << queueTail << endl;
		cout << "word: " << word << endl;
	}
	else
	{
		cout << "Queue is empty." << endl;
	}
}
void Queue::printQueue()
{
	int count = queueHead;
	if(queueIsEmpty() == false)
	{
		for(int i = 0; i < queueCount; i++)
		{
			cout << count << ": " << arrayQueue[count] << endl;
			count ++;
			if(count == 10)
			{
				count = 0;
			}
		}
	}
	else
	{
		cout << "Empty" << endl;
	}
}

bool Queue::queueIsFull()
{
	if(queueCount == queueSize)
	{
		//queueTail = 0;
		
		//queueCount = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool Queue::queueIsEmpty()
{
	if(queueCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Queue::Queue(int qs) {
queueSize = qs;
arrayQueue = new string[queueSize];
queueHead = 0;
queueTail = 0;
queueCount = 0;
}
Queue::~Queue()
{
	
}

