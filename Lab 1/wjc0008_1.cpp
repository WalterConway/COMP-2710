// Program 1:	Meeting Room Application
// Name:		Walter Conway
// Class:		COMP 2710
// Date:		June 18, 2013
// E-Mail:		wjc0008@auburn.edu
//
// Description:	This program will simulate a meeting room with multiple users and rooms.
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;



class Room {
private:
   string name;
   string chatBuffer;

public:  
   Room(string roomName);
   ~Room();
   string getName() const;
   string getMessage() const;
   void setName(string roomName);
   void sendMessage(string message);
};



class User {  
public:
   User();
   ~User();   
   User(string Username);   
   string getName() const;   
   void setName(string userName);
   string getPresentConnectionName();
   void setPresentConnectionName(string roomName);   
   
private:
   string name;
   string presentConnectionName;   
   };

class Connector
{
public:
	Connector();
	Connector(User *userAddress, Room *roomAddress);
	~Connector();
	void setUserPointer(User *userAddress);
	void setRoomPointer(Room *roomAddress);
	User* getUserPointer();
	Room* getRoomPointer();
	void getNewMessages();
	void getAllMessages();
	int getNewMsgPlaceMark();
	int getAllMsgPlaceMark();
	void setNewMsgPlaceMark(int placementNumber);
	void setAllMsgPlaceMark(int placementNumber);

private:
	User *userName;
	Room *meetingRoom;
	int newMsgPlaceMark; //Stores the index of the message buffer in the room for the use to get new messages.
	int allMsgPlaceMark; //Stores the index of the message buffer in the room for the use to get all message.	
};

class System {
public:
	System();
	~System();
	int getUserAmount();
	int getRoomAmount();
	int getConnectorAmount();
	void connectToRoom(string name);
	void WelcomeMessage();
	void addUser(string name);
	void addRoom(string name);
	void switchUser(string name);
	void switchRoom(string name);
	void fareWellMessage();
	void roomEntranceBanner(string userName, string roomName);
	void quit();
	bool findRoom(string name);
	bool findUser(string name);
	Room* findRoomPointer(string name);
	User* findUserPointer(string name);
	bool isConnected();
	void sendMessage(string message);
	void displayNewMessages();
	void displayAllMessages();
	void createConnection();
	Connector* findPreviousConnection(string userName, string roomName);
	string getCurrentRoom();
	string getCurrentUser();
	void userGreeting(string name);
	void roomCreationBanner(string roomName);

private:
	list<User*> userListPointers;
	list<Room*> roomListPointers;	
	list<Connector*> connectorListPointers;	
	User *currentUser;
	Room *currentRoom;
	Connector *currentConnector;
}; 

class Menu
{
 private:
   int selection;
   System system;
   string input; 
 
 public:
   Menu();
   ~Menu();   
   void menuPrompt();
   void quit();
   void switchRoom();
   void displayAllMessages();
   void displayNewMessages();
   void createRoom();
   void createUser();
   void connectToRoom();
   void sendAMessage();
   void switchUser();
   bool isValid(string input); 
 
};

Connector::Connector()
{
}
// Function: Connector class constructor
// Inputs: user pointer, room pointer
// Outputs: void
// Description: Initalizes the connector object for each connection to a room and user.
//				A user my have one or more connectors but only one connection to a particular room.
//				Ex. John connected to Blue room
//					 John connected to Red room
// John has two connectors in all one to Blue room and one to Red room.
Connector::Connector(User *userAddress, Room *roomAddress)
{
	userName = userAddress;
	meetingRoom = roomAddress;
	allMsgPlaceMark = ((*meetingRoom).getMessage()).length();
	newMsgPlaceMark = ((*meetingRoom).getMessage()).length();
}
//Deconstructor
Connector::~Connector()
{
}

// Function: setsUserPointer
// Inputs: A user's pointer
// Outputs: void
// Description: sets the connector's user pointer.
void Connector::setUserPointer(User *userAddress)
{
	userName = userAddress;
}

// Function: setRoomPointer
// Inputs: A room's pointer
// Outputs: void
// Description: sets the connector's room pointer.
void Connector::setRoomPointer(Room *roomAddress)
{
	meetingRoom = roomAddress;
}

