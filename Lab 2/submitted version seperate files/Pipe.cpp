#include "Pipe.h"
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