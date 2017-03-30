#pragma once
#ifndef __RoomList__
#define __RoomList__
#include "TemplateSingleton.h"
#include "Room.h"
#include <string>
#include <unordered_map>
#include <iostream>

#define ROOMLIST RoomList::RoomList::GetInstance()
using std::string;
using std::unordered_map;

namespace RoomList
{
	class RoomList : public TemplateSingleton<RoomList>
	{
	private:
		unordered_map<int, Room::Room> roomList;
		int room_index = 0;
	public:
		bool addRoom(string title);
		void deleteRoom(int room_id);
		bool findRoom(int room_id);
		Room::Room getRoom(int room_id);
		void printRoom();
		json getJson();
		unordered_map<int, Room::Room> getRoomList();
	};
}
#endif // __Authentication__