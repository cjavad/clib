#include <iostream>
#include "../src/param.hpp"

int main()
{
    String url("http://example.com/long-ass-string/hello?hello=q");
    std::vector<std::string> vec = split_url(url);
    /// at index 0 is the protocol
    /// at index 1 is the base url 
    /// as index 2 is the query_s (query string/urlencoded)
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}