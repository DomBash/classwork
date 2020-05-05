// Name: Dominic B
// Date: 10/10/15
// Assignment: Homework #5
// Description: Read in keywords and phrases to create a sort of AI

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(int argc, char* argv[])//CLA
{
	ifstream responses_filename;
	responses_filename.open(argv[1]);//Open file
	
	string array1[2][100];
	string line;
	int count = 0;	

	if (responses_filename.is_open())
	{
		while ( getline (responses_filename,line))//read each line
		{
			int index = line.find("@");//find @ in the line
			array1[0][count] = line.substr(0,index);//before @
			array1[1][count] = line.substr(index+1);// after @
			count += 1;
		}
		responses_filename.close();//close file
	}
	
	string keyword = "";
	string response = "";
	cout << "What question do you have about C++?" << endl;
	cin >> keyword;//get keyword
	while(keyword != "quit")//if input is quit it ends
	{
		for(int i=0; i<=count; i++)//loop through the array
		{
			if(array1[0][i] == keyword)//if keyword is in array
			{
				response = array1[1][i];//= response to keyword
			}else if (response == "") response = "Sorry, I don't know. What else can we talk about?";//if keyword is not in array
		}
		cout << response << endl;//print response to keyword
		cin >> keyword;//get new keyword
		response = "";//reset response
	}
	return 0;
}

