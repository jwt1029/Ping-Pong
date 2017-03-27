#include "JsonParser.h"
#include "Authentication.h"

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

	int JsonParser::parse(const char *buf)
	{
		std::cout << "parse Start" << std::endl;
		std::cout << "parse:" << buf << std::endl;
		js = json::parse(buf);

		process();
		js.clear();
		return status;
	}

	void JsonParser::process()
	{
		if (this->getType() == "register")
		{
			status = AUTHENTICATION->register_user(js["id"], js["password"], js["username"]);
		}
		else if (this->getType() == "login")
		{
			status = AUTHENTICATION->login(js["id"], js["password"]);
		}
		else if (this->getType() == "createRoom")
		{

		}
		else if (this->getType() == "getRoomList")
		{

		}
		else if (this->getType() == "enterRoom")
		{

		} 
		else {
			std::cout << "invalid request type" << std::endl;
			status = 0;
		}
	}

	json JsonParser::getType()
	{
		return js["type"];
	}
}
