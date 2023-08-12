#include <iostream>


// generic types -> function templates
template <typename T>
T add(T x) {
  return x + x;
}

template <typename T>
constexpr T square(T x) {
  return x * x;
}

// class templates
template <typename T1, typename T2>
class Pair {
  private:
    T1 first;
    T2 second;
    
  public:
    Pair(T1 first, T2 second) : first(first), second(second) {}

    T1 getFirst() const {
      return first;
    }
    
    T2 getSecond() const {
      return second;
    }
};

int main() {
  std::cout << add(3) << std::endl;
  std::cout << add(3.3) << std::endl;
  std::cout << square(3) << std::endl;

  // stating the types when creating the particular objects
  Pair<int, float>* p = new Pair(1, 2.5f);
  std::cout << p->getFirst() << std::endl;
  std::cout << p->getSecond() << std::endl;
}
