#include <fstream>
#include <iostream>
#include <vector>

using std::ios;

class open {
    //inspired by python
    private:
        std::fstream file;
    public:
        //constructor
        open(std::string filename, std::string mode);
        //write to file
        void write(std::string in) {
            file << in.c_str();
        }
        //read intire file file
        std::string read() {
            std::string tmp;
            std::string out;
            while (getline(file, tmp)) {
                out += tmp + "\n";
            }
            return out;
        }
        //read all lines into an array (like python)
        std::vector<std::string> readlines() {
            std::vector<std::string> out;
            std::string tmp;
            while (getline(file, tmp)) {
                out.push_back(tmp);
            }
            return out;
        }
        //read specific line
        std::string readline(int line) {
            return this->readlines()[line];
        }

        //close file
        void close() {
            file.close();
        }
        //check if open
        bool isOpen(){ return file.is_open(); }
};

open::open(std::string filename, std::string mode) {
    if ( mode == "w" ) {
        file.open(filename, ios::in | ios::trunc);
    } else if ( mode == "r" ) {
        file.open(filename, ios::out);
    } else if ( mode == "r+" ) {
        file.open(filename, ios::out | ios::in);
    } else if ( mode == "a" ) {
        file.open(filename, ios::in | ios::app);
    } else if( mode == "rb" ) {
        file.open(filename, ios::out | ios::binary);
    } else if ( mode == "wb" ) {
        file.open(filename, ios::in | ios::binary | ios::trunc);
    } else if ( mode == "ab" ) {
        file.open(filename, ios::in | ios::app | ios::binary );
    } else if ( mode == "b+" ) {
        file.open(filename, ios::in | ios::out | ios::binary);
    } else {
        throw "Mode is not set";
    }
}

