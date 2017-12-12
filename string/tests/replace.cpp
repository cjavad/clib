#include <iostream>
#include <vector>
#include <limits>
#include "../src/string.hpp"


void replace(String s) {
	for (size_t i = 0; i < 1000; i++)
	{
		std::cout << s.replace("insert", "world!") << std::endl;
	}
}

void vec(String s) {
	for (size_t i = 0; i < 1000; i++)
	{
		std::cout << String("world!").join(s.split("insert")) << std::endl;
	}
}

int main(int argc, char* args[]) {
	String str = "Hello insert and die insert insert";
	/// if there is 1 argument run replace
	if (argc > 1) {
		std::cout << "replace" << std::endl;
		/// fastest if only 1
		/// slower 20-40ms if 3
		replace(str);
	}
	/// if there is two arguments run vector
	if (argc > 2) {
		/// 1-2 seconds slower if only one
		/// if more this is faster by a lot
		std::cout << "vector" << std::endl;
		vec(str);
	}
	return 0;
}