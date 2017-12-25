#include "../fs.hpp"

int main(){
    open a("text.txt", "r");
    std::cout << a.readline(0) << std::endl;
    a.close();
}