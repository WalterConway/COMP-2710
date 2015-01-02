// Program 1:		The system object of the meeting room application
// File:			System.h
// Description:		Class definition of the System class.

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include "User.h"
#include "Room.h"
#include "Connector.h"
using namespace std;

#ifndef System_H
#define System_H
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
#endif