#include "System.h"
// Function: constructor 
// Inputs: void
// Outputs: sends out the welcome message
// Description: sets the current room and current user to null.
//				sets the current connector to null as well.
System::System()
{
   WelcomeMessage();
   currentRoom = NULL;
   currentUser = NULL;
   currentConnector = NULL;
}

// Function: deconstructor
// Inputs:
// Outputs:
// Description:
System::~System()
{
}

// Function: WelcomeMessage
// Inputs: void
// Outputs: displays the welcome message of the system.
// Description: displays the welcome message of the system.
void System::WelcomeMessage()
{
		cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tWelcome to the Meeting Room Application!";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
}

// Function: fareWellMessage
// Inputs: void
// Outputs: displays the fare well message of the system.
// Description: when called displays the farewell message.
void System::fareWellMessage()
{
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tThank you for using the meeting room application";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
}

// Function: userGreeting
// Inputs: user name
// Outputs: displays a message welcoming that user
// Description: when called displays a message to welcome him/her.
void System::userGreeting(string name){

	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(45);
	cout << left << "\t\tWelcome, " + name +"!";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
}

// Function: quit
// Inputs: void
// Outputs: displays the fare well message
// Description: terminates the application
void System::quit()
{
   fareWellMessage();
   exit(1);
}

// Function: getRoomAmount
// Inputs: void
// Outputs: returns a number of how many rooms were created
// Description: retrieves the number of rooms in the list.
int System::getRoomAmount()
{
	   return roomListPointers.size();
}

// Function: getUserAmount
// Inputs: void
// Outputs: returns the number of users there are
// Description: retrieves the number of rooms in the list.
int System::getUserAmount()
{
   return userListPointers.size();
}

// Function: getConnectorAmount
// Inputs: void
// Outputs: returns how many connection there are total
// Description: retrieves the number of connectors in the list
int System::getConnectorAmount()
{
   return connectorListPointers.size();
}

// Function: addUser
// Inputs: user name
// Outputs: welcome message or error message accordingly
// Description:When called it sets the current user as the new user
//				also adds the current user into the list.
//				It also checks if the last item inserted into the list
//				matches the name based passed through, which means that the
//				add was successful else the user was not added is displayed.
void System::addUser(string name)
{
	if(!findUser(name))
	{
		currentRoom = NULL;
		currentConnector = NULL;
		currentUser = new User(name);	
   
   userListPointers.push_back(currentUser);
      if( name == (*userListPointers.back()).getName())
	  {
		  userGreeting(name);
	  }
	  else
	  {
		  cout << endl << "**User was not added**" << endl ;
	  }
	}
	else
	{
		cout << "\n\n**User name has already been taken.**\n\n";
	}
}

// Function: findRoom
// Inputs: room name
// Outputs: true if room exist false otherwise
// Description: Will return true when the first occurance of the room name is found in the list.
bool System::findRoom(string name)
{
	for(list<Room*>::iterator it = roomListPointers.begin(); it != roomListPointers.end(); it++)
	{
		if((*(*it)).getName() == name)
		{
			return true;
		}
	}
	return false;
}

// Function: findUser
// Inputs: user name
// Outputs: true if user exist false otherwise
// Description: Will return true when the first occurance of the user name is found in the list.
bool System::findUser(string name)
{
	for(list<User*>::iterator it = userListPointers.begin(); it != userListPointers.end(); it++)
	{
		if((*(*it)).getName() == name)
		{
			return true;
		}
	}
	return false;
}

// Function: findRoomPointer
// Inputs: room name
// Outputs: the pointer to that room if not found returns NULL
// Description: locates and returns the pointer associated with this room.
Room* System::findRoomPointer(string name)
{
	for (list<Room*>::iterator it = roomListPointers.begin(); it != roomListPointers.end(); it++)
	{ 
		if((*(*it)).getName() == name)
		{
			return *it;
		}
	}
	return NULL;
}

// Function: findUserPointer
// Inputs: user name
// Outputs: user pointer to that name if not found returns NULL
// Description: locates and returns the pointer associated with this user.
User* System::findUserPointer(string name)
{
	for (list<User*>::iterator it = userListPointers.begin(); it != userListPointers.end(); it++)
	{
		if((*(*it)).getName() == name)
		{
			return *it;
		}
	}
	return NULL;
}

