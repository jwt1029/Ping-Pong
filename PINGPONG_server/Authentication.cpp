#include "Authentication.h"
#include "Connection.h"

int Authentication::Authentication::login(string id, string password)
{
	sprintf_s(query, "select * from Account where id='%s'&&password='%s'", id.c_str(), password.c_str());
	if (CONNECTION->excute_Query(query) == false)
	{
		return 500;
	}
	res_set = CONNECTION->getResult();
	unsigned int numrows = mysql_num_rows(res_set);
	unsigned int i = 0;
	// get the number of the columns
	int num_fields = mysql_num_fields(res_set);
	// Fetch all rows from the result
	while ((row = mysql_fetch_row(res_set)))
	{
		// Print all columns
		for (int i = 0; i < num_fields; i++)
		{
			// Make sure row[i] is valid!
			if (row[i] != NULL)
			{
				std::cout << row[i] << std::endl;
				return 200;
			}
			else
				std::cout << "Account not found" << std::endl;

			// Also, you can use ternary operator here instead of if-else
			// cout << row[i] ? row[i] : "NULL" << endl;
		}
	}

	std::cout << "excute_Query called" << std::endl;
	return 500;
}

int Authentication::Authentication::isLogined(string id)
{
	return 500;
}

int Authentication::Authentication::register_user(string id, string password, string username)
{
	sprintf_s(query, "insert into Account values ('%s', '%s', '%s')", id.c_str(), username.c_str(), password.c_str());
	if (CONNECTION->excute_Query(query)==false)
	{
		return 500;
	}
	std::cout << "ID: " << id << " registered!" << std::endl;

	return 200;
}
