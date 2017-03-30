#include "Socket.h"

#define MAXBUF 512
#define DESIRED_WINSOCK_VERSION        0x0202
#define MINIMUM_WINSOCK_VERSION        0x0001
#include <iostream>
#include "JsonParser.h"

Socket::Socket()
{
	status = 0;
	initialize();
}

Socket::~Socket()
{
	Close();
}

void Socket::Close()
{
	closesocket(m_client_sock);
}

void Socket::initialize() {
	if (!WSAStartup(DESIRED_WINSOCK_VERSION, &wsadata)) {
		if (wsadata.wVersion < MINIMUM_WINSOCK_VERSION) {
			WSACleanup();
			//exit(1);
		}
	}
}

void Socket::create()
{
	m_listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (m_listen_sock == INVALID_SOCKET) {
		std::cout<<"socket error : "<<std::endl;
		WSACleanup();
		exit(1);
	}
	addrlen = sizeof(server_addr);
	std::cout << "socket Created" << std::endl;
}

void Socket::address_bind(const char *addr, u_short port)
{
	// 주소 구조체에 주소 지정
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(addr);
	server_addr.sin_port = htons(port); // 사용할 포트번호

	if (bind(m_listen_sock, (LPSOCKADDR)&server_addr, addrlen) == SOCKET_ERROR) {
		std::cout << "Socket Bind Error: " << std::endl;
		WSACleanup();
		exit(1);
	}
	std::cout <<"Bind: "<< addr<<":" << port << std::endl;
}

void Socket::listen_start()
{
	if (listen(m_listen_sock, 1) != 0) {
		printf("listen error : ");
		exit(1);
	}
	std::cout << "client listen start" << std::endl;

	while (1) {
		// 클라이언트가 접속하면 접속을 허용하고 클라이언트 소켓을 생성함z
		socket_accept();
		if (isSocketValid()) {
			js.clear();
			char buffer[BUFFER_SIZE] = { 0, };
			
			status = 0;
			recvMessage(buffer, BUFFER_SIZE);
			js = JSONPARSER->parse(buffer);
			sendMessage(js.dump(4).c_str());
		}
	}
}

void Socket::socket_accept()
{
	m_client_sock = accept(m_listen_sock, (LPSOCKADDR)&client_addr, &addrlen);
}

void Socket::sendMessage(const char *buffer)
{
	if (send(m_client_sock, buffer, strlen(buffer), 0) <= 0)
		printf("send error : ");

	std::cout << "Message Send: " << buffer << std::endl;
}

bool Socket::isSocketValid()
{
	if (m_client_sock != INVALID_SOCKET)
	{
		return true;
	}
	return false;
}

// ::abc
void Socket::recvMessage(char buf[], int bufsize)
{
	recv(m_client_sock, buf, bufsize, 0);
	std::cout << "recvMessage: " << buf << std::endl;
}