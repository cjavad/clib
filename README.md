# clib
A bunch of easy to use c++ libaries (NOTE: some libaries migth be compateble with c)

    windows support is comming soon!

Here is some examples with the socket client:
```c++
#include <iostream>
#include "clib/socket/client.hpp" //automaticly chooses either windows or linux/macos

int main(){
    std::string host = "google.com";
    int port = 80;
    int buffer_size = 1024;

    Client c(host, port, buffer_size);

    c.send("GET /search?q=cpp HTTP/1.1\r\nHost: " + host + "\r\nConnection: close\r\n\r\n");
    //the first arg is if you want to read the entire stream or just the amount you have specified
    std::cout << c.recv(true) << std::endl;
}

```

and even easier with the http lib

```c++
#include <iostream>
#include "clib/http/src/multi_http.hpp"

int main(){
    std::cout << HTTP::get("google.com", "/search?q=cpp") << std::endl;
}

```