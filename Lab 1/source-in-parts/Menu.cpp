#include "Menu.h"

// Function: Constructor
// Inputs: void
// Outputs: void
// Description: initalizes the selection to 0;
Menu::Menu()
{
	   selection = 0;
}

// Function: Deconstructor
// Inputs:  void
// Outputs: void
// Description:
Menu::~Menu()
{
}

// Function: quit
// Inputs: void
// Outputs: void
// Description: redirects to the system's quit function.
void Menu::quit()
{
	system.quit();
}

// Function: switchRoom
// Inputs: A room name
// Outputs: displays "Which meeting room to connect?:"
// Description: redirects to the system's switchRoom function.
void Menu::switchRoom()
{
	cout << "\tWhich meeting room to connect?: ";
	getline(cin, input);
	system.switchRoom(input);	
}

// Function: displayAllMessages
// Inputs: void
// Outputs: void
// Description: redirects to the system's displayAllMessages function.
void Menu::displayAllMessages()
{
	system.displayAllMessages();
}

// Function: displayNewMessages
// Inputs: void
// Outputs: void
// Description: redirects to the system's displayNewMessages function.
void Menu::displayNewMessages()
{
	system.displayNewMessages();
}

// Function: createRoom
// Inputs: a room Name
// Outputs: "Please enter meeting room name:"
// Description: redirects to the system's addRoom function
void Menu::createRoom()
{	
	cout << "\tPlease enter meeting room name: ";
	getline(cin,input);
	system.addRoom(input);
}

// Function: createUser
// Inputs: user name
// Outputs: displays "Please enter user name:"
// Description: redirects to the system's addUser function
void Menu::createUser()
{
	cout << "\tPlease enter user name: ";
	getline(cin, input);
	system.addUser(input);
}

// Function:connectToRoom
// Inputs: room name
// Outputs: displays "Which meeting room to connect?:"
// Description: redirects to the system's connectToRoom function.
void Menu::connectToRoom()
{
	cout << "\tWhich meeting room to connect?: ";
	getline(cin, input);
	system.connectToRoom(input);
}

// Function: sendAMessage
// Inputs: A string
// Outputs: displays "Enter message: "
// Description: redirects to the system's sendMessage function.
void Menu::sendAMessage()
{
	cout << "\tEnter message: ";
	getline(cin, input);
	system.sendMessage(input);
}

// Function: switchUser
// Inputs: a user name
// Outputs: displays "Please enter user name: "
// Description: redirects to the system's switchUser function.
void Menu::switchUser()
{
	cout << "\tPlease enter user name: ";
	getline(cin, input);
	system.switchUser(input);
}

// Function: isValid
// Inputs: string to be validated
// Outputs: true if the input is valid or false otherwise.
// Description: Checks to see if the input is valid by checking if 
//				there are  more than one character and if the first character
//				is a number from 1-9.
bool Menu::isValid(string input)
{
	if(input.empty())
	{
		return false;
	}

	if(input.length() > 1)
	{
		return false;
	}

	if (input[0] -'0' < 1 || input[0] - '0' > 9)
	{
		return false;
	}
	return true;
}


// Function: menuPrompt
// Inputs: void
// Outputs: menu
// Description: Displays the menu and prompt the user for a selection
void Menu::menuPrompt()
{
   cout << "1) Create a meeting room" << endl;
   cout << "2) Create a new user" << endl;
   cout << "3) Connect to a meeting room" << endl;
   cout << "4) Send a message" << endl;
   cout << "5) Display new messages" << endl;
   cout << "6) Display all messages" << endl;
   cout << "7) Switch to a different user" << endl;
   cout << "8) Switch to a different meeting room" << endl;
   cout << "9) Quit the meeting room application" << endl << endl;   
   cout << "\tPlease choose an option: ";
   getline(cin,input);
	
  if(isValid(input))
  {
	//Since after validation it is safe 
	//to assume the first letter of the
	//input is a number within the range 1-9.
	selection = input[0] - '0';
   
   switch (selection)
   {
   case 1:
	   createRoom();
	   break;
   case 2:
	   createUser();
	   break;
   case 3:
	   connectToRoom();
	   break;
   case 4:
	   sendAMessage();
	   break;
   case 5:
	   displayNewMessages();
	   break;
   case 6:
	   displayAllMessages();
	   break;
   case 7:
	   switchUser();
	   break;
   case 8:
	   switchRoom();
	   break;
   case 9:
	   quit();
	   break;
   default:
	   cout << "\n\n**Sorry, invalid input**\n\n";
   }
  }
  else{
	  cout << "\n\n**Sorry, invalid input**\n\n";
  }
}

