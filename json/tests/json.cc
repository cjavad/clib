#include <iostream>
#include "../json.hpp"

int main() {
    std::string js = "{\"KEY\":10}";
    Json json;
    json.Parse(js.c_str());
    std::cout << json["KEY"].GetInt() << std::endl;
    json["NUM"].SetInt(11);
    std::cout << json["NUM"].IsInt() << std::endl;
    return 0;
}