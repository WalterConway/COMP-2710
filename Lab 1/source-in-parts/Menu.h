// Program 1:		Menu object of the meeting room application.
// File:			Menu.h
// Description:		Class definition of the Menu class.
#include <iostream>
#include <sstream>
#include "System.h"
using namespace std;

#ifndef Menu_H
#define Menu_H
class Menu
{
 private:
   int selection;
   System system;
   string input; 
 
 public:
   Menu();
   ~Menu();   
   void menuPrompt();
   void quit();
   void switchRoom();
   void displayAllMessages();
   void displayNewMessages();
   void createRoom();
   void createUser();
   void connectToRoom();
   void sendAMessage();
   void switchUser();
   bool isValid(string input); 
 
};
#endif