#pragma once
#ifndef __GameManager__
#define __GameManager__

#include "json.hpp"
#include "TemplateSingleton.h"
#include "UserList.h"
#include "RoomList.h"
using json = nlohmann::json;

#define GAMEMANAGER GameManager::GameManager::GetInstance()

namespace GameManager
{
	class GameManager : public TemplateSingleton<GameManager> {
	private:
		int status;
	public:
		json getRoomList();
		int createRoom(string title);
		bool startGame(int room_id, string id);
		int ready(int room_id, string id);
		int endGame(int room_id, string id);
		int enterRoom(int room_id, string id);
		int leaveRoom(string id, int room_id);
		int logout(string id);
	};
}

#endif // __Connection__