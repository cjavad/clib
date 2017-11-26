#include <iostream>
#include "../src/unix_server.hpp"

int main(){
    Server s("0.0.0.0", 8080, 1024);
    s.send("HELLO WORLD");
    return 0;
}
