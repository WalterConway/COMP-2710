#include "Menu.h"
// Function: default constructor
// Inputs: void
// Outputs: void
// Description: initialize a menu.
Menu::Menu()
{
	MessagingSystem.addUser();
}

// Function: deconstructor
// Inputs: void
// Outputs: void
// Description: void 
Menu::~Menu(){

}

// Function: display menu
// Inputs: void
// Outputs: void
// Description: displays menu and also sends choice to the message system
void Menu::DisplayMenu()
{
	string selection;

	cout << "Select Friend (f)\tSend (s)\tReceive (r)\t\nFriend List (g)\t\tQuit (q)\tEnter option: ";
	getline(cin, selection);
	if(isValid(selection))
	{
		char choice = tolower(selection[0]);
		switch (choice)
   {
   case 'f':
	   MessagingSystem.selectFriend();
	   break;
   case 's':
	   MessagingSystem.sendMessage();
	   break;
   case 'r':
	   MessagingSystem.receiveMessage();
	   break;
   case 'q':
	   MessagingSystem.quit();
	   break;
   case 'g':
	   MessagingSystem.getFriendList();
	   break;
   default:
	   cout << "\n\n**Invalid input**\n\n";
	   break;
		 }
	}
	else
	{
		cout << "\n\n**Invalid input**\n\n";
	}
}
// Function: is valid
// Inputs: string input
// Outputs: bool true whether the input is a valid choice for the menu
// Description: returns true whether the input is a valid choice for the menu and false otherwise
bool Menu::isValid(string input)
{
	if(input.length() > 1 )
	{
		return false;
	}
	return true;
}

