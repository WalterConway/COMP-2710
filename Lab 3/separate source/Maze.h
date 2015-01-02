#include <string>
#include <iostream>
#include "Room.h"
using namespace std;

#ifndef MAZE_H
#define MAZE_H
#define MAXROOMS 12
class Maze
{
private:
	Room* startRoom;
	Room* endRoom;
	Room* roomList[MAXROOMS];
	int roomCount;
public:
	Maze();
	~Maze();
	int getRoomCount() const;
	void incrementRoomCount();
	Room* getStartRoom() const;
	void setStartRoom(Room* roomPointer);
	Room* getEndRoom() const;
	void setEndRoom(Room* roomPointer);
	void addRoom(char name);
	void setRoom(char name, char north, char east, char south, char west);
	Room* findRoom(char name);
};
#endif