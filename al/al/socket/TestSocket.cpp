#include "../Test.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<winsock2.h>
#include<iostream>
using namespace std;

#pragma comment(lib, "ws2_32.lib")


//主机字节序转换到网络字节序
int mynet_hton(int value)
{
	int returnvalue = 0;
	int byte1 = (value & 0xFF);
	int byte2 = (value & 0xFF00) >> 8;
	int byte3 = (value & 0xFF0000) >> 16;
	int byte4 = (value & 0xFF000000) >> 24;

	returnvalue |= byte1 << 24;
	returnvalue |= byte2 << 16;
	returnvalue |= byte3 << 8;
	returnvalue |= byte4;

	return returnvalue;
}

//网络字节序转换为主机
int mynet_ntoh(int value)
{
	int returnvalue = 0;
	int byte1 = (value & 0xFF);
	int byte2 = (value & 0xFF00) >> 8;
	int byte3 = (value & 0xFF0000) >> 16;
	int byte4 = (value & 0xFF000000) >> 24;

	returnvalue |= byte1 << 24;
	returnvalue |= byte2 << 16;
	returnvalue |= byte3 << 8;
	returnvalue |= byte4;

	return returnvalue;
}

void  TestSocketAddr()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return;
	}


	char ip1[] = "192.168.0.74";
	char ip2[] = "211.100.21.179";
	struct in_addr addr1, addr2;
	long l1, l2;
	l1 = inet_addr(ip1);   //将字符串形式的IP地址 -> 网络字节顺序  的整型值
	l2 = inet_addr(ip2);

	int intip1 = 0;
	intip1 |= 192;
	intip1 |= 168 << 8;
	intip1 |= 0 << 16;
	intip1 |= 74 << 24;

	int test1 = mynet_hton(intip1);
	test1 = mynet_hton(test1);
	int intip2 = 0;
	intip2 |= 179;
	intip2 |= 21 << 8;
	intip2 |= 100 << 16;
	intip2 |= 211 << 24;


	printf("IP1: %s\n IP2: %s\n", ip1, ip2);
	printf("Addr1: %ld\n Addr2: %ld\n", l1, l2);

	memcpy(&addr1, &l1, 4); //复制4个字节大小  
	memcpy(&addr2, &l2, 4);
	printf("%s <--> %s\n", inet_ntoa(addr1), inet_ntoa(addr2)); //注意：printf函数自右向左求值、覆盖  
	printf("%s\n", inet_ntoa(addr1)); //网络字节顺序的整型值 ->字符串形式的IP地址  
	printf("%s\n", inet_ntoa(addr2));



	//0x00000001
	int i = 0x04030201;
	if (i >> 24)
	{
		int i = 0;
		i++;
	}

	//getchar();
}


class TESTSOCKET
{
public:
	TESTSOCKET()
	{
		Register();
	}


	void Register()
	{
		FuncMain::Instance()->AddMethod(TestSocketAddr);
	}
};

static TESTSOCKET a;