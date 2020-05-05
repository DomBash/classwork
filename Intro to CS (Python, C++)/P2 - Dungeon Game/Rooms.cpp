// Name: Dominic B
// Date: 12/5/15
// Assignment: Project 2
// Description: Rooms class for dungeon

#include "Rooms.h"
Rooms::Rooms(std::string next, std::string prev, std::string current)
{
	prevRoom = prev;
	nextRoom = next;
	currentRoom = current;
}
std::string Rooms::getPrevRoom()
{
	return prevRoom;
}
std::string Rooms::getNextRoom()
{
	return nextRoom;
}
std::string Rooms::getCurrentRoom()
{
	return currentRoom;
}
void Rooms::setPrevRoom(std::string prev)
{
	prevRoom = prev;
}
void Rooms::setNextRoom(std::string next)
{
	nextRoom = next;
}
void Rooms::setCurrentRoom(std::string current)
{
	currentRoom = current;
}
