#include <iostream>
#include <vector>
#include "../src/string.hpp"
/*
for params
*/
int main(){
    String a("https://example.com/longer/search?q=this is not google");
    std::vector<std::string> v = a.split("/");
    std::string proc = String(v[0]).split(":")[0];
    std::string base_url = v[2];
    std::cout << proc << " " << base_url << std::endl;
    std::string params = "";
    for (size_t i = 0; i < v.size() - 3; i++)
    {
        params += "/" + v[3 + i];
    }
    std::cout << params << std::endl;
}