#include "lib/unix_client_base.hpp"

Client::Client(std::string host, int port, int buffer_size){
	/*
	Socket varibles
	*/
    struct hostent *hp;
	struct sockaddr_in addr;
    //set socket an on
	int on = 1, sock;

	/*
	Get host ip
	*/
	if((hp = gethostbyname(host.c_str())) == NULL){
		herror("Error trying to get hostname");
		exit(1);
	}
	bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));

	/*
	error creating socket
	*/
	if(sock == -1){
		perror("error creating socket");
		exit(1);
	}

	/*
	Try to connect else give error
	*/
	if(connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1){
		perror("Error while trying to connect");
		exit(1);

	}
    /*
	Set sockfd to sock
	and set buffer size
	*/
	BUFFER_SIZE = buffer_size;
	sockfd = sock;
}

void Client::send(std::string data){
	write(sockfd, data.c_str(), strlen(data.c_str()));
}

std::string Client::recv(bool isToClose = false, int buffer_size = 1024){
	/*
	Varibles.
	out is the returned value. STRING
	buffers if the buffer size. INT
	buffer is the buffer for data recv(). CHAR*
	*/
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


void Client::destroy(){
	close(sockfd);
}
