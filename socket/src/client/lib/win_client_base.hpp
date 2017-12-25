/// Defining _WINSOCKAPI_ so windows.h wont include winsock.h
#define _WINSOCKAPI_ 
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")

class Client {
	SOCKET sockfd;
	int BUFFER_SIZE;

public:
	Client(std::string host, int port, int buffer_size);
	std::string hear(bool isToClose, int buffer_size);
	void say(std::string data);
	void destroy();
};