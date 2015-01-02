// Program 2:	Distributed Messaging System
// Name:		Walter Conway
// Class:		COMP 2710
// Date:		July 10, 2013
// E-Mail:		wjc0008@auburn.edu
//
// Description:	This program will simulate a Distributed Messaging System.

#include <fstream>
#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstdio>

#define MAX 10 //sets the total amount of friends and users there can be.

using namespace std;

class Friend
{
private:
	string name;
public:
	~Friend();
	Friend();
	Friend(string userName);
	string getName();
	void setName(string userName);
};


class Pipe
{
private:
	string usr;
public:
	string friendOfUsr;
	ofstream outputFile;
	ifstream inputFile;
	Pipe();
	Pipe(string userName, string friendName);
	~Pipe();
	void receiveFlow();
	bool sendFlow(string message);
	void setUser(string userName);
	string getUser();
	void setFriend(string friendName);
	string getFriend();
	string fileNameSend;
	string fileNameReceive;
};

class User
{
private:

string name;
Friend *friendList[MAX];
Pipe *pipeList[MAX];
int friendCount;
public:
	User();
	~User();
	User(string userName);
	string getName();
	void setName(string userName);
	bool addFriend(string friendName);
	void addPipe(string friendName);
	int findPipe(string friendName);
	Pipe* getPipe(string friendName);
	void decrementPipeCount();
	int getPipeCount();
	int pipeCount;
	void setPipeCount(int newValue);
	void incrementPipeCount();
	int findFriend(string friendName);
	int getFriendCount();
	void setFriendCount(int newValue);
	void decrementFriendCount();
	void incrementFriendCount();
	void printFriends();
	Friend* getFriend(string friendName);
};

class MessageSystem
{
private:
	User *currentUser;
	Friend *currentFriend;
	Pipe *currentPipe;
	User *userList[MAX];
	int userCount;

public:
	MessageSystem();
	~MessageSystem();
	void selectFriend();
	void sendMessage();
	void receiveMessage();
	void quit();
	int findUser(string userName);
	void addUser();
	User* getCurrentUser();
	void setCurrentUser(User *userPointer);
	Pipe* getCurrentPipe();
	void setCurrentPipe(string friendName);
	Friend* getCurrentFriend();
	void setCurrentFriend(string friendName);
	int getUserCount();
	void setUserCount(int newValue);
	void getFriendList();
	void decrementUserCount();
	void incrementUserCount();
	void welcomeMessage();
	void welcomeMessage(string userName);
	void connectedMessage(string userName);
	void messageSentMessage(string userName);
	void disconnectMessage(string userName);
	void farewellMessage();
};

class Menu
{
private:
public:
	Menu();
	~Menu();
	void DisplayMenu();
	MessageSystem MessagingSystem;
	bool isValid(string input);
};


// Function: default constructor
// Inputs: void
// Outputs: void
// Description: void
Friend::Friend()
{

}

// Function: overloaded 
// Inputs: string user name
// Outputs: void
// Description: initialize a friend object
Friend::Friend(string userName)
{
	name = userName;
}

// Function: deconstructor
// Inputs: void
// Outputs: void
// Description: void
Friend::~Friend()
{

}

// Function: get name
// Inputs: void
// Outputs: string friend name
// Description: return the friend name
string Friend::getName()
{
return name;
}

// Function: set name
// Inputs: string user name
// Outputs: void
// Description: sets the the friend name
void Friend::setName(string userName)
{
	name = userName;
}

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

// Function: default constructor
// Inputs: void
// Outputs: void
// Description: initialize the message system object and displays welcome message
MessageSystem::MessageSystem()	
{
	userCount = 0;
	currentFriend = NULL;
	currentPipe = NULL;
	currentUser = NULL;
	welcomeMessage();
}

// Function: deconstructor
// Inputs: void
// Outputs: void
// Description: void
MessageSystem::~MessageSystem()
{
	delete currentUser;
	delete currentFriend;
	delete currentPipe;
	delete [] *userList;
}

// Function: select friend
// Inputs: void
// Outputs: void
// Description: makes a new friend and sets friend as current friend
void MessageSystem::selectFriend()
{
	string friendName;
	int friendIndex;
	do
	{
	cout << "Please enter Friend's name: ";
	getline(cin, friendName);
	} while(friendName.empty());
	if ((*getCurrentUser()).getName() != friendName)
	{
	if (getCurrentFriend() == NULL || (*getCurrentFriend()).getName() != friendName)
	{
		friendIndex = (*currentUser).findFriend(friendName);
		if(friendIndex != -1)
		{
			setCurrentFriend(friendName);
			setCurrentPipe(friendName);
		}
		else
		{
			if ((*currentUser).addFriend(friendName))
			{
				setCurrentFriend(friendName);
				setCurrentPipe(friendName);
			}
		}
	}
	else
	{
		cout << "\n\n**You are already connected to " + friendName + ".**\n\n";
	}
	}
	else
	{
		cout << "\n\n**You can not connect to yourself.**\n\n";
	}
}

