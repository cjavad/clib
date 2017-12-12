#include <iostream>
#include <vector>
#include "http_base.hpp"
#include "param.hpp"
#include "../../socket/client.hpp"

class HTTP {
        public:
            static std::string get(std::string url, std::string query_s);
            static std::string post(std::string url, std::string query_s);
};

std::string HTTP::get(std::string url){
    std::vector<std::string> uri = split_url(url);
    if(uri[0] == ("https" || "HTTPS")){
        int port = 443;
        bool https = true;
    } else {
        int port = 80;
        bool https = false;
    }
    return request("GET", uri[1], port, uri[2], https);
}

std::string HTTP::post(std::string url){
        std::vector<std::string> uri = split_url(url);
    if(uri[0] == ("https" || "HTTPS")){
        int port = 443;
        bool https = true;
    } else {
        int port = 80;
        bool https = false;
    }
    return request("POST", uri[1], port, uri[2], https);
}
