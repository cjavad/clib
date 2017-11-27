#include <string>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <map>

#include "Base64.hpp"

class Async {
    private:
        void *A_tag;

        struct sockaddr_in A_server;
        std::string A_address;
        int A_port;
        int A_socket;
        bool A_connected;
        bool A_threadStopped;

        int A_packetSize;

        pthread_t A_thread;
        std::map<std::string, void (*)(Async*, std::vector<std::string>)> A_messageListenerMap;
        void (*A_disconnectListener) (Async*);

        void receiveThread();
        static void* staticReceiveThread(void* p){
            Async *client = (Async*) p;
            client->receiveThread();
        }
        
        int receive(std::string &message);
        bool send(std::string message);

    public:
        Async();
        Async(std::string address, int port);
        Async(int socket);

        int getSocket();
        void* getTag();

        bool connect();
        void disconnect();
        bool send(std::string key, std::vector<std::string> messages);
        void addListener(std::string key, void (*messageListener) (Async*, std::vector<std::string>));
        void setDisconnectListener(void (*disconnectListener) (Async*));
        void setTag(void *tag);
};

Async::Async(){}

Async::Async(std::string address, int port){
    A_address = address;
    A_port = port;

    A_server.sin_addr.s_addr = inet_addr(address.c_str());
    A_server.sin_family = AF_INET;
    A_server.sin_port = htons(port);

    A_tag = NULL;
    A_disconnectListener = NULL;
    A_connected = false;
    A_threadStopped = false;
    A_packetSize = 4096;
}

Async::Async(int socket){
    A_socket = socket;
    A_tag = NULL;
    A_disconnectListener = NULL;
    A_connected = true;
    A_threadStopped = false;
    A_packetSize = 4096;
    pthread_create(&A_thread, NULL, &staticReceiveThread, this);
}

int Async::getSocket(){
    return A_socket;
}

bool Async::connect(){
    A_socket = socket(AF_INET , SOCK_STREAM , 0);
    if(A_socket == -1)
    {
        return false;
    }

    if(::connect(A_socket, (struct sockaddr *)&A_server, sizeof(A_server)) < 0)
    {
        return false;
    }

    A_connected = true;
    pthread_create(&A_thread, NULL, &staticReceiveThread, this);

    return true;
}

void Async::disconnect(){
    close(A_socket);
    A_connected = false;
    A_threadStopped = true;
}

bool Async::send(std::string message){
    uint32_t length = htonl(message.size());
    if(::send(A_socket, &length, sizeof(length), 0) < 0){
        return false;
    }
    if(::send(A_socket, message.c_str(), message.size(), 0) < 0){
        return false;
    }
    return true;
}

bool Async::send(std::string key, std::vector<std::string> messages){
    if(send(key)){
        return send(vectorToString(messages));
    }
    return false;
}

int Async::receive(std::string &message){
    uint32_t length;
    int code;

    code = ::recv(A_socket, &length, sizeof(length), 0);
    if(code!=-1 && code!=0){
        length = ntohl(length);
        char server_reply[length];
        message = "";

        for(int i=0 ; i<length/A_packetSize ; i++){
            code = ::recv(A_socket, server_reply, A_packetSize, 0);
            if(code!=-1 && code!=0){
                message += std::string(server_reply, A_packetSize);
            }
            else{
                return code;
            }
        }
        if(length%A_packetSize!=0){
            char server_reply_rest[length%A_packetSize];
            code = ::recv(A_socket, server_reply_rest, length%A_packetSize, 0);
            if(code!=-1 && code!=0){
                message += std::string(server_reply_rest, length%A_packetSize);
            }
        }
    }
    return code;
}

void Async::addListener(std::string key, void (*messageListener) (Async*, std::vector<std::string>)){
    A_messageListenerMap[key] = messageListener;
}

void Async::setDisconnectListener(void (*disconnectListener) (Async*)){
    A_disconnectListener = disconnectListener;
}

void Async::setTag(void *tag){
    A_tag = tag;
}

void* Async::getTag(){
    return A_tag;
}

void Async::receiveThread(){
    std::string key, message;
    int code1, code2;
    while (!A_threadStopped) {
        code1 = receive(key);
        code2 = receive(message);
        if(code1==0 || code2==0){
            disconnect();
            if(A_disconnectListener!=NULL){
                (*A_disconnectListener)(this);
            }
        }
        else if(code1!=-1 && code2!=-1){
            if(A_messageListenerMap[key]!=NULL){
                (*A_messageListenerMap[key])(this, stringToVector(message));
            }
        }
    }
}
