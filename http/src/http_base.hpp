#include <iostream>
#include "../../socket/client.hpp"

/*
A http function to make a raw request or return request string
*/
std::string request(std::string method, std::string host, int port, std::string query, bool https = false ,std::string headers = "\r\n", bool ReturnString = false)
{
    std::string protocol = "HTTP";
    
    if(https){
        protocol = "HTTPS";
        port = 443;
    }
    Client c(host, port, 2048);
    std::string request = method + " " + query +  " " + protocol + "/1.1\r\nHost: " + host + "\r\nConnection: Close" + headers + "\r\n";
    // if you want the string and send it later
    if(ReturnString){ return request; }
    // else make the request
    c.send(request);
    return c.recv(true);
}