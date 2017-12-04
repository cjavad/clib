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
        */
        String(const std::string& x){self = x;}
        String(const char* x){self = x;}
        String& operator= (const std::string& x){return *this;}
        String& operator= (const char& x){return *this;}
        //return std::string
        std::string to_str(){return self;}
        //spliting function
        std::vector<std::string> split(std::string sep);
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
    std::string s = self; ///copy self
    std::vector<std::string> v; ///create out vector
    size_t pos = 0; ///position var
    std::string token; ///declare token
    while ((pos = s.find(sep)) != std::string::npos) {
        //while there is something to look for
        //set token to value
        token = s.substr(0, pos);
        //and add to vector
        v.push_back(token);
        //and at last remove from string
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
    std::string out = ""; ///declare string to return
    std::string sep = self; ///copy self
    for (size_t i = 0; i < arr.size(); i++)
    {
        //for each item in loop
        if(!(i == arr.size() - 1)){
            //if itsn't the last element add seperator/delimeter
            out += arr[i] + sep;
        } else {
            //else add rest
            out += arr[i];
        }

    }
    //return out
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