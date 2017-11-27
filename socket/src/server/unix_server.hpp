/*
include all nesesary libaries for this to work on LINUX/MAC 
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    private:
        int S_port;
        int S_socket;
        struct sockaddr_in S_server;

    public:
        Server(int port);
        bool start();
        int accept();
};

Server::Server(int port){
    /*
    Socket Struct and vars
    */
    S_port = port;
    S_server.sin_family = AF_INET;
    S_server.sin_addr.s_addr = INADDR_ANY;
    S_server.sin_port = htons(port);
}



bool Server::start()
{
    S_socket = socket(AF_INET , SOCK_STREAM , 0);
    if(S_socket!=-1){
        if(bind(S_socket,(struct sockaddr *)&S_server , sizeof(S_server)) >= 0){
            listen(S_socket, 3);
            return true;
    	}
    }
    return false;
}

int Server::accept(){
    int c = sizeof(struct sockaddr_in);
    struct sockaddr_in client;

	int client_sock = ::accept(S_socket, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0){
        return -1;
	}
    return client_sock;
}

