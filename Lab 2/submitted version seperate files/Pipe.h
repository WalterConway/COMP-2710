#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

#ifndef PIPE_H
#define PIPE_H
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
#endif