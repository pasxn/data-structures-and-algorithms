#include <stdio.h>
#include <time.h>
#include <stdarg.h>

void tlog(const char* fmt,...) {
  char msg[50];
  strftime(msg, sizeof msg, "%T", localtime(&(time_t){time(NULL)}));
  printf("[%s] ", msg);
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
}

void simple_printf(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);

  while (*fmt != '\0') {
    if (*fmt == 'd') {
      int i = va_arg(args, int);
      printf("%d\n", i);
    } else if (*fmt == 'c') {
      // A 'char' variable will be promoted to 'int'
      // A character literal in C is already 'int' by itself
      int c = va_arg(args, int);
      printf("%c\n", c);
    } else if (*fmt == 'f') {
      double d = va_arg(args, double);
      printf("%f\n", d);
    }
    ++fmt;
  }

  va_end(args);
}

int main(void) {
  simple_printf("dcff", 3, 'a', 1.999, 42.5);
  printf("--------------------------------------\n");
  tlog("logging %d %d %d...\n", 1, 2, 3);
}
