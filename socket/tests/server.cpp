#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <stdio.h>

#include "../src/unix_server.hpp"
#include "../lib/async_client.hpp"

using namespace std;

std::string getUid(){
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string uid="";
    int length = characters.size();
    for(int i=0 ; i<10 ; i++){
        uid += characters[rand() % length];
    }
    return uid;
}



std::vector<Async*> clientsVector;

void forward(string key, vector<string> messages, Async *exception){
	std::string *_uid = (std::string*) exception->getTag();
	for(auto x : clientsVector){
		std::string *uid = (std::string*) x->getTag();
		if((*uid)!=(*_uid)){
			x->send(key, messages);
		}
	}
}

void onMessage(Async *socket, vector<string> messages){
	forward("message", messages, socket);
}

void onDisconnect(Async *socket){
	cout << "client disconnected !" << endl;
	forward("message", {"Client disconnected"}, socket);
	std::string *_uid = (std::string*) socket->getTag();
	for(int i=0 ; i<clientsVector.size() ; i++){
		std::string *uid = (std::string*) clientsVector[i]->getTag();
		if((*uid)==(*_uid)){
			clientsVector.erase(clientsVector.begin() + i);
		}
	}
	delete socket;
}

void freeMemory(){
	for(auto x : clientsVector){
		delete (std::string*) x->getTag();
		delete x;
	}
}

int main(int argc , char *argv[]){
	srand(time(NULL));

	Server server(8888);
	if(server.start()){
		cout << "server started. Listening on port 8888..." << endl;
		while (1) {
			int sock = server.accept();
			if(sock!=-1){
				cout << "client connected !" << endl;
				Async *client = new Async(sock);
				client->addListener("message", onMessage);
				client->setDisconnectListener(onDisconnect);
				client->setTag(new std::string(getUid()));
				clientsVector.push_back(client);
			}
		}
	}
	else{
		cout << "Could not create server" << endl;
	}

	freeMemory();
	return 0;
}