#include <stdio.h>

struct Rectangle {
  int width;
  int height;
};

// Function to calculate the area of the rectangle
int calculateArea(struct Rectangle rect) {
  return rect.width * rect.height;
}

int main() {
  struct Rectangle myRect = {5, 10};
  int area = calculateArea(myRect);
  printf("Area: %d\n", area);
  return 0;
}
