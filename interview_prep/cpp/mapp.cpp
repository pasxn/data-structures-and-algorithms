#include <iostream>
#include <map>

int main() {
  // declaration using default constructor
  std::map<int, std::string> myMap;

  // initialization using initializer list
  std::map<char, int> charCount = {{'a', 3}, {'b', 5}, {'c', 2}};

  myMap.insert(std::make_pair(1, "one"));
  myMap[2] = "two"; // using operator[] for insertion

  std::cout << myMap[1] << std::endl; // output: "one"

  for (const auto& pair : charCount) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  auto it = charCount.find('b');
  if (it != charCount.end()) {
    std::cout << "found: " << it->first << ": " << it->second << std::endl;
  } else {
    std::cout << "not found" << std::endl;
  }

  if (myMap.empty()) {
    std::cout << "map is empty" << std::endl;
  } else {
    std::cout << "map size: " << myMap.size() << std::endl;
  }

  myMap.erase(1); // remove element with key 1

  int count = charCount.count('a'); // returns 1

  std::cout << count << std::endl;

  return 0;
}
