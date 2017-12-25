/* Copyright (c) 2017 Javad Shafique */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

// convert string to integer for switch stament
// uses const expr for the conversion
constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

class open {
    //inspired by python
    private:
        std::fstream file;
    public:
        //constructor
        open(std::string filename, std::string mode);
        //write to file
        void write(std::string in, std::string end = "\n") {
            file << (in + end).c_str();
        }
        //write vector to file
        void writelines(std::vector<std::string> in, std::string end = "\n") {
            for(int i; i < (int)in.size(); i++) {
                write(in[i], end);
            }
        }
        //read intire file file
        std::string read() {
            // define out varibles
            std::string tmp;
            std::string out = "";
            // check if file is open
            if(file.is_open()){
                // while there is something to read
                // add it to the std::string out
                while (std::getline(file, tmp)) {
                    out += tmp;
                }
            }
            //always return it
            return out;
        }
        //read all lines into an array (like python)
        std::vector<std::string> readlines() {
            // define varible out (vector)
            std::vector<std::string> out;
            // check if file is open
            if(file.is_open()) {
                // if it's read the file
                for(std::string line; std::getline(file, line); ) {
                    out.push_back(line);
                }
           }
           // always return the vector
           return out;
        }
        //read specific line
        std::string readline(int line) {
            return readlines()[line];
        }

        //close file
        void close() {
            file.close();
        }
        //check if open
        bool isOpen(){ return file.is_open(); }
};

open::open(std::string filename, std::string mode) {
    // big ass switch
    switch(str2int(mode.c_str())) {
        // check if you want to only read from file
        // then set file to ios::out
        case str2int("r"):
            file.open(filename, std::ios::out);
            break;

        // if you want to write to file use ios::trunc so 
        // yu always override the previos files
        case str2int("w"):
            file.open(filename, std::ios::in | std::ios::trunc);
            break;
        
        // if you choose to append then the ios::app flag will be 
        // added to our file stream
        case str2int("a"):
            file.open(filename, std::ios::in | std::ios::app);
            break;
        
        // then we have the binary operations. first the read as binary
        case str2int("rb"):
            file.open(filename, std::ios::out | std::ios::binary);
            break;
        
        // then a write as binary which uses the ios::trunc flag so 
        // it will override previos files.
        case str2int("wb"):
            file.open(filename, std::ios::in | std::ios::trunc | std::ios::binary);
            break;

        // and a append to binary if you want to continue to write to a file.
        case str2int("ab"):
            file.open(filename, std::ios::out | std::ios::app | std::ios::binary);
            break;
        
        // read/write which does not append to the file

        case str2int("r+"):
            file.open(filename, std::ios::out | std::ios::in);
            break;
        
        // a read/write plus which appends to the file
        case str2int("r++"):
            file.open(filename, std::ios::out | std::ios::in | std::ios::app);
            break;
        
        // the same read/write without append but in binary
        case str2int("b+"):
            file.open(filename, std::ios::out | std::ios::in | std::ios::binary);
            break;

        // a plus version of the read/write binary so this one appends
        case str2int("b++"):
            file.open(filename, std::ios::out | std::ios::in | std::ios::app | std::ios::binary);
            break;
        
        // if none of the above have been selected throw an error
        default:
            throw "Wrong mode selected";
            break;
    }
}

