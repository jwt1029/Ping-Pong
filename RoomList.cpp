#include "RoomList.h"

bool RoomList::RoomList::addRoom(string title)
{
	room_index++;
	int room_id = room_index;
	Room::Room room(room_id, title);
	roomList[room_id] = room;
	std::cout << "room id: " << room_id << "created!" << std::endl;
	return true;
}

void RoomList::RoomList::deleteRoom(int room_id)
{
	unordered_map<int, Room::Room>::iterator it;
	it = roomList.find(room_id);
	roomList.erase(it);
	std::cout << "Room:  " << room_id << "Deleted from roomList" << std::endl;
}

bool RoomList::RoomList::findRoom(int room_id)
{
	if (!(roomList.find(room_id) == roomList.end())) {
		return true;
	}
	return false;
}

Room::Room RoomList::RoomList::getRoom(int room_id)
{
	return roomList[room_id];
}

void RoomList::RoomList::printRoom()
{
	for (auto i = roomList.begin(); i != roomList.end(); i++)
	{
		std::cout << i->first << std::endl;
	}
}

json RoomList::RoomList::getJson()
{
	json js_roomList;
	for (auto i = roomList.begin(); i != roomList.end(); i++)
	{
		Room::Room room = getRoom(i->first);
		json js_room = room.getJson();
		js_roomList.push_back(js_room);
	}
	return js_roomList;
}

unordered_map<int, Room::Room> RoomList::RoomList::getRoomList()
{

	return unordered_map<int, Room::Room>();
}
