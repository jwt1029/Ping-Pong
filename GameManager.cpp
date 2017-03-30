#include "GameManager.h"

json GameManager::GameManager::getRoomList()
{
	json js;
	js = ROOMLIST->getJson();
	return js;
}

int GameManager::GameManager::createRoom(string title)
{
	if (ROOMLIST->addRoom(title) == true)
	{
		return 200;
	}
	return 0;
}

bool GameManager::GameManager::startGame(int room_id, string id)
{
	if (ROOMLIST->getRoom(room_id).getIsPlaying() != true)
	{
		ROOMLIST->getRoom(room_id).setIsPlaying(true);
		USERLIST->setlocatedRoom(id, room_id);
		return true;
	}
	std::cout << "Game is already started!" << std::endl;
	return false;
}

int GameManager::GameManager::ready(int room_id, string id)
{
	if (ROOMLIST->getRoom(room_id).findUser(id) == true && ROOMLIST->getRoom(room_id).getIsPlaying() == false)
	{
		if (USERLIST->getReady(id) == false)
		{
			USERLIST->setReady(id, true);
			if (ROOMLIST->getRoom(room_id).getNumOfPlayers() == 2)
			{
				if (startGame(room_id, id) == true)
				{
					return 201; // game start
				}
			}
			return 202; // game not start, but ready successful

		}
		else {
			USERLIST->setReady(id, false);
			return 203;// try unready successful
		}
	}
	return 0;
}

int GameManager::GameManager::endGame(int room_id, string id)
{
	if (ROOMLIST->getRoom(room_id).getIsPlaying() == true)
	{
		ROOMLIST->getRoom(room_id).setIsPlaying(false);
		USERLIST->setBarPosition(id, 0);
		return 200;
	}
	std::cout << "Rooom: " << room_id << "is not play the game"<<std::endl;
	return 0;
}

int GameManager::GameManager::enterRoom(int room_id, string id)
{
	if (ROOMLIST->getRoom(room_id).getNumOfPlayers() < 2)
	{
		if (ROOMLIST->getRoom(room_id).addUser(id) == true)
		{
			USERLIST->setlocatedRoom(id, room_id);
			return 200;
		}
	}
	return 0;
}

int GameManager::GameManager::leaveRoom(string id, int room_id)
{
	if (ROOMLIST->getRoom(room_id).getIsPlaying() == true)
	{
		endGame(room_id, id);
	}
	if (ROOMLIST->getRoom(room_id).deleteUser(id) == true)
	{
		USERLIST->setlocatedRoom(id, 0);
		return 200;
	}
	return 0;
}

int GameManager::GameManager::logout(string id)
{
	int room_id = USERLIST->getLocatedRoom(id);
	if (room_id != 0)
	{
		if (ROOMLIST->getRoom(room_id).getIsPlaying() == true)
		{
			endGame(room_id, id);
		}
		if (ROOMLIST->getRoom(room_id).deleteUser(id) == true)
		{
			USERLIST->setlocatedRoom(id, 0);
			return 200;
		}
	}
	USERLIST->deleteUser(id);
	return 0;
}
