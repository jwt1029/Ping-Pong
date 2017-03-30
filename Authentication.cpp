#include "Authentication.h"
#include "Connection.h"
#define MYSQL_USERNAME_INDEX 1


int Authentication::Authentication::login(string id, string password)
{
	sprintf_s(query, "select * from Account where id='%s'&&password='%s'", id.c_str(), password.c_str());
	if (CONNECTION->excute_Query(query) == false)
	{
		return 500;
	}
	res_set = CONNECTION->getResult();
	int num_row;
	if (res_set) {
		num_row = mysql_num_rows(res_set);
	} else{
		num_row = 0;
	}
	if (num_row == 1)
	{
			if (isLogined(id) == true)
			{
				std::cout << "Player: " << id << " tried login, But already exist in Game" << std::endl;
				return 500;
			}
			row = mysql_fetch_row(res_set);
			string username = row[MYSQL_USERNAME_INDEX];
			USERLIST->addUser(id, username);
			std::cout << "User: " << id << "(" << username << ")" << "logined!" << std::endl;
			return 200;	
	}
	else {
		std::cout << "Player: " << id << " not found" << std::endl;
		return 500;
	}
	return 500;
}

bool Authentication::Authentication::isLogined(string id)
{
	if (USERLIST->findUser(id))
	{
		return true;
	}
	return false;
}

int Authentication::Authentication::register_user(string id, string password, string username)
{
	sprintf_s(query, "insert into Account values ('%s', '%s', '%s')", id.c_str(), username.c_str(), password.c_str());
	if (CONNECTION->excute_Query(query) == false)
	{
		return 500;
	}
	std::cout << "ID: " << id << " registered!" << std::endl;

	return 200;
}
