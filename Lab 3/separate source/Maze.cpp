#include "Maze.h"

// Function: default constructor
// Inputs: void
// Outputs: void
// Description: void
Maze::Maze()
{
	startRoom = NULL;
	endRoom = NULL;
	roomCount = 0;
}

// Function: destructor
// Inputs: void
// Outputs: void
// Description: performs clean up.
Maze::~Maze()
{
	delete [] roomList;
	*roomList = NULL;
	delete startRoom;
	startRoom = NULL;
	delete endRoom;
	endRoom = NULL;

}

// Function: getStartRoom
// Inputs: void
// Outputs: returns a room pointer
// Description: returns the starting room of the maze
Room* Maze::getStartRoom() const
{
	return startRoom;
}

// Function: setStartRoom
// Inputs: a room pointer
// Outputs: void
// Description: sets the room pointer with the input pointer 
void Maze::setStartRoom(Room* roomPointer)
{
	startRoom = roomPointer;
}

// Function: getEndRoom
// Inputs: void
// Outputs: returns room pointer
// Description: returns the maze's end room.
Room* Maze::getEndRoom() const
{
	return endRoom;
}

// Function: setEndRoom
// Inputs: a room pointer
// Outputs: void
// Description: sets the room pointer to the end room pointer
void Maze::setEndRoom(Room* roomPointer)
{
	endRoom = roomPointer;
}

// Function: addRoom
// Inputs: a character
// Outputs: void
// Description: adds a room with the character as its name and sets all other "doors" to null. 
void Maze::addRoom(char name)
{
	roomList[getRoomCount()] = new Room(name);
	incrementRoomCount();
}

// Function: findRoom
// Inputs: character
// Outputs: a room pointer
// Description: find the first room pointer with the character input
Room* Maze::findRoom(char name)
{
	if(name == '*')
	{
		return NULL;
	}
	for(int i = 0; i < MAXROOMS; i++)
	{
		if ((*roomList[i]).getName() == name)
		{
			return roomList[i];
		}
	}
return NULL;
}

// Function: getRoomCount
// Inputs: void
// Outputs: a integer
// Description: returns the how many rooms are in the maze
int Maze::getRoomCount() const
{
	return roomCount;
}

// Function: incrementRoomCount
// Inputs: void
// Outputs: void
// Description: increments the room count by one
void Maze::incrementRoomCount()
{
	roomCount++;
}

// Function: setRoom
// Inputs: room name for each door
// Outputs: void
// Description: sets the room name with inputted with the room name inputted in each direction. 
void Maze::setRoom(char name, char north, char east, char south, char west)
{
	Room* currentFoundRoom = findRoom(name);
		(*currentFoundRoom).setNorth(findRoom(north));
		(*currentFoundRoom).setSouth(findRoom(south));
		(*currentFoundRoom).setEast(findRoom(east));
		(*currentFoundRoom).setWest(findRoom(west));

}
