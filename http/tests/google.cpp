#include <iostream>
#include "../src/multi_http.hpp"

int main(){
    std::cout << HTTP::get("google.com", "/search?q=cpp") << std::endl;
}