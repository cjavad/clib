#include <iostream>

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