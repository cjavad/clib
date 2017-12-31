#include <iostream>
#include "../http.hpp"

int main(){
    // automatic https detection
    std::cout << HTTP::get("https://google.com/search?q=cpp") << std::endl;
}