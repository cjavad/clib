#include <iostream>
#include <unistd.h>
#include <term.h>

void ClearScreen()
  {
  if (!cur_term)
    {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
    }

  putp( tigetstr( "clear" ) );
  }


int main(){
    while (true)
    {
        ClearScreen();
        std::cout << "^-^";
        ClearScreen();
        std::cout << "^_^";
    }
    
}