#include "../fs.hpp"
#include <vector>
#include <iostream>

int main(){
    open a("text.txt", "r+");
    a.write("HALLO");
    //std::cout << a.read() << std::endl;
    std::vector<std::string> out = a.readlines();

    for(int i = 0; i < (int)out.size(); i++) {
        std::cout << out[i] << std::endl; 
    }
    std::cout << out.size() << std::endl;
    a.close();
}