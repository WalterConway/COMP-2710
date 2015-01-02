// Name:		Walter Conway
// Class:		COMP 2710
// Date:		June 18, 2013
// E-Mail:		wjc0008@auburn.edu
//
// Description:	This class maintains the connection between the user and a meeting room.
#include "Connector.h"

Connector::Connector()
{
}
// Function: Connector class constructor
// Inputs: user pointer, room pointer
// Outputs: void
// Description: Initalizes the connector object for each connection to a room and user.
//				A user my have one or more connectors but only one connection to a particular room.
//				Ex. John connected to Blue room
//					 John connected to Red room
// John has two connectors in all one to Blue room and one to Red room.
Connector::Connector(User *userAddress, Room *roomAddress)
{
	userName = userAddress;
	meetingRoom = roomAddress;
	allMsgPlaceMark = ((*meetingRoom).getMessage()).length();
	newMsgPlaceMark = ((*meetingRoom).getMessage()).length();
}
//Deconstructor
Connector::~Connector()
{
}

// Function: setsUserPointer
// Inputs: A user's pointer
// Outputs: void
// Description: sets the connector's user pointer.
void Connector::setUserPointer(User *userAddress)
{
	userName = userAddress;
}

// Function: setRoomPointer
// Inputs: A room's pointer
// Outputs: void
// Description: sets the connector's room pointer.
void Connector::setRoomPointer(Room *roomAddress)
{
	meetingRoom = roomAddress;
}

// Function: getUserPointer
// Inputs: void
// Outputs: connector's user pointer
// Description: retrives the connector's user pointer.
User* Connector::getUserPointer()
{
	return userName;
}

// Function: getRoomPointer
// Inputs: void
// Outputs: connector's room pointer
// Description: retrives the connector's room pointer.
Room* Connector::getRoomPointer()
{
	return meetingRoom;
}

// Function: getAllMsgPlaceMark
// Inputs: void
// Outputs: returns the index value (Place Marker) of when the connector was created.
// Description: The purpose is to remember where the user first joined a room so messages can be retrieved.
int Connector::getAllMsgPlaceMark()
{
	return allMsgPlaceMark;
}

// Function: getNewMsgPlaceMark
// Inputs: void
// Outputs: returns the index value (Place Marker) of when the connector was created
//			or when the new message function was called last.
// Description: The purpose is to remember where the user last left off of checking their messages.
int Connector::getNewMsgPlaceMark()
{
	return newMsgPlaceMark;
}

// Function: setNewMsgPlaceMark
// Inputs: Integer of the placement value of where the user last left off check their messages.
// Outputs: void
// Description: sets the new message placement marker value.
void Connector::setNewMsgPlaceMark(int placementNumber)
{
	newMsgPlaceMark = placementNumber;
}

// Function: setAllMsgPlaceMark
// Inputs: Integer of the placement value of where the user first joined the room.
// Outputs: void
// Description: sets the all message placement marker value.
void Connector::setAllMsgPlaceMark(int placementNumber)
{
	allMsgPlaceMark = placementNumber;

}

// Function: getAllMessages
// Inputs: void
// Outputs: displays all messages based off the all message placement marker and the room's buffer.
// Description: Displays all The messages from which the user first came into the room.
void Connector::getAllMessages()
{
	if(((*meetingRoom).getMessage()).length() !=  getAllMsgPlaceMark())
	{
		setNewMsgPlaceMark(((*meetingRoom).getMessage()).length());
		cout << endl;
		cout << ((*meetingRoom).getMessage()).substr(getAllMsgPlaceMark());
		cout << endl;
	}
	else
	{
		cout << "\n\n**No new messages**\n\n";
	}
}

// Function: getNewMessages
// Inputs: void
// Outputs: displays all messages based off the new message placement marker and the room's buffer.
// Description: Displays all the messages that has yet been retrieved, either by all messages or new messages.
void Connector::getNewMessages()
{
	if(((*meetingRoom).getMessage()).length() !=  getNewMsgPlaceMark())
	{
		cout << endl;
		cout << ((*meetingRoom).getMessage()).substr(getNewMsgPlaceMark());
		cout << endl;
		setNewMsgPlaceMark(((*meetingRoom).getMessage()).length());
	}
	else
	{
		cout << "\n\n**No new messages**\n\n";
	}
}