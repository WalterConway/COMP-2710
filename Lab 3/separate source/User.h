#include <string>
#include <iostream>
#include "Room.h"
using namespace std;

class User
{
private:
	string name;
	Room *currentRoom;
public:
	User();
	~User();
	bool moveNorth();
	bool moveSouth();
	bool moveEast();
	bool moveWest();
	bool checkNorth();
	bool checkSouth();
	bool checkEast();
	bool checkWest();
	string getName() const;
	void setName(string newName);
	void setCurrentRoom(Room* newRoomPointer);
	Room* getCurrentRoom() const;
};