#include <stdio.h>

struct Rectangle {
  int width;
  int height;

  // Member function to calculate the area of the rectangle
  int (*calculateArea)(struct Rectangle*);
};

// Member function implementation
int calculateArea(struct Rectangle* rect) {
  return rect->width * rect->height;
}

int main() {
  struct Rectangle myRect = {5, 10, calculateArea};
  int area = myRect.calculateArea(&myRect);
  printf("Area: %d\n", area);
  return 0;
}
