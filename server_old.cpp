//
// Created by production on 2017-03-21.
//
#include "stddef.h"
#include <string>
#include "stdio.h"

#include "json.hpp"
#include "Connection.h"
#include "Socket.h"
#include "JsonParser.h"
#include "RoomList.h"

using json = nlohmann::json;
#pragma comment(lib, "ws2_32.lib")




#define SOCKET_ADDR "10.156.145.184"
#define SOCKET_PORT 9999

#include <unordered_map>
using std::unordered_map;

int main()
{
	Socket *socket = new Socket();
	socket->create();
	socket->address_bind(SOCKET_ADDR, SOCKET_PORT);
	socket->listen_start();
	return 0;
}

//1���� ������� ���� Ŭ���̾�Ʈ-����
//2���� JSON ��� & Mysql ����
//3���� �ڵ� �����͸�
//4���� �ڵ� �����͸� ������
//5���� ȸ������ Ŭ���̾�Ʈ ���� ����
//6���� �α��� ���� ���� & Mysql & Socket ���� ����
//7���� �۾�ȯ�� �籸�� ( ȯ�� ������ ���� ���� )