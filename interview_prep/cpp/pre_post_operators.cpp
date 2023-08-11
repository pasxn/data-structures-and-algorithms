#include <iostream>

int main () {
  int x = 8;

  std::cout << ++x <<std::endl;
  std::cout << x++ <<std::endl;
  std::cout << x <<std::endl;

  x = 8;
  std::cout << ++x + x++ <<std::endl;

}
