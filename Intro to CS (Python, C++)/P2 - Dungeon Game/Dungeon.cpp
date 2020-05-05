// Name: Dominic B
// Date: 12/5/15
// Assignment: Project 2
// Description: Create dungeon game in c++

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include "Rooms.cpp"
#include "Output.cpp"
using namespace std;
void welcome()
{
	cout << "Welcome to the dungeon." << endl;
	cout << "Good luck finding the princess." << endl;
}
string userInput()
{
	string response;
	cin >> response;
	return response;
}
string fromLobby(string direction)
{
	string newRoom;
	Rooms Lobby("Hallway1", "Exit", "Lobby");
	if (direction == "n")
	{
		newRoom = Lobby.getNextRoom();
	}
	else if(direction == "s")
	{
		exit(0);
	}	
	else
	{
		newRoom = Lobby.getCurrentRoom();
	}
	return newRoom;
}
string fromHallway1(string direction)
{
	string newRoom;
	Rooms Hallway1("Bedroom", "Lobby", "Hallway1");
	if(direction == "w")
	{
		newRoom = Hallway1.getNextRoom();
	}
	else if (direction == "s")
	{
		newRoom = Hallway1.getPrevRoom();
	}
	else
	{
		newRoom = Hallway1.getCurrentRoom();
	}
	return newRoom;
}

string fromHallway4(string direction)
{
	string newRoom;
	Rooms Hallway4("Library", "Bedroom", "Hallway4");
	if(direction == "n")
	{
		newRoom = Hallway4.getNextRoom();
	}
	else if(direction == "s")
	{
		newRoom = Hallway4.getPrevRoom();
	}
	else
	{
		newRoom = Hallway4.getCurrentRoom();
	}
	return newRoom;
}
string fromBedroom(string direction)
{
	string newRoom;
	Rooms Bedroom("Hallway4", "Hallway1", "Bedroom");
	if(direction == "n")
	{
		newRoom = Bedroom.getNextRoom();
	}
	else if(direction == "e")
	{
		newRoom = Bedroom.getPrevRoom();
	}
	else
	{
		newRoom = Bedroom.getCurrentRoom();
	}
	return newRoom;
}
string fromLibrary(string direction)
{
	string newRoom;
	Rooms Library("SecretRoom", "Hallway4", "Library");
	if(direction == "e")
	{
		newRoom = "win";
	}
	else if(direction == "s")
	{
		newRoom = Library.getPrevRoom();
	}
	else
	{
		newRoom = Library.getCurrentRoom();
	}
	return newRoom;
}
void win(int now)
{
	cout << "You pull on a book and the shelf swings open. You found the secret room with the princess in it! Great Job!" << endl;
	time_t now2 = time(0);
	int took = now2 - now;
	ofstream outfile;
	outfile.open("Time.txt");
	outfile << "It took you " << took << " seconds to find the princess!" << endl;
	exit(0);	
}
string nextRoom(string direction, string room)
{
	string newRoom;
	if (room == "Lobby")
	{
		newRoom = fromLobby(direction);
	}
	else if(room == "Hallway1")
	{
		newRoom = fromHallway1(direction);
	}
	else if(room == "Bedroom")
	{
		newRoom = fromBedroom(direction);
	}
	else if(room == "Hallway4")
	{
		newRoom = fromHallway4(direction);
	}
	else if(room == "Library")
	{
		newRoom = fromLibrary(direction);
	}
	return newRoom;
}
int main()
{
	ifstream responses_filename;
	responses_filename.open("RoomText.txt");
	
	string array1[2][10];
	string line;
	int count = 0;

	if (responses_filename.is_open())
	{
		while ( getline (responses_filename,line))
		{
			int index = line.find(":");
			array1[0][count] = line.substr(0,index);
			array1[1][count] = line.substr(index+1);
			count += 1;
		}
		responses_filename.close();
	}
	time_t now = time(0);
	cout << "Start time:" << now << endl;
	string direction;
	string room = "Lobby";
	welcome();
	while ( direction != "q")
	{
		string output;
		if(room == "Lobby")
		{
			Output Lobby(array1[0][0], array1[1][0]);
			output = Lobby.getRoomDialogue();
	    }
	    else if(room == "Hallway1")
		{
			Output Hallway1(array1[0][1], array1[1][1]);
			output = Hallway1.getRoomDialogue();
	    }
	    else if(room == "Bedroom")
		{
			Output Bedroom(array1[0][2], array1[1][2]);
			output = Bedroom.getRoomDialogue();
	    }
	    else if(room == "Hallway4")
		{
			Output Hallway4(array1[0][3],array1[1][3]);
			output = Hallway4.getRoomDialogue();
	    }
	    else if(room == "Library")
		{
			Output Library(array1[0][4], array1[1][4]);
			output = Library.getRoomDialogue();
	    }
	    
	    cout << output << endl;
		direction = userInput();
		room = nextRoom(direction, room);
		if(room == "win")
		{
			win(now);
		}
	}
	if (direction == "q")
	{
		time_t now2 = time(0);
		int took = now2 - now;
		ofstream outfile;
		outfile.open("Time.txt");
		outfile << "You looked for the princess for " << took << " seconds." << endl;
		exit(0);
	}
	return 0;
}
