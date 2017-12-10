#include <iostream>
#include <vector>
#include "../src/string.hpp"

int main() {
	String str = "H A L L O";
	String s = str + str;

	std::vector<std::string> vec = str.split(" ");
	std::cout << String("-").join(vec) << std::endl;
	std::cout << s.str() << std::endl;
	return 0;
}