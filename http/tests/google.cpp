#include <iostream>
#include "../http.hpp"

int main(){
    std::cout << HTTP::get("http://google.com/?q=cpp") << std::endl;
}