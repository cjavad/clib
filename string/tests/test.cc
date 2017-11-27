#include <iostream>
#include <vector>
#include "../src/string.hpp"

int main(){
    std::string b = "Hello World LIFE";
    Basic_List l;
    l.append_s(b);
    String a(b);
    std::vector<std::string> v = a.split(" ");
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }

    String d("-");
    std::cout << d.join(v) << " " << v.size() << std::endl;
    std::cout << a.upper() << " " << a.lower() << std::endl;
    std::cout << a.swapcase() << l.get_s(0) << std::endl;
    return 0;
}
