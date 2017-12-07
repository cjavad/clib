#include <iostream>
#include <vector>
#include "../mail.hpp"

int main(){
    SMTP m("smtp.gmail.com", 465, "javadshafique@gmail.com", "JAS123as");
    std::vector<std::string> msg =  m.compose("javadshafique@hotmail.com", "cpp", "Hello From c++");
    std::cout << m.send(msg) << std::endl;
    return 0;
}