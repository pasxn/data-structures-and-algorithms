#include <iostream>
#include <type_traits>


template <typename T>
constexpr T square1(T x) {
  return x * x;
}

template <typename T>
constexpr T square2(T x) {
  static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");
  return x * x;
}

int main() {

  constexpr auto x = square1(5);
  std::cout << x << '\n';

  constexpr auto y = square1(5.5);
  std::cout << y << '\n';

  constexpr auto xx = square2(5);
  std::cout << xx << '\n';

  constexpr auto yy = square2(5.5);
  std::cout << yy << '\n';      
}
