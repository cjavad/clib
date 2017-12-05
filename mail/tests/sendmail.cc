#include <iostream>
#include "../mail.hpp"

int main(){
    SMTP m("smtp.gmail.com", 465, "javadshafique@gmail.com", "JAS123as");
    std::cout << m.compose("javadshafique@hotmail.com", "cpp", "Hello From c++") << std::endl;
    return 0;
}