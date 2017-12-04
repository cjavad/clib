#include <iostream>
#include "../../socket/client.hpp"

class HTTP {
        public:
         static std::string get(std::string url, std::string query_s);
         static std::string post(std::string url, std::string query_s);
};

std::string HTTP::get(std::string url, std::string query_s){
    Client c(url, 80, 2048);
    std::string request = "GET " + query_s + " HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\nUser-Agent: Mozilla/5.0 ()\r\n\r\n";
    std::cout << request << std::endl;
    c.send(request);
    return c.recv(true);
}

std::string HTTP::post(std::string url, std::string query_s){
    Client c(url, 80, 2048);
    std::string request = "POST " + query_s + " HTTP/1.1\r\nHost: " + url + "\r\nConnection: close\r\nUser-Agent: Mozilla/5.0 ()\r\n\r\n";
    std::cout << request << std::endl;
    c.send(request);
    return c.recv(true);
}
