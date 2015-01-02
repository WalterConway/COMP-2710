#include <string>
#include <iostream>
#include <cctype>
#include "MessageSystem.h"
using namespace std;

#ifndef MENU_H
#define MENU_H
class Menu
{
private:
public:
	Menu();
	~Menu();
	void DisplayMenu();
	MessageSystem MessagingSystem;
	bool isValid(string input);

};
#endif