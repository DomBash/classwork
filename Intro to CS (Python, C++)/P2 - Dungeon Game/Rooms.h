
#include <iostream>
#include <string>

#ifndef ROOMS_H
#define ROOMS_H

class Rooms
{
	private:
		std::string prevRoom;
		std::string nextRoom;
		std::string currentRoom;
	public:
		Rooms(std::string, std::string, std::string);
		std::string getPrevRoom();
		std::string getNextRoom();
		std::string getCurrentRoom();
		void setPrevRoom(std::string);
		void setNextRoom(std::string);
		void setCurrentRoom(std::string);
};
#endif
