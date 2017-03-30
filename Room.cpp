#include "Room.h"

Room::Room::Room()
{
	this->room_id = 0;
	this->title = "";
	this->isPlaying = false;
}

Room::Room::Room(int room_id, string title)
{
	Room();
	this->room_id = room_id;
	this->title = title;
}

Room::Room::~Room()
{
}

bool Room::Room::addUser(string id)
{
	if (findUser(id) == false)
	{
		userList.push_back(id);
		return true;
	}
	std::cout << "try to add User: " << id << "to Room: " << room_id << "But target user is already joined this room" << std::endl;
	return false;
}

bool Room::Room::deleteUser(string id)
{
	if (findUser(id) == true)
	{
		userList.remove(id);
		return true;
	}
	std::cout << "try to delete User: " << id << "to Room: " << room_id << "But target user is not joined this room" << std::endl;

	return false;
}

int Room::Room::getNumOfPlayers()
{
	return userList.size();
}

bool Room::Room::findUser(string id)
{
	return (std::find(userList.begin(), userList.end(), id) != userList.end());
}

json Room::Room::getJson()
{
	json js_userlist(userList);
	json js;
	js["room_id"] = room_id;
	js["title"] = title;
	js["isPlaying"] = isPlaying;
	js["userList"] = js_userlist;
	return js;
}

int Room::Room::startGame()
{
	if (isPlaying != true)
	{
		isPlaying = true;
		return 200;
	}
	else {
		std::cout << "Game is already started!" << std::endl;
		return 500;
	}
}
