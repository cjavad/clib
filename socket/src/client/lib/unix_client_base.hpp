/*
include all nesesary libaries for this to work on LINUX/MAC 
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

class Client {
    int sockfd, BUFFER_SIZE;

    public:
		Client(std::string host, int port, int buffer_size);
		std::string recv(bool isToClose, int buffer_size);
		void send(std::string data);
		void destroy();
};