#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock.h>
#include "json.hpp"
#ifndef __Socket__
#define __Socket__

#define BUFFER_SIZE 512
using json = nlohmann::json;

class Socket {
private:
	SOCKET m_client_sock, m_listen_sock; // 소켓 디스크립트 정의
	WSADATA wsadata;
	struct sockaddr_in client_addr, server_addr;
	int addrlen;
	int status;
	json js;

public:
	Socket();
	~Socket();
	void Close();
	void initialize();
	void create();
	void address_bind(const char * addr, u_short port);
	void listen_start();
	void socket_accept();
	void sendMessage(const char * buffer);
	bool isSocketValid();
	void recvMessage(char buf[], int bufsize);
};

#endif // __Socket__