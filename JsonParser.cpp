#include "JsonParser.h"

namespace JsonParser {
	JsonParser::JsonParser()
	{
	}
	JsonParser::~JsonParser()
	{
	}
	JsonParser::JsonParser(const char *buf)
	{
		//this->parse(buf);
	}

	json JsonParser::parse(const char *buf)
	{
		js.clear();
		js = json::parse(buf);

		process();
		return js;
	}

	void JsonParser::process()
	{
		if (this->getType() == "register")
		{
			js["status"] = AUTHENTICATION->register_user(js["id"], js["password"], js["username"]);
		}
		else if (this->getType() == "login")
		{
			js["status"] = AUTHENTICATION->login(js["id"], js["password"]);
		}
		else if (this->getType() == "createRoom")
		{
			js["status"] = GAMEMANAGER->createRoom(js["title"]);
		}
		else if (this->getType() == "getRoomList")
		{
			js["roomList"] = GAMEMANAGER->getRoomList();
			js["status"] = 200;
		}
		else if (this->getType() == "enterRoom")
		{
			js["status"] = GAMEMANAGER->enterRoom(js["room_id"], js["id"]);
		}
		else if (this->getType() == "endGame")
		{
			js["status"] = GAMEMANAGER->endGame(js["room_id"], js["id"]);
		}
		else if (this->getType() == "leaveRoom")
		{
			js["status"] = GAMEMANAGER->leaveRoom(js["id"], js["room_id"]);
		}
		else if (this->getType() == "ready")
		{
			js["status"] = GAMEMANAGER->ready(js["room_id"], js["id"]);
		}
		else if (this->getType() == "logout")
		{
			js["status"] = GAMEMANAGER->logout(js["id"]);
		}
		else {
			std::cout << "invalid request type" << std::endl;
			js["status"] = 0;
		}
	}

	json JsonParser::getType()
	{
		return js["type"];
	}
}
