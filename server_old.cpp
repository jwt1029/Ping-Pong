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

//1일차 소켓통신 성공 클라이언트-서버
//2일차 JSON 통신 & Mysql 연동
//3일차 코드 리펙터링
//4일차 코드 리펙터링 마무리
//5일차 회원가입 클라이언트 연동 성공
//6일차 로그인 연동 성공 & Mysql & Socket 에러 수정
//7일차 작업환경 재구축 ( 환경 오류로 인한 포맷 )