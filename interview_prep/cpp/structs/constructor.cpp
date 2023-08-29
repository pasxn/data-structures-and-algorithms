#include <iostream>

struct Point {
  int x;
  int y;

  // Default constructor
  Point() : x(0), y(0) {}

  // Parameterized constructor
  Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

int main() {
  // Using the default constructor
  Point origin;

  // Using the parameterized constructor
  Point point1(3, 4);

  std::cout << "Origin: (" << origin.x << ", " << origin.y << ")" << std::endl;
  std::cout << "Point 1: (" << point1.x << ", " << point1.y << ")" << std::endl;

  return 0;
}
