#include <cstdlib>
#include <string>
#include "User.h"
#include "Friend.h"
#include "Pipe.h"

#ifndef MESSAGESYSTEM_H
#define MESSAGESYSTEM_H
class MessageSystem
{
private:
	User *currentUser;
	Friend *currentFriend;
	Pipe *currentPipe;
	User *userList[10];
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
#endif