/*
Clib string libary Copyrigth (C) Javad Shafique 2017
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <tuple>
#include <vector>


/*
Strings class. funcs =>
______________________
[private] String::swap_case(char c); Swaps a char used in String::swapcase
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
        //constuctor
        String(std::string str);
        //spliting function
        std::vector<std::string> split(std::string sep);
        //joining function
        std::string join(std::vector<std::string> arr);
        //quick'n dirty lowercase/uppercase functions
        std::string upper(){std::string str = self; std::transform(str.begin(), str.end(), str.begin(), ::toupper); return str;};
        std::string lower(){std::string str = self; std::transform(str.begin(), str.end(), str.begin(), ::tolower); return str;};
        //and some swapcase stuff
        std::string swapcase(){std::string str = self; std::transform(str.begin(), str.end(), str.begin(), this->swap_case); return str;}
};

/*
class constuctor
*/

String::String(std::string str){
    self = str;
}

/*
basic splitter
*/
std::vector<std::string> String::split(std::string sep){
    std::string s = self;
    std::vector<std::string> v;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(sep)) != std::string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + sep.length());
    }
    v.push_back(s); //push back rest
    return v;
}

/*
joining using a python style join function:
| ---------------- |
| str.join(vector);|
| ---------------- |
*/

std::string String::join(std::vector<std::string> arr){
    std::string out = "";
    std::string sep = self;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if(!(i == arr.size() - 1)){
            out += arr[i] + sep;
        } else {
            out += arr[i];
        }

    }
    return out;
}

/*
Basic_List class. functions =>
______________________________
a vector for each datatype we support
a append for each datatype we support
a clear for each datatype we support
a size for each datatype we support
a get for each datatype we support

a basic list system that powers List

*/

class Basic_List {
    private:
        //a bunch of vectors
        std::vector<char> char_vec;
        std::vector<int> int_vec;
        std::vector<float> float_vec;
        std::vector<std::string> str_vec;
    public:
        void append_c(char c){char_vec.push_back(c);};
        void append_i(int i){int_vec.push_back(i);};
        void append_f(float f){float_vec.push_back(f);};
        void append_s(std::string s){str_vec.push_back(s);};

        int size_c(){return char_vec.size();};
        int size_i(){return int_vec.size();};
        int size_f(){return float_vec.size();};
        int size_s(){return str_vec.size();};

        void pop_c(){return char_vec.pop_back();};
        void pop_i(){return int_vec.pop_back();};
        void pop_f(){return float_vec.pop_back();};
        void pop_s(){return str_vec.pop_back();};

        void clear_c(){return char_vec.clear();};
        void clear_i(){return int_vec.clear();};
        void clear_f(){return float_vec.clear();};
        void clear_s(){return str_vec.clear();};

        char get_c(int index){return char_vec[index];};
        int get_i(int index){return int_vec[index];};
        float get_f(int index){return float_vec[index];};
        std::string get_s(int index){return str_vec[index];};
};

class List {
//WIP
};