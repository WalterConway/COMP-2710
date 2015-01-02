#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Maze.h"
#include "User.h"
using namespace std;

#ifndef GAMESYSTEM_H
#define GAMESYSTEM_H
class GameSystem
{
private:
	ifstream mazeFile;
	Maze* currentMaze;
	User* currentUser;
	int steps;
	string path;
public:
	GameSystem();
	~GameSystem();	
	void welcomeMessage();
	bool isFileCorrupt(string fileName);
	void gameOverMessage();
	void setUser(User* userPointer);
	User* getCurrentUser() const;
	Maze* getMaze() const;
	void setMaze(Maze* mazePointer);
	int getSteps() const;
	string getCurrentUserAvailiableMoves() const;
	string getCurrentUserName() const;
	char getCurrentUserCurrentRoomName() const;
	string getPath() const;
	void setSteps(int newNumber);
	void incrementStep();
	void setPath(char newPath);
	void loadMaze(string fileName);
	void inputCommand(char command);
	bool isCurrentUserFinished();
};
#endif