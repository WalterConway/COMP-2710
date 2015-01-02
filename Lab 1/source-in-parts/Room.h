// Program 1:		Room object of the meeting room application.
// File:			Room.h
// Description:		Class definition of the Room class.
#include <iostream>
#include <string>
using namespace std;

#ifndef Room_H
#define Room_H
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
#endif