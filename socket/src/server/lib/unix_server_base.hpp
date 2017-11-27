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