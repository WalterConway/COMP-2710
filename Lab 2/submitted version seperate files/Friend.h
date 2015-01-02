#include <string>
using namespace std;

#ifndef FRIEND_H
#define FRIEND_H
class Friend
{
private:
	string name;
public:
	~Friend();
	Friend();
	Friend(string userName);
	string getName();
	void setName(string userName);
};
#endif