// Function: send message
// Inputs: void
// Outputs: void
// Description: prompts for a message and redirects to the pipe where it sends the message.
void MessageSystem::sendMessage()
{
	if (getCurrentPipe() != NULL)
	{
		string message;
		do
		{
		cout << "Enter Message: ";
		getline(cin, message);
		} while(message.empty());
		if((*currentPipe).sendFlow(message))
		{
		messageSentMessage((*getCurrentFriend()).getName());
		}
	}
	else
	{
		cout << "\n\n**There is currently no connection to a friend.**\n\n";
	}
}

// Function: receive message
// Inputs: void
// Outputs: void
// Description: redirects to the pipe object where it recieve the messages
void MessageSystem::receiveMessage()
{
	if (getCurrentPipe() != NULL)
	{
		(*currentPipe).receiveFlow();
	}
	else
	{
		cout << "\n\n**There is currently no connection to a friend.**\n\n";
	}
}

// Function: quit
// Inputs: void
// Outputs: void
// Description: displays farewell message and exits the program
void MessageSystem::quit()
{
	farewellMessage();
	exit(1);
}

// Function: welcome message
// Inputs: void
// Outputs: void
// Description: display a welcome message
void MessageSystem::welcomeMessage()
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
	cout << left << "\tAuburn Distriuted Messaging system!";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl <<endl;
}

// Function: welcome message overloaded
// Inputs: string user name
// Outputs: void
// Description: displays a custom message for the inputted user.
void MessageSystem::welcomeMessage(string userName)
{
	cout << endl;
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tAuburn Distriuted Messaging system, " + userName + "!";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl << endl;
}

// Function: connected message
// Inputs: string user name
// Outputs: void
// Description: displays a connected message for when a user connects to a friend
void MessageSystem::connectedMessage(string userName)
{
	cout << endl;
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tConnected to " + userName;
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl << endl;
}

// Function: disconnect message
// Inputs: string user name
// Outputs: void
// Description: used when a user sets a current friend when it is not null
void MessageSystem::disconnectMessage(string userName)
{
	cout << endl;
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tDisconnected from " + userName;
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl << endl;
}

// Function: message sent message
// Inputs: string user name
// Outputs: void
// Description: displays a Affirmation when message is sent
void MessageSystem::messageSentMessage(string userName)
{
	cout << endl;
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tMessage sent to " + userName;
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl << endl;
}

// Function: farewell message
// Inputs: void
// Outputs: void
// Description: displays a message saying thanks for using
void MessageSystem::farewellMessage()
{
	cout << endl;
	cout<<"\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl;
	cout << "\t#";
	cout.fill(' ');
	cout.width(52);
	cout << left << "\tThank you for using the messaging system";
	cout << "#";
	cout << endl << "\t";
	cout.fill('#');
	cout.width(60);
	cout.left;
	cout << "" <<endl << endl;
}

// Function: add user
// Inputs: void
// Outputs: void
// Description: diplays a prompt to enter a user which is added to the list and set as current user.
void MessageSystem::addUser()
{
	string userName;
	do
	{
		cout << "Please enter user name: ";
		getline(cin, userName);
	} while(userName.empty());

	if(getUserCount() != MAX)
	{
		userList[getUserCount()] = new User(userName);
		setCurrentUser(userList[getUserCount()]);
		incrementUserCount();
	}
	else
	{
		cout << "Added too many users, delete some.";
	}
}

// Function: get friend list
// Inputs: void
// Outputs: void
// Description: displays all the current user's friends in a list
void MessageSystem::getFriendList()
{
	cout << "-----------------\n";
	cout << "Friend List\n";
	cout << "-----------------\n";
	(*getCurrentUser()).printFriends();
	cout << endl;
}

// Function: get current user
// Inputs: void
// Outputs: returns a user pointer to the current user.
// Description: returns a user pointer to the current user.
User* MessageSystem::getCurrentUser()
{
	return currentUser;
}

// Function: find user
// Inputs: string user name
// Outputs: returns integer that states where the user is at in the list. or displays a -1 otherwise.
// Description: returns the first instance of the user's name
int MessageSystem::findUser(string userName)
{	
		for(int i = 0 ; i < getUserCount() ; i++)
		{
			if((*userList[i]).getName() == userName)
			{
				return i;
			}
		}	
	return -1;
}

// Function: set current user
// Inputs: user pointer
// Outputs: void
// Description:sets the current user to the pointer specified. 
void MessageSystem::setCurrentUser(User *userPointer)
{
	currentUser = userPointer;
	welcomeMessage((*getCurrentUser()).getName());
}

