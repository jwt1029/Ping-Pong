#include "connection.h"
#include <iostream>
#include <string.h>
#define DB_PORT 3306
#define DB_HOST "127.0.0.1"
#define DB_NAME "pingpong"
#define DB_UID "root"
#define DB_PASS "9045591jkh"

using std::string;

Connection::Connection()
{
	if (!IsConnected())
	{
		Connect(DB_HOST, DB_NAME, DB_UID, DB_PASS);
	}
}

Connection::~Connection()
{
}

void Connection::Close() {
	if (!IsConnected()) {
		return;
	}
	mysql_close(connection);
	connection = (MYSQL *)NULL;
}

void Connection::Connect(char *host, char *db, char *uid, char *pw) {
	if (IsConnected()) {
		throw "Connection has already been established.";
	}
	mysql_init(&conn);
	connection = mysql_real_connect(&conn, host, uid, pw, db, DB_PORT, (char *)NULL, 0);
	std::cout << "DB Connected" << std::endl;
	if (!IsConnected()) {
		throw GetError();
	}
}

bool Connection::excute_Query(char *query)
{
	if (!IsConnected())
	{
		std::cout << "not connected." << std::endl;
		return false;
	}
	query_state = mysql_query(connection, query);
	if (getQuery_State() != 0)
	{
		std::cout << "query_state: "<<getQuery_State() << std::endl;
		std::cout << GetError() << std::endl;
		return false;
	}
	std::cout <<"½ÇÇàµÈ Äõ¸®: "<< query << std::endl;
	res_set = mysql_use_result(connection);

	return true;
}

const char *Connection::GetError() {
	if (IsConnected())
	{
		return mysql_error(connection);
	}
	return mysql_error(&conn);
}

int Connection::IsConnected() {
	return !(!connection);
}

int Connection::getQuery_State() {
	return query_state;
}

MYSQL_RES *Connection::getResult()
{
	return res_set;
}
