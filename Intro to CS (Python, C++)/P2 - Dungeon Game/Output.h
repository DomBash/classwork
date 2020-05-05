
#include <iostream>
#include <string>

#ifndef OUTPUT_H
#define OUTPUT_H

class Output
{
	private:
		std::string roomName;
		std::string roomDialogue;
	public:
		Output(std::string, std::string);
		std::string getRoomName();
		std::string getRoomDialogue();
		void setRoomName(std::string);
		void setRoomDialogue(std::string);		
};
#endif

