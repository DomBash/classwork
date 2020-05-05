// Name: Dominic B
// Date: 12/5/15
// Assignment: Project 2
// Description: Output class for dungeon

#include "Output.h"
Output::Output(std::string name, std::string dialogue)
{
	roomName = name;
	roomDialogue = dialogue;
}
std::string Output::getRoomName()
{
	return roomName;
}
std::string Output::getRoomDialogue()
{
	return roomDialogue;
}
void Output::setRoomName(std::string name)
{
	roomName = name;
}
void Output::setRoomDialogue(std::string dialogue)
{
	roomDialogue = dialogue;
}
