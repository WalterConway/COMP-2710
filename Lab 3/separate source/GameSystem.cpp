#include "GameSystem.h"
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
// Description: void
GameSystem::~GameSystem()
{

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
	mazeFile.open(fileName);
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
	int i = 0;
	mazeFile.open(fileName);
	if(mazeFile.fail())
	{
		cout << "File was not opened.";
	}
	
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