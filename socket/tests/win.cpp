#include <iostream>
#include "../src/client/win_client.hpp"


int main() {
	Client c("google.com", 80, 1024);
	c.say("GET / HTTP/1.1\r\n\r\n");
	printf("%s\n", c.hear().c_str());
}