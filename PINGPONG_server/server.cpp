//#define _WINSOCK_DEPRECATED_NO_WARNINGS
//
//#include <string>
//#include "stdio.h"
//#include "json.hpp"
//
//using json = nlohmann::json;
//#include "winsock2.h"
//#pragma comment(lib, "ws2_32.lib")
//
//#define DESIRED_WINSOCK_VERSION        0x0202
//#define MINIMUM_WINSOCK_VERSION        0x0001
//#define MAXBUF 512
//#define DB_HOST "127.0.0.1"
//#define DB_USER "root"
//#define DB_PASS "9045591jkh"
//#define DB_NAME "pingpong"
//
//#include <mysql.h>
//#pragma comment(lib, "libmysql.lib")

//int main()
//{
//	MYSQL *connection = NULL, conn;
//	MYSQL_RES *sql_result;
//	MYSQL_ROW sql_row;
//	int query_state;
//
//	mysql_init(&conn);
//
//	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);
//
//	if (connection == NULL)
//	{
//		std::cout << "Mysql connection error : " << mysql_error(&conn) << std::endl;
//		exit(1);
//	}
//
//
//
//
//	SOCKET m_client_sock, m_listen_sock; // ���� ��ũ��Ʈ ����
//	WSADATA wsadata;
//	struct sockaddr_in client_addr, server_addr;
//
//	// Ŭ���̾�Ʈ�� ������ ���ڿ�
//	char buffer[MAXBUF] = "nonregister!";
//	std::string message = "non-register";
//	int clen;
//	int i = 0;
//
//	// ������ �ʱ�ȭ
//	if (!WSAStartup(DESIRED_WINSOCK_VERSION, &wsadata)) {
//		if (wsadata.wVersion < MINIMUM_WINSOCK_VERSION) {
//			WSACleanup();
//			exit(1);
//		}
//	}
//
//	// ���� ���� ����
//	m_listen_sock = socket(AF_INET, SOCK_STREAM, 0);
//	if (m_listen_sock == INVALID_SOCKET) {
//		printf("socket error : ");
//		WSACleanup();
//		exit(1);
//	}
//
//	clen = sizeof(server_addr);
//
//	// �ּ� ����ü�� �ּ� ����
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = inet_addr("10.156.145.184");
//	server_addr.sin_port = htons(9999); // ����� ��Ʈ��ȣ
//
//										// bind �Լ��� ����Ͽ� ���� ������ �ּ� ����
//	if (bind(m_listen_sock, (LPSOCKADDR)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
//		printf("bind error : ");
//		WSACleanup();
//		exit(1);
//	}
//
//	// ������ ������ �ּҷ� Ŭ���̾�Ʈ ������ ��ٸ�
//	if (listen(m_listen_sock, 1) != 0) {
//		printf("listen error : ");
//		exit(1);
//	}
//
//	while (1) {
//		// Ŭ���̾�Ʈ�� �����ϸ� ������ ����ϰ� Ŭ���̾�Ʈ ������ ������
//		m_client_sock = accept(m_listen_sock, (LPSOCKADDR)&client_addr, &clen);
//		if (m_client_sock != INVALID_SOCKET) {
//			printf("=== Connect Successfully ===");
//
//
//
//			char bufferToServer[MAXBUF] = { 0, };
//			recv(m_client_sock, bufferToServer, MAXBUF, 0);
//
//			printf("\nrecv : %s\n\n", bufferToServer);
//
//			json js = json::parse(bufferToServer);
//
//			printf("json:: \n");
//			std::cout << js.dump(4) << std::endl;
//			if (js["type"] == "register")
//			{
//				message = "success";
//
//				char query[256];
//
//				std::string id = js["id"];
//				std::string username = js["username"];
//				std::string password = js["password"];
//				//sprintf(query, "insert into Account values ( '" + id.c_str() + "', '" + username.c_str() + "', '" + password.c_str() + "')";
//				sprintf_s(query, "insert into Account values ('%s', '%s', '%s')", id.c_str(), username.c_str(), password.c_str());
//				std::cout << query << std::endl;
//				query_state = mysql_query(&conn, query);
//				if (query_state != 0)
//				{
//					std::cout << mysql_error(&conn) << std::endl;
//					exit(1);
//				}
//			}
//
//			strcpy_s(buffer, message.c_str());
//
//			// Ŭ���̾�Ʈ�� buf�� �ִ� ���ڿ� ����
//			if (send(m_client_sock, buffer, MAXBUF, 0) <= 0)
//				printf("send error : ");
//
//			// Ŭ���̾�Ʈ ������ ����
//			closesocket(m_client_sock);
//			mysql_close(&conn);
//		}
//	}
//	return 0;
//}