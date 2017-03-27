#pragma once
#ifndef __Connection__
#define __Connection__

#include <winsock.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
#include "stddef.h"
#include "TemplateSingleton.h"

#define CONNECTION Connection::GetInstance()

class Connection : public TemplateSingleton<Connection>{
private:
	MYSQL *connection = NULL, conn;
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;
	int query_state;
	MYSQL_RES *res_set;

public:
	Connection();
	~Connection();
	void Close();
	void Connect(char *host, char *db, char *uid, char *pw);
	bool excute_Query(char *query);

	const char *GetError();
	int IsConnected();
	int getQuery_State();
	MYSQL_RES *getResult();
};

#endif // __Connection__