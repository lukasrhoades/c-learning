#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\");
      printf("t");
    }
    else if (c == '\b') {
      printf("\\");
      printf("b");
    }
    else if (c == '\\') {
      printf("\\");
      printf("\\");
    }
    else putchar(c);
  }

  return 0;
}
