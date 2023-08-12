#include <iostream>


template<typename... Args>
constexpr int sum(Args&&... args) {
  return (args + ... + 0);
}

int main() {
  // returns 15
  std::cout << sum(4,5,6) << '\n';

  // returns zero
  std::cout << sum() << '\n';

}