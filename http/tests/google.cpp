#include <iostream>
#include "../src/multi_http.hpp"

int main(){
    std::cout << HTTP::get("useragentapi.com", "/") << std::endl;
}