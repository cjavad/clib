#include "../fs.hpp"

int main(){
    open a("text.txt", "r+");
    std::vector<std::string> out = a.readlines();
    for(int i; i < out.size(); i++) {
        std::cout << out[i] << std::endl;
    }
    std::cout << out.size() << std::endl;
    a.close();
}