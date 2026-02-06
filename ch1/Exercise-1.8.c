#include <stdio.h>

int main() {
  int c, nb, nt, nl;

  nb = nt = nl = 0;
  while((c = getchar()) != EOF) {
    if (c == ' ')
      ++nb;
    if (c == '\t')
      ++nt;
    if (c == '\n')
      ++nl;
  }
  printf("Number of blanks: %d\n", nb);
  printf("Number of tabs: %d\n", nt);
  printf("Number of newlines: %d\n", nl);

  return 0;
}
