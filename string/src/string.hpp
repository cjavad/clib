#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class String {
    std::string self;
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