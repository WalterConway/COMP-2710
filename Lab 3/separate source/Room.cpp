#include "Room.h"

// Function: default constructor
// Inputs: void
// Outputs: void
// Description: sets the class variables to a default value.
Room::Room()
	:name(' '), north(NULL), south(NULL), east(NULL), west(NULL)
{
}

// Function: destructor
// Inputs: void
// Outputs: void
// Description: deletes the local variables for cleanup.
Room::~Room()
{
	delete north;
	north = NULL;

	delete south;
	south = NULL;

	delete east;
	east = NULL;

	delete west;
	west = NULL;
}

// Function: overloaded constructor
// Inputs: room name
// Outputs: void
// Description: creates a room with the input value.
Room::Room(char roomName)
{
	name = roomName;
	north= NULL;
	south= NULL;
	east= NULL;
	west= NULL;
}

// Function: getName
// Inputs: void
// Outputs: character that is the name of the room
// Description: returns the name of the room.
char Room::getName() const
{
	return name;
}

// Function: setName
// Inputs: character that will take the place of the value of the name
// Outputs: void
// Description: sets the name of the room with the input
void Room::setName(char newName)
{
	name = newName;
}

// Function: getNorth
// Inputs: void
// Outputs: returns the pointer to the north
// Description: returns the pointer to the north
Room* Room::getNorth() const
{
	return north;
}

// Function: setNorth
// Inputs: a room pointer
// Outputs: void
// Description: sets the room's north pointer to the input
void Room::setNorth(Room* northPointer)
{
	north = northPointer;
}

// Function: getSouth
// Inputs: void
// Outputs: returns the pointer to the south
// Description: returns the pointer to the south
Room* Room::getSouth() const
{
	return south;
}

// Function: setSouth
// Inputs: a room pointer
// Outputs: void
// Description: sets the room's south pointer to the input
void Room::setSouth(Room* southPointer)
{
	south = southPointer;
}

// Function: getEast
// Inputs: void
// Outputs: returns the pointer to the east
// Description: returns the pointer to the east
Room* Room::getEast() const
{
	return east;
}

// Function: setEast
// Inputs: a room pointer
// Outputs: void
// Description: sets the room's east pointer to the input
void Room::setEast(Room* eastPointer)
{
	east = eastPointer;
}

// Function: getWest
// Inputs: void
// Outputs: returns the pointer to the west
// Description: returns the pointer to the west
Room* Room::getWest() const
{
	return west;
}

// Function: setWest
// Inputs: a room pointer
// Outputs: void
// Description: sets the room's west pointer to the input
void Room::setWest(Room* westPointer)
{
	west = westPointer;
}