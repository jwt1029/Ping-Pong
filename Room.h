#pragma once
#ifndef __Room__
#define __Room__
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include "json.hpp"
using json = nlohmann::json;

using std::string;
using std::list;

namespace Room
{
	class Room
	{
	private:
		int room_id;
		list<string> userList;
		string title;
		bool isPlaying;
	public:
		Room();
		Room(int room_id, string title);
		~Room();
		bool addUser(string id);
		bool deleteUser(string id);
		int getNumOfPlayers();
		bool findUser(string id);
		json getJson();
		int getRoom_id() { return room_id; };
		void setRoom_id(int room_id) { this->room_id = room_id; };
		bool getIsPlaying() { return isPlaying; };
		void setIsPlaying(bool isPlaying) { this->isPlaying = isPlaying; };
		int startGame();
	};
}
#endif // __Room__