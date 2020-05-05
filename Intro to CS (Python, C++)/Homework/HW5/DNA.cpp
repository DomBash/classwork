// Name: Dominic B
// Date: 10/10/15
// Assignment: Homework #5
// Description: Read in a file and analyze the data

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main(int argc, char* argv[])
{
	char* mouseDNA_filename = argv[1];
	char* humanDNA_filename = argv[2];
	char* unknownDNA_filename = argv[3];
	
	string mouseDNA;
	string humanDNA;
	string unknownDNA;	
	
	float mouseHem = 0;	
	float humanHem = 0;
	float mouseSim = 0;
	float humanSim = 0;

	float stringLength;

	int count = 0;

	string line;
	ifstream mouse (mouseDNA_filename); 
	if (mouse.is_open())
	{
		while ( getline (mouse,line) )
		{
			mouseDNA = line;
		}
		mouse.close();
	}
	else cout << "Unable to open file mouse" << endl;

	ifstream human (humanDNA_filename); 
	if (human.is_open())
	{
		while ( getline (human,line) )
		{
			humanDNA = line;
		}
		human.close();
	}
	else cout << "Unable to open file human" << endl;

	ifstream unknown (unknownDNA_filename); 
	if (unknown.is_open())
	{
		while ( getline (unknown,line) )
		{
			unknownDNA = line;
		}
		unknown.close();
	}
	else cout << "Unable to open file" << endl;

	stringLength = mouseDNA.length();
	
	while (count<= stringLength)
	{
		if (mouseDNA[count] != unknownDNA[count])
		{
			mouseHem += 1;
		}
		count += 1;
	}
	count = 0;
	while (count <= stringLength)
	{
		if (humanDNA[count] != unknownDNA[count])
		{
			humanHem += 1;
		}
		count += 1;
	}
	
	mouseSim = (stringLength - mouseHem)/stringLength;
	humanSim = (stringLength - humanHem)/stringLength;
	cout << "MouseCompare = " << mouseSim << endl;
	cout << "HumanCompare = " << humanSim << endl;

	if( abs(mouseSim - humanSim) < 0.0001)
	{
		cout << "identity cannot be determined" << endl;
	}
	else if (mouseSim > humanSim)
	{
		cout << "mouse" << endl;
	}
	else if (mouseSim < humanSim)
	{
		cout << "human" << endl;
	}

	return 0;	
}


