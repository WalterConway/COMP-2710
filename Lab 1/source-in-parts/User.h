// Program 1:		The User object of the meeting room application
// File:			User.h
// Description:		Class definition of the User class
#include <iostream>
#include <string>
using namespace std;

#ifndef User_H
#define User_H
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
#endif