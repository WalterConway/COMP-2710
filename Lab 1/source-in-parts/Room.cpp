#include "Room.h"
// Function: Constructor
// Inputs: room name
// Outputs: void
// Description: initializes the room name and chat buffer.
Room::Room(string roomName)
{
   name = roomName;
   chatBuffer = "";
}

// Function: deconstructor
// Inputs:
// Outputs:
// Description:
Room::~Room()
{
}

// Function: getMessage
// Inputs: void
// Outputs: message buffer
// Description: returns the Room's message buffer
string Room::getMessage() const
{
	return chatBuffer;
}

// Function: setName
// Inputs: room name
// Outputs: void
// Description: sets the name of the room
void Room::setName(string roomName)
{
   name = roomName;
}

// Function: sendMessage
// Inputs: a message
// Outputs: void
// Description: appends to the end of the chat buffer.
void Room::sendMessage(string message)
{
   chatBuffer.append(message);
}

// Function: getName
// Inputs: void
// Outputs: room name
// Description: returns the name of the room
string Room::getName() const
{
   return name;
}
