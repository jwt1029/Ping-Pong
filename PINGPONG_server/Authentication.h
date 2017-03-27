#pragma once
#ifndef __Authentication__
#define __Authentication__
#include <winsock.h>
#include <iostream>
#include <string>
#include <mysql.h>
#include "TemplateSingleton.h"


#define AUTHENTICATION Authentication::Authentication::GetInstance()

using std::string;
namespace Authentication
{
	class Authentication : public TemplateSingleton<Authentication>
	{
	private:
		char query[256];
		string id;
		string password;
		string username;
		MYSQL_RES *res_set;
		MYSQL_ROW row;

	public:
		int login(string id, string password);
		int isLogined(string id);
		int register_user(string id, string password, string username);
	};
}
#endif // __Authentication__