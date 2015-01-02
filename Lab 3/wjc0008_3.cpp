// Program 2:	Maze 
// Name:		Walter Conway
// Class:		COMP 2710
// Date:		July 24, 2013
// E-Mail:		wjc0008@auburn.edu
//
// Description:	This program is a game that simulates a Maze.
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;
#define MAXROOMS 12

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
	void gameOverMessage();
	bool isFileCorrupt(string fileName);
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

class Menu
{
private:
	GameSystem MazeSystem;
public:
	Menu();
	~Menu();
	bool isValid(string input);
	void displayMenu();
};

Menu menuObj;

int main()
{	
	while(true)
	{
		menuObj.displayMenu();
	}
	return 0;
}

// Function: default constructor
// Inputs: void
// Outputs: void
// Description: void
Menu::Menu()
{

}

// Function: destructor
// Inputs: void
// Outputs: void
// Description: void
Menu::~Menu()
{

}

// Function: displayMenu
// Inputs: void
// Outputs: void
// Description: displays the menu and prompts the user for input
void Menu::displayMenu()
{
string input = "";	
cout << "You are currently in Room " << MazeSystem.getCurrentUserCurrentRoomName() << " of the Maze." << endl;
cout << "You can go " << MazeSystem.getCurrentUserAvailiableMoves();
cout << ". What is your choice? ";
getline(cin,input);
if(isValid(input))
{
	MazeSystem.inputCommand(toupper(input[0]));
}
else
{
	cout << "**Invalid Input**" << endl;
}
}

// Function: isValid
// Inputs: string
// Outputs: returns true if there is only one character, false otherwise
// Description: returns true if the input is only one character
bool Menu::isValid(string input)
{
if(input.length() > 1 )
{
	return false;
}
return true;
}

// Function: default constructor
// Inputs: void
// Outputs: void
// Description: void
GameSystem::GameSystem() : steps(0), path("") , currentUser(new User()), currentMaze(new Maze())
{
	string fileName;
	welcomeMessage();
		do
		{
			cout << "What is the maze file name: ";
			getline(cin, fileName);
		} while(isFileCorrupt(fileName));
		loadMaze(fileName);
}
// Function: destructor
// Inputs: void
// Outputs: void
// Description: cleans up, can not delete the current maze it creates an error.
GameSystem::~GameSystem()
{
	//delete currentUser;
	//currentUser = NULL;
	//delete currentMaze;
	//currentMaze = NULL;
}


// Function: isFileCorrupt
// Inputs: string fileName
// Outputs: bool true if the file is corrupt false if it is not corrupt
// Description: checks if the input is a blank space, or
//				if there is a file by that name, also the number of lines, and the spacing in the file.
bool GameSystem::isFileCorrupt(string fileName)
{
	string invalid = "**Invalid File Name**\n";
	string corrupt = "**File is Corrupt**\n";
	int lineCount = 0;
	string line;
	if(fileName.empty())
	{
		cout << invalid;
		return true;	
	}
	mazeFile.open(fileName.c_str());
	if(mazeFile.fail())
	{
		mazeFile.close();
		cout << invalid;
		return true;
	}

	while(!mazeFile.eof() && lineCount < MAXROOMS)
	{
		getline(mazeFile, line);
		//Checks for the spaces in the file
		if((int)line[1] != 32 || (int)line[3] != 32 || (int)line[5] != 32 || (int)line[7] != 32)
		{
			mazeFile.close();
			cout << corrupt;
			return true;
		}
		//Checks for the capital letters for the rooms
		if((int)(line[0]) != (lineCount + 65))
		{
			mazeFile.close();
			cout << corrupt;
			return true;
		}
		lineCount++;
	}
	mazeFile.close();

	if(lineCount < MAXROOMS)
	{
		cout << corrupt;
		return true;
	}	
	return false;
}

// Function: welcomeMessage
// Inputs: void
// Outputs: void
// Description: Displays a welcome message.
void GameSystem::welcomeMessage()
{
cout << endl;
cout << "\t";
cout.fill('#');
cout.width(60);
cout.left;
cout << "" <<endl;
cout << "\t#";
cout.fill(' ');
cout.width(52);
cout << left << "\tWelcome to the Maze game!";
cout << "#";
cout << endl << "\t";
cout.fill('#');
cout.width(60);
cout.left;
cout << "" <<endl <<endl;
}

// Function: gameOverMessage
// Inputs: void
// Outputs: void
// Description: Displays a farewell message that contains steps and path.
void GameSystem::gameOverMessage()
{
cout << endl;
cout << "\t";
cout.fill('#');
cout.width(60);
cout.left;
cout << "" <<endl;
cout << "\t#";
cout.fill(' ');
cout.width(52);
cout << left << "\tCongratulations! You have reached the finish point.";
cout << "#";
cout << endl << "\t";
cout.fill('#');
cout.width(60);
cout.left;
cout << "" <<endl <<endl;
cout << "You took " << getSteps() << " steps" << endl;
cout << "Your path is: " << getPath() << endl;
}

// Function: getCurrentUser
// Inputs: void
// Outputs: void
// Description: returns the current user.
User* GameSystem::getCurrentUser() const
{
	return currentUser;
}

// Function: setUser
// Inputs: userPointer
// Outputs: void
// Description: Sets the current user to the input.
void GameSystem::setUser(User* userPointer)
{
	currentUser = userPointer;
}

// Function: getMaze
// Inputs: void
// Outputs: returns the current maze
// Description: returns the current maze in the system.
Maze* GameSystem::getMaze() const
{
	return currentMaze;
}

// Function: setMaze
// Inputs: mazePointer
// Outputs: void
// Description: 
void GameSystem::setMaze(Maze* mazePointer)
{
	currentMaze = mazePointer;
}

