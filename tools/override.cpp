#include <iostream>
#include "base64.hpp"


int main(){
  std::string a = b64_encode("ENCODE ME");
  std::string b = b64_decode(a);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  return 0;
}