#include "User.h"

// Function: constructor
// Inputs: void
// Outputs: void
// Description: void
User::User()
{
	name = "";
}

// Function: destructor
// Inputs: void
// Outputs: void
// Description: void
User::~User()
{
	delete currentRoom;
	currentRoom = NULL;
}

// Function: moveNorth
// Inputs: void
// Outputs: void
// Description: sets the current room to the current's room north's pointer
bool User::moveNorth()
{
	if(checkNorth())
	{
		currentRoom = (*currentRoom).getNorth();
		return true;
	}
	else
	{
		return false;
	}
}

// Function: moveSouth
// Inputs: void
// Outputs: void
// Description: sets the current room to the current's room south's pointer
bool User::moveSouth()
{
	if(checkSouth())
	{
		currentRoom = (*currentRoom).getSouth();
		return true;
	}
	else
	{
		return false;
	}
}

// Function: moveEast
// Inputs: void
// Outputs: void
// Description: sets the current room to the current's room east's pointer
bool User::moveEast()
{
	if(checkEast())
	{
	currentRoom = (*currentRoom).getEast();
	return true;
	}
	else
	{
		return false;
	}
}

// Function: moveWest
// Inputs: void
// Outputs: void
// Description: sets the current room to the current's room west's pointer
bool User::moveWest()
{
	if(checkWest())
	{
	currentRoom = (*currentRoom).getWest();
	return true;
	}
	else
	{
		return false;
	}
}

// Function: checkNorth
// Inputs: void
// Outputs: true if room's north pointer is not null false otherwise
// Description: if the room pointer is null then returns false
bool User::checkNorth()
{
	if((*currentRoom).getNorth() != NULL)
	{
		return true;
	}
	return false;
}

// Function: checkSouth
// Inputs: void
// Outputs: true if room's south pointer is not null false otherwise
// Description: if the room pointer is null then returns false
bool User::checkSouth()
{
	if((*currentRoom).getSouth() != NULL)
	{
		return true;
	}
	return false;
}

// Function: checEast
// Inputs: void
// Outputs: true if room's east pointer is not null false otherwise
// Description: if the room pointer is null then returns false
bool User::checkEast()
{
	if((*currentRoom).getEast() != NULL)
	{
		return true;
	}
	return false;
}

// Function: checkWest
// Inputs: void
// Outputs: true if room's west pointer is not null false otherwise
// Description: if the room pointer is null then returns false
bool User::checkWest()
{
	if((*currentRoom).getWest() != NULL)
	{
		return true;
	}
	return false;
}

// Function: getName
// Inputs: void
// Outputs: string 
// Description: returns the name of the user which will be null unless set.
string User::getName() const
{
	return name;
}

// Function: setName
// Inputs: string
// Outputs: void
// Description: sets the name inputted with the name of the user
void User::setName(string newName)
{
	name = newName;
}

// Function: setCurrentRoom
// Inputs: a room pointer
// Outputs: void
// Description: sets the current room pointer to the input room pointer
void User::setCurrentRoom(Room* newRoomPointer)
{
	currentRoom = newRoomPointer;
}

// Function: getCurrentRoom
// Inputs: void
// Outputs: a room pointer
// Description: returns the current room pointer of the user.
Room* User::getCurrentRoom() const
{
	return currentRoom;
}
