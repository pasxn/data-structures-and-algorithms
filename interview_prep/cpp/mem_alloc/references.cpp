#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


void modifyValue(int& ref) {
  ref = 42;
}

void processLargeArray(std::vector<int> &arr) {
  sort(arr.begin(), arr.end());
}

int& findValue(int arr[], int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == value) {
      return arr[i];
    }
  }
  return arr[0];
}

int data[] = {5, 10, 15, 20};
int& getElement(int index) {
    std::cout << "impressive behavior" << std::endl;
    return data[index];
}

int main() {
  using namespace std;

  cout << "passing by reference -> " << endl;
  int a = 69;
  cout << "before modifying: " << a << endl;
  modifyValue(a);
  cout << "after modifying: " << a << endl;
  cout << endl;

  cout << "avoid copying -> " << endl;
  vector<int> data = {1, 6, 2, 7, 3, 8, 4, 9, 5, 0};
  cout << "before preocessing: " << endl;
  copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));
  cout << endl;
  processLargeArray(data);
  cout << "after preocessing: " << endl;
  copy(data.begin(), data.end(), std::ostream_iterator<int>(std::cout, " "));
  cout << endl;
  cout << endl;

  cout << "return reference -> " << endl;
  int numbers[] = {10, 20, 30, 40, 50};
  cout << "brfore preocessing: " << numbers[2] << endl;
  int &result = findValue(numbers, 5, 30);
  result = 33;
  cout << "after preocessing: " << numbers[2] << endl;
  cout << endl;

  cout << "alias -> " << endl;
  int aa = 69;
  int& a_alias = aa;
  cout << "before modifying: " << aa << endl;
  a_alias = 42;
  cout << "after modifying: " << aa << endl;
  cout << endl;

  cout << "references as function return types -> " << endl;
  getElement(2) = 25;
  cout << endl;

  return 0;
}
