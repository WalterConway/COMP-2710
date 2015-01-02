#include "GameSystem.h"
#include <iostream>
#include <cctype>
using namespace std;

#ifndef MENU_H
#define MENU_H
class Menu
{
private:
	GameSystem MazeSystem;
public:
	Menu();
	~Menu();
	bool isValid(string input);
	void displayMenu();
};
#endif