// Function: getSteps
// Inputs: void
// Outputs: returns the number of steps
// Description: returns the number of steps that it took to get to the end or to the current room.
int GameSystem::getSteps() const
{
	return steps;
}

// Function: setSteps
// Inputs: a number that will take the place of the current number of steps
// Outputs: void
// Description: sets the input to steps. 
void GameSystem::setSteps(int newNumber)
{
	steps = newNumber;
}

// Function: incrementStep
// Inputs: void
// Outputs: void
// Description: increment the step count by one.
void GameSystem::incrementStep()
{
	steps++;
}

// Function: getPath
// Inputs: void
// Outputs: returns a string of the path that was used to get to the current room
// Description: 
string GameSystem::getPath() const
{
	return path;
}

// Function: setPath
// Inputs: a character that will be appened to the end of the path.
// Outputs: void
// Description: takes the input and appends it to the end of the path string.
void GameSystem::setPath(char newPath)
{
	path.append(string(1,newPath));
}

// Function: inputCommand
// Inputs: character that will move the user in the maze
// Outputs: void
// Description: n,s,e,w are the only commands that are recognized when appropriate.
void GameSystem::inputCommand(char command)
{
switch(command)
{
case 'N':
	if((*getCurrentUser()).moveNorth())
	{
	incrementStep();
	setPath(getCurrentUserCurrentRoomName());
	}
	else
	{
		cout << "**Sorry, Invalid Move**" << endl;
	}
	break;
case 'S':
	if((*getCurrentUser()).moveSouth())
	{
	incrementStep();
	setPath(getCurrentUserCurrentRoomName());
		}
	else
	{
		cout << "**Sorry, Invalid Move**" << endl;
	}
	break;
case 'E':

	if((*getCurrentUser()).moveEast())
	{
	incrementStep();
	setPath(getCurrentUserCurrentRoomName());
		}
	else
	{
		cout << "**Sorry, Invalid Move**" << endl;
	}
	break;
case 'W':

	if((*getCurrentUser()).moveWest())
	{
	incrementStep();
	setPath(getCurrentUserCurrentRoomName());
		}
	else
	{
		cout << "**Sorry, Invalid Move**" << endl;
	}
	break;
default:
	cout << "**Invalid Input**" << endl;
	break;
}
if(isCurrentUserFinished())
{
	gameOverMessage();
	exit(1);		
}
}

// Function: getCurrentUserAvailiableMoves
// Inputs: void
// Outputs: returns the availiable moves in a string
// Description: each move is seperated by an or if there is more than one.
string GameSystem::getCurrentUserAvailiableMoves() const
{
	string output = "";
	int optionCount = 0;
if((*getCurrentUser()).checkNorth())
{
	if(optionCount > 0)
	{
		output += " or ";
	}

	output += "(N)orth";
	optionCount++;
}
if((*getCurrentUser()).checkSouth())
{
		if(optionCount > 0)
		{
			output += " or ";
		}
	output += "(S)outh";
		optionCount++;
}
if((*getCurrentUser()).checkEast())
{
	if(optionCount > 0)
	{
		output += " or ";
	}
	output += "(E)ast";
		optionCount++;
}
if((*getCurrentUser()).checkWest())
{
	if(optionCount > 0)
	{
		output += " or ";
	}
	output += "(W)est";
		optionCount++;
}
return output;
}

// Function: loadMaze
// Inputs: void
// Outputs: void
// Description: loads in the maze file input.txt
void GameSystem::loadMaze(string fileName)
{
	string line;
	string connectors[MAXROOMS];
	mazeFile.open(fileName.c_str());
	if(mazeFile.fail())
	{
		cout << "File was not opened.";
	}
	int i = 0;
	while(!mazeFile.eof() && i < MAXROOMS)
	{
		getline(mazeFile,line);
		(*getMaze()).addRoom(line[0]);
			connectors[i] = line;
			i++;
	}
	mazeFile.close();
	//accessing each line of the array
	for(i = 0; i < MAXROOMS; i++)
	{
		(*getMaze()).setRoom( connectors[i].at(0), connectors[i].at(2), connectors[i].at(4), connectors[i].at(6), connectors[i].at(8));
	}
	(*getMaze()).setStartRoom((*getMaze()).findRoom(connectors[0].at(0)));
	(*getMaze()).setEndRoom((*getMaze()).findRoom(connectors[11].at(0)));
	(*getCurrentUser()).setCurrentRoom((*getMaze()).getStartRoom());
	if(isCurrentUserFinished())
	{
	cout << "**The starting room is equal to the ending room.**\n";
	cout << "**Use a different Maze file**\n";
	exit(1);
	}
	setPath(getCurrentUserCurrentRoomName());
}

// Function: getCurrentUserName
// Inputs: void
// Outputs: string returns the current user of the system
// Description: unless set the username will be NULL
string GameSystem::getCurrentUserName() const
{
	return (*getCurrentUser()).getName();
}

// Function: getCurrentUserCurrentRoomName
// Inputs: void
// Outputs: returns the character that is the label of the room
// Description: the return character is the name of the room
char GameSystem::getCurrentUserCurrentRoomName() const
{
	return (*(*getCurrentUser()).getCurrentRoom()).getName();
}

// Function: isCurrentUserFinished
// Inputs: void
// Outputs: true if the user's current room is equal to the maze's end room.
// Description: checks whether or not the user has reached the end of the maze.
bool GameSystem::isCurrentUserFinished(){
if((*getCurrentUser()).getCurrentRoom() == (*getMaze()).getEndRoom())
{
	return true;
}
return false;
}


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
