#include <string>
using namespace std;

#ifndef ROOM_H
#define ROOM_H
class Room
{
private:
	char name;
	Room *north;
	Room *south;
	Room *east;
	Room *west;
public:
	Room();
	~Room();
	Room(char roomName);

	char getName() const;
	void setName(char newName);

	Room* getNorth() const;
	void setNorth(Room* northPointer);

	Room* getSouth() const;
	void setSouth(Room* southPointer);

	Room* getEast() const;
	void setEast(Room* eastPointer);

	Room* getWest() const;
	void setWest(Room* westPointer);
};
#endif
