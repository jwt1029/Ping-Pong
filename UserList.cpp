#include "UserList.h"

void UserList::UserList::addUser(string id, string username)
{
	User user;
	user.id = id;
	user.username = username;
	userList.insert(id, user);
}

void UserList::UserList::deleteUser(string id)
{
}

void UserList::UserList::exitGame(string id)
{
}

void UserList::UserList::exitRoom(string id)
{
}

bool UserList::UserList::findUser(string id)
{
	return false;
}