// Function: roomEntranceBanner
// Inputs: user name and room name
// Outputs: banner that includes the user name and room name inputted.
// Description: displays the room entrace banner that includes the values inputted.
void System::roomEntranceBanner(string userName, string roomName)
{
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\t"+userName + " is now in the " + roomName + " Meeting room!";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
}

// Function: roomCreationBanner
// Inputs: room name
// Outputs: banner that includes room name inputted.
// Description: displays a box that signifies a room has been created.
void System::roomCreationBanner(string roomName)
{
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tMeeting room " + roomName + " has been created.";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
}

// Function: addRoom
// Inputs: room name
// Outputs: outputs accordingly, if there is an error or a successful execution
// Description: When called adds the room to the list of rooms
//				also it checks if it was a sucessful add.
void System::addRoom(string name)
{
	if(!(findRoom(name)))
	{
		roomListPointers.push_back(new Room(name));
		if(name == (*roomListPointers.back()).getName())
		{
			roomCreationBanner(name);
		}
	}
	else{
		cout << "\n\n**Sorry there is already a room by that name.**\n\n";
	}
}

// Function: getCurrentRoom
// Inputs: void
// Outputs: name of the current room.
// Description: When called grabs the current room name
//				and returns it. Otherwise displays that your not 
//				currently connected to a room.
string System::getCurrentRoom()
{
	if(isConnected())
	{
		return (*currentRoom).getName();
	}
	return "\n\n**You are currently in no room**\n\n";
}

// Function: getCurrentUser()
// Inputs: void
// Outputs: returns the current user name
// Description: When called grabs the current user name
//				and returns it. Otherwise displays that there is
//				not a currently connected user.
string System::getCurrentUser()
{
	if((currentUser != NULL))
	{
		return (*currentUser).getName();
	}
	return "\n\n**There is currently no current User**\n\n";
}

// Function: createConnection
// Inputs: void
// Outputs: void
// Description: creates a connection involving the current user and room 
//				also sets the user's present connection name.
void System::createConnection()
{
	currentConnector = new Connector(currentUser, currentRoom);
	connectorListPointers.push_back(currentConnector);
	(*currentUser).setPresentConnectionName(getCurrentRoom());
}

// Function: findPreviousConnection
// Inputs: user name, room name
// Outputs: returns a pointer to the connector or returns NULL
// Description: returns previous connection to room or if not found returns NULL.
Connector* System::findPreviousConnection(string userName, string roomName)
{
	for(list<Connector*>::iterator it = connectorListPointers.begin(); it != connectorListPointers.end(); it++)
	{
		if((*((*(*it)).getUserPointer())).getName() == userName && (*((*(*it)).getRoomPointer())).getName() == roomName)
		{
			return *it;
		}
	}
	return NULL;
}

// Function: connectToRoom
// Inputs: room name
// Outputs: void
// Description: Checks to see if there is even a room avaliable first.
//				then cycles through the list of rooms in attempt to find
//				the room name and when found sets the room object as the current
//				room. Outputs errors accordingly
void System::connectToRoom(string name)
{
	if(getRoomAmount() >	0)
	{
		if(currentUser != NULL)
		{
			Connector *ConnectionPointer = findPreviousConnection(getCurrentUser(), name);
			if(ConnectionPointer != NULL)
			{
				currentConnector = ConnectionPointer;
				roomEntranceBanner(getCurrentUser(), getCurrentRoom());
			}
			else
			{
				Room *roomPointer = findRoomPointer(name);
				if(roomPointer != NULL)
				{
					currentRoom = roomPointer;
					createConnection();
					roomEntranceBanner(getCurrentUser(), getCurrentRoom());
				}
				else
				{
					cout << "\n\n**There is no room by that name try again**\n\n";
				}
			}
		}
		else
		{
			cout << "\n\n**Sorry there is not a current user set. Create a user and try again.**\n\n";
		}
	}
	else
	{
            cout << "\n\n**Sorry there are no meeting rooms for you to connect to.**\n"
				 << "Hint: Try to create one and try again.\n\n";
	}
}

