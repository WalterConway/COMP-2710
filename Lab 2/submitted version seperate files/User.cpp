#include "User.h"
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