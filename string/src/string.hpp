/*
Clib string libary Copyrigth (C) Javad Shafique 2017
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <tuple>
#include <vector>

/// Note all functions return std::string not String.
/// But you can still String s = std::string("something");
/// to cout it use either String().str() or String().c_str()

/*
Strings class. funcs =>
______________________
[private] String::self; std::string variable
[private] String::swap_case(char c); Swaps a char used in String::swapcase
[public] String::to_str(); returns std::string aka. [private] self;
[public] String::join(std::vector<std::string>); Inspired by python takes vector of strings an adds them with a seperator (the string).
[public] String::split(std::string sep); takes a seperator an splits the string by that seperator. returna a vector.
[public] String::upper(); returns an all uppercase string.
[public] String::lower(); returns an all lowercase string.
[public] String::swapcase(); returns a string with swapped cases. uses String::swap_case(char c);
*/

class String {
    private:
        //the actaul string
        std::string self;
        //swap case of letters
        static char swap_case(char c){if (std::isupper(c)) {return std::tolower(c);} else {return std::toupper(c);}}

    public:
        //conversion types
        /*
        From char to String
        From std::string to String
        and assigning value to self

		Plus Equal operators
        */
        String(const std::string& x){self = x;}
        String(const char* x){self = x;}
        String& operator= (const std::string& x) { return *this; }
        String& operator= (const char& x) { return *this; }
		// Plus equal operator
		String operator+= (std::string& x) { self = self + x; return String(self); }
		String operator+= (const char* x) { self = self + x; return String(self); }

		//get length of string
		int len() { return sizeof(self) / sizeof(std::string); }
        //return std::string
        std::string str() { return self; }
		//return as char
		const char* c_str() { return self.c_str(); }
        //spliting function
        std::vector<std::string> split(std::string sep);
		//replacing function
		std::string replace(std::string from, std::string to);
		//and a vector replacing function
		std::string replace_vector(std::string from, std::string to) { return String(to).join(this->split(from)); };
        //joining function
        std::string join(std::vector<std::string> arr);
        //quick'n dirty lowercase/uppercase functions
        std::string upper(){std::string str = self; std::transform(str.begin(), str.end(), str.begin(), ::toupper); return str;};
        std::string lower(){std::string str = self; std::transform(str.begin(), str.end(), str.begin(), ::tolower); return str;};
        //and some swapcase stuff
        std::string swapcase(){std::string str = self; std::transform(str.begin(), str.end(), str.begin(), swap_case); return str;}
};


/*
basic splitter
*/
std::vector<std::string> String::split(std::string sep){
    std::string str = self; ///copy self
    std::vector<std::string> v; ///create out vector
    size_t pos = 0; ///position var
    std::string token; ///declare token
    while ((pos = str.find(sep)) != std::string::npos) {
        //while there is something to look for
        //set token to value
        token = str.substr(0, pos);
        //and add to vector
        v.push_back(token);
        //and at last remove from string
        str.erase(0, pos + sep.length());
    }
    v.push_back(str); //push back rest
    return v;
}


/*
Replacer
*/
std::string String::replace(std::string from, std::string to) {
	std::string str = self; /// copy self
	if (from.empty())
		return str;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
	return str;
}


/*
joining using a python style join function:
| ---------------- |
| str.join(vector);|
| ---------------- |
*/

std::string String::join(std::vector<std::string> arr){
    std::stringstream out; ///declare string to return
    std::string sep = self; ///copy self
    for (size_t i = 0; i < arr.size(); i++)
    {
		if (i != 0) {
			out << sep;
		}
		out << arr[i];
    }
    //return out as string
    return out.str();
}
