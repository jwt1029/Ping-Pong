#pragma once
#ifndef __UserList__
#define __UserList__
#include "TemplateSingleton.h"
#include <string>
#include <unordered_map>
#include <iostream>

#define USERLIST UserList::UserList::GetInstance()
using std::string;
using std::unordered_map;

namespace UserList
{
	class UserList : public TemplateSingleton<UserList>
	{
	private:
		typedef struct User {
			string id;
			string username;
			bool isReady;
			int locatedRoom;
			double barPosition;
		};
		unordered_map<string, User> userList;
		unordered_map<string, User>::iterator it;
	public:
		void addUser(string id, string username);
		void setReady(string id, bool isReady);
		bool getReady(string id);
		void setBarPosition(string id, double barPosition);
		int getLocatedRoom(string id);
		void setlocatedRoom(string id, int room_id);
		void deleteUser(string id);
		void exitGame(string id);
		void exitRoom(string id);
		bool findUser(string id);
	};
}
#endif // __Authentication__