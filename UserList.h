#pragma once
#ifndef __UserList__
#define __UserList__
#include "TemplateSingleton.h"
#include <string>
#include <hash_map>

#define USERLIST UserList::UserList::GetInstance()
using std::string;
using stdext::hash_map;

namespace UserList
{
	class UserList : public TemplateSingleton<UserList>
	{
	private:
		typedef struct User {
			string id;
			string username;
			bool isReady;
			bool locatedRoom;
			int barPosition;
		};
		hash_map<string, User> userList;
	public:
		void addUser(string id, string username);
		void deleteUser(string id);
		void exitGame(string id);
		void exitRoom(string id);
		bool findUser(string id);
	};
}
#endif // __Authentication__