#include <stdio.h>

#define MAXLINE 1000

int main() {
  int c;
  int i = 0;
  int lim = MAXLINE;

  while (i < lim-1) {
    c = getchar();
    if (c == EOF)
      lim = 0;
    if (c == '\n')
      lim = 0;
    putchar(c);
    ++i;
  }

  return 0;
}
