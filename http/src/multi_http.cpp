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

int main()
{
    Param param1("key_is", "value_lol");
    Param param2("key_is", "value_lol");
    Param v[] = {param1, param2};

    std::cout << query("https://a", v, sizeof(v)/sizeof(Param)) << std::endl;
    return 0;
}