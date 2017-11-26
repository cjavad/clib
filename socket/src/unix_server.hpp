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

class Server {
    int sockfd, sock, BUFFER_SIZE;

    public:
		Server(std::string host, int port, int buffer_size);
		std::string recv(bool isToClose, int buffer_size);
		void send(std::string data);
		void stop();
};

Server::Server(std::string host, int port, int buffer_size){
    //incomming length
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    //if there is any errors perror it
    if (sock < 0) {
        perror("ERROR opening socket");
        exit(0);
    }
    //create struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = port;

    /*
    try to bind. if any error ocours exit()
    */

    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(0);
    }

    //listen
    listen(sock, 5);
    /*
	Set sockfd to accepts new connections
	and set buffer size
	*/
	BUFFER_SIZE = buffer_size;
	sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    //check status
    if (sockfd < 0) {
        perror("ERROR accept");
        exit(0);
    }
}

void Server::send(std::string data){
	write(sockfd, data.c_str(), strlen(data.c_str()));
}

std::string Server::recv(bool isToClose = false, int buffer_size = 0){
    
	std::string out;
	int buffers;
	if(buffer_size == 0){
		buffers = BUFFER_SIZE;
	} else {
		buffers = buffer_size;
	}
	char buffer[buffers];
	if(isToClose){
		while(read(sockfd, buffer, buffers - 1) != 0){
			out += buffer;
			bzero(buffer, buffers);
		} 
	} else {
		read(sockfd, buffer, buffers - 1);
		out = buffer;
	}
	return out;
}


void Server::stop(){
	close(sockfd);
    close(sock);
}