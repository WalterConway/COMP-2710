#include "Menu.h"

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