// Function: switchRoom
// Inputs: room name
// Outputs: void
// Description: Checks if there are more than 1 room avaiable, since you can only switch to another room if there is actually another room there to switch to.
//				If a incorrect name is used a continuous prompt will happen for a correct room name.
//				Checks if room name exist, also checks if a previous connection is avaiable based on the current user.
//				if the room name is not found ti is set to NULL. messages are sent if sucess errors messages otherwise.
void System::switchRoom(string name)
{
	if(getRoomAmount() > 1)
	{
		if(!findRoom(name))
		{
			currentRoom = NULL;
			cout << "\n\n**That room name does not exist.**\n\n" << endl;
			do
			{
				cout << "Enter a room name that exist: ";
				getline(cin, name);
			} while (!findRoom(name));
		}

			Connector *previousConnection = findPreviousConnection(getCurrentUser(),name);
			if (previousConnection != NULL){
				currentConnector = previousConnection;
				currentRoom = (*previousConnection).getRoomPointer();
				(*currentUser).setPresentConnectionName(getCurrentRoom());
				roomEntranceBanner(getCurrentUser(), getCurrentRoom());
			}
			else
			{
				cout << "\n\n**Sorry you have yet to establish a connection to this meeting room**\n\n";
			}
		
	}
	else
	{
		cout << endl;
		cout << "**Sorry there are no other meeting rooms for you to connect to.**" 
         << endl	<< "Hint: Try to create one and try again." << endl << endl;
	}
}

// Function: switchUser
// Inputs: user name
// Outputs: void
// Description: Checks if there is more than one user since switching implies that there should be another user to switch to.
//				checks if the user exist if not then a continous prompt for a correct user name.
//				If a correct user name does exist the user's previously connector is put in place. Two users that are not connected to
//				a room can switch.
void System::switchUser(string name)
{
	if(getUserAmount() > 1)
	{
		if(!findUser(name))
		{
			cout << "\n\n**That user name does not exist.**\n\n" << endl;
			do
			{
				cout << "Enter a user name that exist: ";
				getline(cin, name);
			} while (!findUser(name));
		}
		User *userPointer = findUserPointer(name);
		if(userPointer != NULL)
		{
			currentConnector = findPreviousConnection((*userPointer).getName(),(*userPointer).getPresentConnectionName());
            currentUser = userPointer;
			if(currentConnector != NULL)
			{
				currentRoom = (*currentConnector).getRoomPointer();
				roomEntranceBanner(getCurrentUser(),getCurrentRoom());
			}
			else
			{
				currentRoom = NULL;
				userGreeting(getCurrentUser());
			}
		}
	}
	else
   {
	   cout << endl;
	   cout << "**Sorry there are no other users you can switch to.**" 
		   << endl	<< "Hint: Try to create one and try again." << endl << endl;
	}
}

// Function: isConnected
// Inputs: void
// Outputs: returns true if a current connector is not null false otherwise
// Description: returns true if the current connector is not null.
//				returns false if the current connector is null.
bool System::isConnected()
{
	if(currentConnector != NULL){
		return true;
	}
	return false;
}

// Function: sendMessage
// Inputs: string for a message
// Outputs: error if user is not connected to a room
// Description: sends a message to the currently connected room.
void System::sendMessage(string message)
{
	if(isConnected())
	{
		(*currentRoom).sendMessage("\t" + getCurrentUser() + ": "+ message +"\n");
	}
	else
	{
		cout << "\n\n**Sorry you have to be connected to a room before sending messages.**\n\n";
	}
}

// Function: displayAllMessages
// Inputs: void
// Outputs: error if user is not currently connected to a room.
// Description: redirects to the current connector to output all messages
void System::displayAllMessages()
{
	if(isConnected()){
		(*currentConnector).getAllMessages();
	}
	else{
		cout << "\n\n**Sorry your not currently connected to a room**\n\n";
	}
}

// Function: displayNewMessages
// Inputs: void
// Outputs: error if user is not currently connected to a room.
// Description: redirects to the current connector to output new messages
void System::displayNewMessages()
{
	if(isConnected())
	{
		(*currentConnector).getNewMessages();
	}
	else
	{
		cout << "\n\n**Sorry your not currently connected to a room**\n\n";
	}
}