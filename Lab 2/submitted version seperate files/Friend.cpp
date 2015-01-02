#include "Friend.h"
// Function: default constructor
// Inputs: void
// Outputs: void
// Description: void
Friend::Friend()
{

}

// Function: overloaded 
// Inputs: string user name
// Outputs: void
// Description: initialize a friend object
Friend::Friend(string userName)
{
	name = userName;
}

// Function: deconstructor
// Inputs: void
// Outputs: void
// Description: void
Friend::~Friend()
{

}

// Function: get name
// Inputs: void
// Outputs: string friend name
// Description: return the friend name
string Friend::getName()
{
return name;
}

// Function: set name
// Inputs: string user name
// Outputs: void
// Description: sets the the friend name
void Friend::setName(string userName)
{
	name = userName;
}