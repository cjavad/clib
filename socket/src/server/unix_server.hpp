/* Copyright (c) 2017 Javad Shafique */
#include "lib/unix_server_base.hpp"


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

