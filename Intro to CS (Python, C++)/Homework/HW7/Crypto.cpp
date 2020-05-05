// Name: Dominic B
// Date: 11/1/15
// Assignment: Homework #7
// Description: Create a Caesar Cipher

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readFile(string filename)
{
	ifstream message_filename;//input file stream
	message_filename.open(filename);//open file
	string line;
	string message;
	if (message_filename.is_open())
	{
		while ( getline (message_filename,line))//read each line
		{
			message = line;//set message to the line
		}
		message_filename.close();//close file
	}
	return message;
}

int encryptChar(char character, int key)
{
	char eChar = character;
	if (character > 64 && character < 123)//make sure character is a letter
	{
		eChar =  character + key;//add offset to character
		if(eChar > 122 || eChar > 90 & eChar < 97)
		{
			eChar = eChar - 26;//make sure encrypted char is letter
		}
	}
	return eChar;
}

int decryptChar(char character, int key)
{
	char eChar = character;
	if (character > 64 && character < 123)
	{
		eChar =  character - key;
		if(eChar < 65 || eChar > 90 & eChar < 97)
		{
			eChar = eChar + 26;
		}
	}
	return eChar;
}

string encryptMessage(string message,int offset_key)
{
	string eMessage = message;
	for(int i = 0; i < message.length(); i++)//loop through message
	{		
		eMessage.at(i) = encryptChar(message.at(i),offset_key);//add encrypted characters to string
	}
	return eMessage;
}
string decryptMessage(string message,int offset_key)
{
	string eMessage = message;
	for(int i = 0; i < message.length(); i++)
	{		
		eMessage.at(i) = decryptChar(message.at(i),offset_key);		
	}
	return eMessage;
}
void writeToFile(string message, string filename, string extension)
{
	ofstream outfile;// output file stream
	outfile.open(filename + extension);//open output file and add extension
	outfile << message << endl;//put message in output file
}

int main(int argc, char* argv[])//CLA
{
	
	string type = argv[1];//set to encrypt or decrypt
	int offset_key = atoi(argv[2]);//get offset
	string message = readFile(argv[3]);//read message from file
	if(type == "-e")//if encrypting
	{
		cout << "Encrypting file: " << argv[3] << endl;//print filename
		string eMessage = encryptMessage(message, offset_key);//encrypt message
		cout << message << endl;
		cout << eMessage << endl;
		writeToFile(eMessage, argv[3], ".enc");//write to output file
	}
	else if(type == "-d")//if decrypting
	{
		cout << "Decrypting file: " << argv[3] << endl;
		string eMessage = decryptMessage(message, offset_key);
		cout << message << endl;
		cout << eMessage << endl;
		writeToFile(eMessage, argv[3], ".dec");
	}	
	return 0;
}
