#include "MessageSystem.h"
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

	if(getUserCount() != 10)
	{
		userList[getUserCount()] = new User(userName);
		if(userList[getUserCount()] == NULL)
		{
			cout << "Error: Insufficient memory.\n";
			exit(1);
		}
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