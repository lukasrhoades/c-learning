#include <stdio.h>

int main() {
  int c1, c2;

  while ((c2 = getchar()) != EOF) {
    if (c1 != ' ')
      putchar(c2);
    if (c1 == ' ')
      if (c2 != ' ')
        putchar(c2);
    ;
    c1 = c2;
  }

  return 0;
}
