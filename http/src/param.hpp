#include <iostream>
#include <vector>
#include "../../string/string.hpp"

class Param {
    public:
        std::string key;
        std::string value;
        Param(std::string key_c, std::string value_c);

};

Param::Param(std::string key_c, std::string value_c){
            key = key_c;
            value = value_c;
}


std::string query(std::string base_url, Param vec[], int len)
{
    base_url += "?place_holder=true";
    for (size_t i = 0; i < len; i++)
    {
        std::string key = vec[i].key;
        std::string value = vec[i].value;
        base_url += "&" + key + "=" + value;
    }   
    return base_url;
}

std::vector<std::string> split_url(String url){
    std::vector<std::string> v = url.split("/");
    std::string protocol = String(v[0]).split(":")[0];
    //params in a string for query_s
    std::string params = "";
    for (size_t i = 0; i < v.size() - 3; i++)
    {
        params += "/" + v[3 + i];
    }
    std::vector<std::string> o;
    //{protocol, v[2], params}
    o.push_back(protocol);
    o.push_back(v[2]);
    o.push_back(params);
    return o;
}