// Function: get current pipe
// Inputs: void
// Outputs: returns the current pipe of the system.
// Description: 
Pipe* MessageSystem::getCurrentPipe()
{
	return currentPipe;
}

// Function: set current pipe
// Inputs: string friend name
// Outputs: void
// Description: sets the current pipe to the friend name specified.
void MessageSystem::setCurrentPipe(string friendName)
{
	currentPipe = (*getCurrentUser()).getPipe(friendName);	
}

// Function: get current friend
// Inputs: void
// Outputs: friend pointer
// Description: returns the pointer to the current  friend.
Friend* MessageSystem::getCurrentFriend()
{
	return currentFriend;
}

// Function: set current friend
// Inputs: string friend name
// Outputs: void
// Description: sets the current friend the the current friend specified.
void MessageSystem::setCurrentFriend(string friendName)
{
	if(currentFriend != NULL)
	{
		disconnectMessage((*getCurrentFriend()).getName());
	}
	currentFriend = (*getCurrentUser()).getFriend(friendName);
	connectedMessage(friendName);
}

// Function: get user count
// Inputs: void
// Outputs: integer of the amount of users
// Description: returns the amount of users.
int MessageSystem::getUserCount()
{
	return userCount;
}

// Function: set user count
// Inputs: integer of how many users there are.
// Outputs: void
// Description: sets the user amount in the system.
void MessageSystem::setUserCount(int newValue)
{
	userCount = newValue;
}

// Function: decrement user count
// Inputs: void
// Outputs: void
// Description: decrements the user count in the system by one.
void MessageSystem::decrementUserCount()
{
	userCount--;
}

// Function: increment user count
// Inputs: void
// Outputs: void
// Description: increments the user count in the system by one.
void MessageSystem::incrementUserCount()
{
	userCount++;
}

// Function: default constructor
// Inputs: void
// Outputs: void
// Description: default constructor
Pipe::Pipe(){

}

// Function: overloaded constructor
// Inputs: user name and friend name
// Outputs: void
// Description: initialize a pipe
Pipe::Pipe(string userName, string friendName) :
	usr(userName), friendOfUsr(friendName)
{
	fileNameSend = userName + "-" + friendName + ".txt";
	fileNameReceive = friendName + "-" +userName + ".txt";	
}

// Function: deconstructor
// Inputs: void
// Outputs: void
// Description: void
Pipe::~Pipe()
{

}

// Function: receive flow
// Inputs: void
// Outputs: void
// Description: output messages from the pipe 
void Pipe::receiveFlow()
{
	inputFile.open(fileNameReceive.c_str(), ios::in);
	cout << "Message(s) from " + getFriend() + ":\n";
	if(inputFile.fail())
	{
		cerr << "**Sorry no messages**\n\n";
	}
	else
	{
		char character;
		inputFile.get(character);
		while(!inputFile.eof())
		{
		cout << character;
		inputFile.get(character);
		}
		inputFile.close();
		if(remove(fileNameReceive.c_str()) != 0)
		{
			cout << "**Error deleting pipe.**\n";
		}
	}
}

// Function: send flow
// Inputs: string message
// Outputs: bool true if file can be opened false otherwise.
// Description: sends message to pipe
bool Pipe::sendFlow(string message)
{
	outputFile.open(fileNameSend.c_str(), ios::app | ios::out);
	if(outputFile.fail())
	{
		cout << "**Error sending message.**\n";
		return false;
	}
	else
	{
	outputFile << message << endl;
	outputFile.close();
	return true;
	}
}

// Function: set user
// Inputs: string username
// Outputs: void
// Description: sets the user
void Pipe::setUser(string userName)
{
	usr = userName;
}

// Function: get user
// Inputs: void
// Outputs: string user
// Description: returns the user of the pipe
string Pipe::getUser()
{
	return usr;
}

// Function: set friend
// Inputs: string friend name
// Outputs: void
// Description:  sets the the name of the friend in the pipe
void Pipe::setFriend(string friendName)
{
	friendOfUsr = friendName;
}

// Function: get friend
// Inputs: void
// Outputs: string friend name
// Description:  returns the name of the friend in the pipe.
string Pipe::getFriend()
{
	return friendOfUsr;
}

// Function: default constructor
// Inputs: 
// Outputs: 
// Description: 
User::User()
{

}

// Function: overloaded constructor
// Inputs: A Name of a User
// Outputs: void
// Description: initalizes a User object
User::User(string userName)
{
name = userName;
friendCount = 0;
pipeCount = 0;
}

// Function: deconstructor
// Inputs: void
// Outputs: void
// Description: void
User::~User()
{
	delete [] *pipeList;
	delete [] *friendList;
}

