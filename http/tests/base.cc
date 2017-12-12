#include "../src/http_base.hpp"

int main() {
    std::cout << request("GET", "google.com", 80, "/?gws_rd=cr&amp;dcr=0&amp;ei=uaYvWqPNIsSp6AS5uIawDQ", false, "\r\nUser-Agent: Mozilla()\r\n");
    return 0;
}