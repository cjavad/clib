#include "../client.hpp"

int main(){
    Client c("localhost", 3434, 1024);
    c.send("hello");
    std::cout << c.recv() << std::endl;
    return 0;
}