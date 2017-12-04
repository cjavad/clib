#include <iostream>
#include "../string.hpp"

int main(){
    String a = "HELLO WORLD";
    std::cout << a.to_str() << std::endl;
    return 0;
}