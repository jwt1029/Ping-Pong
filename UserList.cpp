#include "UserList.h"

void UserList::UserList::addUser(string id, string username)
{
	User user;
	user.id = id;
	user.username = username;
	user.isReady = false;
	user.locatedRoom = 0;
	user.barPosition = 0;
	

	userList[id] = user;
	//delete &user;
	std::cout << "User:" << id << " Added to userList" << std::endl;
}

void UserList::UserList::setReady(string id, bool isReady)
{
	userList[id].isReady = isReady;
}

bool UserList::UserList::getReady(string id)
{
	return userList[id].isReady;
}

void UserList::UserList::setBarPosition(string id, double barPosition)
{
	userList[id].barPosition = barPosition;
}

int UserList::UserList::getLocatedRoom(string id)
{
	return userList[id].locatedRoom;
}

void UserList::UserList::setlocatedRoom(string id, int room_id)
{
	userList[id].locatedRoom = room_id;
}

void UserList::UserList::deleteUser(string id)
{
	it = userList.find(id);
	userList.erase(it);
	std::cout << "User " << id <<"Deleted from userList"<<std::endl;
}

void UserList::UserList::exitGame(string id)
{
	it = userList.find(id);
	userList[id].barPosition = 0;
	userList[id].isReady = false;
}

void UserList::UserList::exitRoom(string id)
{
	userList[id].barPosition = 0;
	userList[id].isReady = false;
	userList[id].locatedRoom = 0;
}

bool UserList::UserList::findUser(string id)
{
	if (!(userList.find(id) == userList.end())) {
		return true;
	}
	return false;
}
