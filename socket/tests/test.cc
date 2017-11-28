#include <iostream>
#include "../client.hpp" //automaticly chooses either windows or linux/macos

int main(){
    std::string host = "google.com";
    int port = 80;
    int buffer_size = 1024;

    Client c(host, port, buffer_size);

    c.send("GET /search?q=cpp HTTP/1.1");
    //the first arg is if you want to read the entire stream or just the amount you have specified
    std::cout << c.recv() << std::endl;
}