// Function: getUserPointer
// Inputs: void
// Outputs: connector's user pointer
// Description: retrives the connector's user pointer.
User* Connector::getUserPointer()
{
	return userName;
}

// Function: getRoomPointer
// Inputs: void
// Outputs: connector's room pointer
// Description: retrives the connector's room pointer.
Room* Connector::getRoomPointer()
{
	return meetingRoom;
}

// Function: getAllMsgPlaceMark
// Inputs: void
// Outputs: returns the index value (Place Marker) of when the connector was created.
// Description: The purpose is to remember where the user first joined a room so messages can be retrieved.
int Connector::getAllMsgPlaceMark()
{
	return allMsgPlaceMark;
}

// Function: getNewMsgPlaceMark
// Inputs: void
// Outputs: returns the index value (Place Marker) of when the connector was created
//			or when the new message function was called last.
// Description: The purpose is to remember where the user last left off of checking their messages.
int Connector::getNewMsgPlaceMark()
{
	return newMsgPlaceMark;
}

// Function: setNewMsgPlaceMark
// Inputs: Integer of the placement value of where the user last left off check their messages.
// Outputs: void
// Description: sets the new message placement marker value.
void Connector::setNewMsgPlaceMark(int placementNumber)
{
	newMsgPlaceMark = placementNumber;
}

// Function: setAllMsgPlaceMark
// Inputs: Integer of the placement value of where the user first joined the room.
// Outputs: void
// Description: sets the all message placement marker value.
void Connector::setAllMsgPlaceMark(int placementNumber)
{
	allMsgPlaceMark = placementNumber;

}

// Function: getAllMessages
// Inputs: void
// Outputs: displays all messages based off the all message placement marker and the room's buffer.
// Description: Displays all The messages from which the user first came into the room.
void Connector::getAllMessages()
{
	if(((*meetingRoom).getMessage()).length() !=  getAllMsgPlaceMark())
	{
		setNewMsgPlaceMark(((*meetingRoom).getMessage()).length());
		cout << endl;
		cout << ((*meetingRoom).getMessage()).substr(getAllMsgPlaceMark());
		cout << endl;
	}
	else
	{
		cout << "\n\n**No new messages**\n\n";
	}
}

// Function: getNewMessages
// Inputs: void
// Outputs: displays all messages based off the new message placement marker and the room's buffer.
// Description: Displays all the messages that has yet been retrieved, either by all messages or new messages.
void Connector::getNewMessages()
{
	if(((*meetingRoom).getMessage()).length() !=  getNewMsgPlaceMark())
	{
		cout << endl;
		cout << ((*meetingRoom).getMessage()).substr(getNewMsgPlaceMark());
		cout << endl;
		setNewMsgPlaceMark(((*meetingRoom).getMessage()).length());
	}
	else
	{
		cout << "\n\n**No new messages**\n\n";
	}
}

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
   cout << "\tPlease choose an option:";
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

// Function: Constructor
// Inputs: room name
// Outputs: void
// Description: initializes the room name and chat buffer.
Room::Room(string roomName)
{
   name = roomName;
   chatBuffer = "";
}

// Function: deconstructor
// Inputs:
// Outputs:
// Description:
Room::~Room()
{
}

// Function: getMessage
// Inputs: void
// Outputs: message buffer
// Description: returns the Room's message buffer
string Room::getMessage() const
{
	return chatBuffer;
}

// Function: setName
// Inputs: room name
// Outputs: void
// Description: sets the name of the room
void Room::setName(string roomName)
{
   name = roomName;
}

// Function: sendMessage
// Inputs: a message
// Outputs: void
// Description: appends to the end of the chat buffer.
void Room::sendMessage(string message)
{
   chatBuffer.append(message);
}

// Function: getName
// Inputs: void
// Outputs: room name
// Description: returns the name of the room
string Room::getName() const
{
   return name;
}


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
	if(getRoomAmount() > 0)
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

   int main()
{
	Menu menuObj;
	do 
	{
	menuObj.menuPrompt();
	} while (true);
	return 0;
}