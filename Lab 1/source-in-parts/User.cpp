#include "User.h"

// Function: empty constructor
// Inputs: void
// Outputs:void
// Description:
User::User()
{
}

// Function: deconstructor
// Inputs:
// Outputs:
// Description:
User::~User()
{
}

// Function: constructor
// Inputs: user name
// Outputs: void
// Description: sets the user name and present connection.
User::User(string Username)
{
   name = Username;
   presentConnectionName = "";
}

// Function: getName
// Inputs: void
// Outputs: user name
// Description: returns the user's name
string User::getName() const 
{
   return name;
}

// Function: setName
// Inputs: user name
// Outputs: void
// Description: sets the user's name
void User::setName(string userName)
{
   name = userName;
}

// Function: getPresentConnectionName
// Inputs: void
// Outputs: returns the present connection name which is a room name
// Description: returns the room name of the user currently resides.
   string User::getPresentConnectionName()
   {
	   return presentConnectionName;
   }

// Function: setPresentConnectionName
// Inputs: room name
// Outputs: void
// Description: sets the present Connection name to the room name inputted.
   void User::setPresentConnectionName(string roomName)
   {
	   presentConnectionName = roomName;
   }