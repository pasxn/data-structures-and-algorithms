#include <iostream>
#include <unordered_map>

int main() {
  // declare an unordered_map with int keys and string values
  std::unordered_map<int, int> umap;

  // initialize the unordered_map with some values, using subscript operator []
  umap[1] = 10;
  umap[2] = 34;
  umap[3] = 20;
  umap[0] = 19;

  // using insert()
  umap.insert(std::make_pair(5, 69));

  std::cout << umap[2] << std::endl;  // output: "two"

  // modifying an existing value
  umap[2] = 43;
  std::cout << umap[2] << std::endl;

  // accessing a non-existing key (inserts the key-value pair)
  std::cout << umap[6] << std::endl;  // Output: ""

  // Using find() to access and modify values safely
  auto it = umap.find(1);
  if (it != umap.end()) {
      it->second = 444;
      // it->first is read only
  }

  if (umap.find(1) != umap.end()) {
    std::cout << "key 1 exists." << std::endl;
  }

  umap.erase(1);  // remove the element with key 4

  for (const auto& pair : umap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  std::cout << "size: " << umap.size() << std::endl;
  umap.clear();
  std::cout << "size: " << umap.size() << std::endl;

  return 0;
}
