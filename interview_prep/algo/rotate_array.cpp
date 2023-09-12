#include <iostream>
#include <vector>

void rightRotate(std::vector<int>& arr, int k) {
  int n = arr.size();
  
  // ensure k is within the array size to handle rotations greater than the array size
  k = k % n;

  std::vector<int> temp(arr.end() - k, arr.end());

  for (int i = n - 1; i >= k; --i) {
    arr[i] = arr[i - k];
  }

  for (int i = 0; i < k; ++i) {
    arr[i] = temp[i];
  }
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  int rotateCount = 2;

  rightRotate(arr, rotateCount);

  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
