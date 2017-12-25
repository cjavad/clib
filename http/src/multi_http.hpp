#include <iostream>
#include <vector>
#include "http_base.hpp"
#include "param.hpp"
#include "../../socket/client.hpp"

class HTTP {
        public:
            static std::string get(std::string url);
            static std::string post(std::string url);
};

std::string HTTP::get(std::string url){
    std::vector<std::string> uri = split_url(url);
    int port;
    bool https;
    if(uri[0] == "https"){
        port = 443;
        https = true;
    } else {
        port = 80;
        https = false;
    }
    return request("GET", uri[1], port, uri[2], https);
}

std::string HTTP::post(std::string url){
    std::vector<std::string> uri = split_url(url);
    int port;
    bool https;

    if(uri[0] == "https" ){
        port = 443;
        https = true;
    } else {
        port = 80;
        https = false;
    }
    return request("POST", uri[1], port, uri[2], https);
}
