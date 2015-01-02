#include <string>
#include <iostream>
#include "Friend.h"
#include "Pipe.h"
using namespace std;

#ifndef USER_H
#define USER_H
class User
{
private:
string name;
Friend *friendList[10];
Pipe *pipeList[10];
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
#endif