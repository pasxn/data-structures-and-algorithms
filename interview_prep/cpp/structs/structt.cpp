#include <iostream>

class Rectangle {
public:
  int width;
  int height;

  // Member function to calculate the area of the rectangle
  int calculateArea() {
    return width * height;
  }
};

int main() {
  Rectangle myRect = {5, 10};
  int area = myRect.calculateArea();
  std::cout << "Area: " << area << std::endl;
  return 0;
}
