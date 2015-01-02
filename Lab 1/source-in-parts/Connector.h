// Program 1:		Connector object of the meeting room application
// File:			Connector.h
// Description:		Class definition of the Connector class.
#include <iostream>
#include "User.h"
#include "Room.h"
using namespace std;

#ifndef Connector_H
#define Connector_H
class Connector
{
public:
	Connector();
	Connector(User *userAddress, Room *roomAddress);
	~Connector();
	void setUserPointer(User *userAddress);
	void setRoomPointer(Room *roomAddress);
	User* getUserPointer();
	Room* getRoomPointer();
	void getNewMessages();
	void getAllMessages();
	int getNewMsgPlaceMark();
	int getAllMsgPlaceMark();
	void setNewMsgPlaceMark(int placementNumber);
	void setAllMsgPlaceMark(int placementNumber);

private:
	User *userName;
	Room *meetingRoom;
	int newMsgPlaceMark; //Stores the index of the message buffer in the room for the use to get new messages.
	int allMsgPlaceMark; //Stores the index of the message buffer in the room for the use to get all message.	
};
#endif