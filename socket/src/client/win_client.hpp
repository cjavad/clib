#include "lib/win_client_base.hpp"

Client::Client(std::string host, int port, int buffer_size = 2048) {
	WSADATA wsa;
	//structs
	struct sockaddr_in server;
	struct addrinfo *res;
	struct in_addr addr;
	//init winsock
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        perror("Failed to start. Error Code");
		return;
    }
	// create socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        perror("Failid to create socket");
		WSACleanup();
		return;
    }
	// Get socket and addr info
	getaddrinfo(host.c_str(), NULL, 0, &res);
	// add adress info
	addr.S_un = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.S_un;
	// add to sockaddr_in
	server.sin_addr.s_addr = inet_addr(inet_ntoa(addr));
    server.sin_port = htons(port);
	server.sin_family = AF_INET;

	// connect to server
	if (connect(sockfd, (SOCKADDR *)&server , sizeof(server)) == SOCKET_ERROR)
    {
		// if it failed to connect
		printf("Failed to connect to socket error: %d\n", WSAGetLastError());
		// close socket
		closesocket(sockfd);
		// and set it to invalid
		sockfd = INVALID_SOCKET;
    }
	// free info from getaddrinfo
	freeaddrinfo(res);
	// check if you succeded
	if(sockfd == INVALID_SOCKET) {
		// use WSAcleanup
		WSACleanup();
		// and return
		return;
	}
	//success if it reached this stage
}

void Client::say(std::string data) {
	if (send(sockfd, data.c_str(), (int)strlen(data.c_str()), 0) == SOCKET_ERROR) {
		printf("Failed to send data: %d\n", WSAGetLastError());
	}
}

std::string Client::hear(bool isToClose = false, int buffer_size = 0) {
	std::string out;
	int iResult;
	int buffers = 1024;
	if (buffer_size == 0) {
		buffers = BUFFER_SIZE;
	}
	else {
		buffers = buffer_size;
	}
	char* buffer = new char[buffers];

	if (isToClose) {
		do {
			iResult = recv(sockfd, buffer, buffers, 0);
			if (iResult > 0) {
				out += buffer;
			}
			else if (iResult == 0) {
				printf("Connection closed\n");
			}
			else {
				printf("recv failed with error: %d\n", WSAGetLastError());
			}

		} while (iResult > 0);
	}
	else {
		iResult = recv(sockfd, buffer, buffers, 0);
		if (iResult > 0) {
			out += buffer;
		}
		else if (iResult == 0) {
			printf("Connection closed\n");
		}
		else {
			printf("recv failed with error: %d\n", WSAGetLastError());
		}
	}
	return out;
}