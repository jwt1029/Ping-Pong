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
//	SOCKET m_client_sock, m_listen_sock; // 소켓 디스크립트 정의
//	WSADATA wsadata;
//	struct sockaddr_in client_addr, server_addr;
//
//	// 클라이언트에 보내줄 문자열
//	char buffer[MAXBUF] = "nonregister!";
//	std::string message = "non-register";
//	int clen;
//	int i = 0;
//
//	// 소켓을 초기화
//	if (!WSAStartup(DESIRED_WINSOCK_VERSION, &wsadata)) {
//		if (wsadata.wVersion < MINIMUM_WINSOCK_VERSION) {
//			WSACleanup();
//			exit(1);
//		}
//	}
//
//	// 서버 소켓 생성
//	m_listen_sock = socket(AF_INET, SOCK_STREAM, 0);
//	if (m_listen_sock == INVALID_SOCKET) {
//		printf("socket error : ");
//		WSACleanup();
//		exit(1);
//	}
//
//	clen = sizeof(server_addr);
//
//	// 주소 구조체에 주소 지정
//	memset(&server_addr, 0, sizeof(server_addr));
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.s_addr = inet_addr("10.156.145.184");
//	server_addr.sin_port = htons(9999); // 사용할 포트번호
//
//										// bind 함수를 사용하여 서버 소켓의 주소 설정
//	if (bind(m_listen_sock, (LPSOCKADDR)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
//		printf("bind error : ");
//		WSACleanup();
//		exit(1);
//	}
//
//	// 위에서 지정한 주소로 클라이언트 접속을 기다림
//	if (listen(m_listen_sock, 1) != 0) {
//		printf("listen error : ");
//		exit(1);
//	}
//
//	while (1) {
//		// 클라이언트가 접속하면 접속을 허용하고 클라이언트 소켓을 생성함
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
//			// 클라이언트로 buf에 있는 문자열 전송
//			if (send(m_client_sock, buffer, MAXBUF, 0) <= 0)
//				printf("send error : ");
//
//			// 클라이언트 소켓을 닫음
//			closesocket(m_client_sock);
//			mysql_close(&conn);
//		}
//	}
//	return 0;
//}