// Function: Get Name
// Inputs: void
// Outputs: string of the user
// Description: returns the name of the user
string User::getName()
{
	return name;
}

// Function: Set Name
// Inputs: string of a user
// Outputs: void
// Description: Sets the name of the user.
void User::setName(string userName)
{
	name = userName;
}

// Function: Get Friend count
// Inputs: void
// Outputs: int number of friends
// Description: returns the amount of friends the user has. 
int User::getFriendCount()
{
	return friendCount;
}

// Function: Add a user
// Inputs: Friend's name
// Outputs: boolean
// Description: returns true if the friend was added return false otherwise.
bool User::addFriend(string friendName)
{
	if(getFriendCount() != 10){
		friendList[getFriendCount()] = new Friend(friendName);
		if(friendList[getFriendCount()] == NULL)
		{
			cout << "Error: Insufficient memory.\n";
			exit(1);
		}
		incrementFriendCount();	
		addPipe(friendName);
		return true;
	}
	else
	{
		cout << "Sorry you have maxed out your Friends.\n";
		return false;
	}
}

// Function: decrement friend count
// Inputs: void
// Outputs: void
// Description: decrements the count of friend
void User::decrementFriendCount()
{
	if(friendCount != 0)
	{
		friendCount--;
	}
}

// Function: increment friend count
// Inputs: void
// Outputs: void
// Description: increment friend count
void User::incrementFriendCount()
{	
	friendCount++;	
}

// Function: print friends
// Inputs: void
// Outputs: void
// Description: displays all the friends of the current user
void User::printFriends()
{
	for(int i = 0 ; i < getFriendCount() ; i++)
	{
		cout << (*friendList[i]).getName() << endl;
	}

}

// Function: find friend
// Inputs: friend name
// Outputs: integer of the where the user is located in the list
// Description: returns the location of where the inputted user is located in the friend list.
int User::findFriend(string friendName)
{
	for(int i = 0; i < getFriendCount() ; i++)
	{
		if((*friendList[i]).getName() == friendName)
		{
			return i;
		}
	}
	return -1;
}

// Function: set friend count
// Inputs: integer
// Outputs: void
// Description: sets the count of friends
void User::setFriendCount(int newValue)
{
	friendCount = newValue;
}

// Function: get friend
// Inputs: friend name
// Outputs: returns pointer of a inputted friend
// Description:  returns a friend pointer.
Friend* User::getFriend(string friendName)
{
	int friendIndex = findFriend(friendName);
	if(friendIndex != -1)
	{
		return friendList[friendIndex];
	}
	else
	{
		return NULL;
	}
}

// Function: add pipe
// Inputs: friend name
// Outputs: void
// Description: adds a pipe or a connection to the chosen friend name.
void User::addPipe(string friendName)
{
	if(getPipeCount() != 10)
	{
		pipeList[getPipeCount()] = new Pipe(getName(), friendName);
		if( pipeList[getPipeCount()] == NULL)
		{
			cout << "Error: Insufficient memory.\n";
			exit(1);
		}
		incrementPipeCount();
	}
	else
	{
		cout << "Added too many pipes, delete some.";
	}
}

// Function: find pipe
// Inputs: friend name
// Outputs: integer of where the pipe is located in the list
// Description: returns the first instance of the user's name and friend's name
int User::findPipe(string friendName)
{
	if(getPipeCount() != 0)
	{
		for(int i = 0 ; i < getPipeCount() ; i++)
		{
			if((*pipeList[i]).getFriend() == friendName){
				return i;
			}
		}		
	}
	return -1;
}

// Function: get pipe
// Inputs: friend name
// Outputs: a pipe pointer
// Description:returns the pointer of the friend name entered. 
Pipe* User::getPipe(string friendName)
{
	int indexOfFriend = findPipe(friendName);
	if(indexOfFriend != -1)
	{
		return pipeList[indexOfFriend];
	}

	return NULL;
}

// Function: decrement pipe count
// Inputs: void
// Outputs: void
// Description: decrements pipe count.
void User::decrementPipeCount()
{
	pipeCount--;
}

// Function: set pipe count
// Inputs: integer value
// Outputs: void
// Description: sets the amount of connections or pipes.
void User::setPipeCount(int newValue)
{
	pipeCount = newValue;
}

// Function: get pipe count
// Inputs: void
// Outputs: integer of pipe count
// Description: returns the amount of pipes or connections
int User::getPipeCount()
{
	return pipeCount;
}
// Function: increment pipe count
// Inputs: void
// Outputs: void
// Description: increment the amount of pipes or connections by one.
void User::incrementPipeCount()
{
	pipeCount++;
}

int main()
{
	Menu menuObj;
	while(true)
	{		
		menuObj.DisplayMenu();
	}
	return 0;
}