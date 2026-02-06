#include <stdio.h>

int main() {
  int c, i;
  int cf[38];
  int max, row, col;

  for (i = 0; i < 38; ++i)
    cf[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++cf[c-'0'];
    else if (c >= 'a' && c <= 'z')
      ++cf[10+(c-'a')];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++cf[36];
    else
      ++cf[37];
  }

  max = 0;
  for (i = 0; i < 38; ++i)
    if (cf[i] > max)
      max = cf[i];

  for (row = max; row > 0; --row) {
    for (col = 0; col < 38; ++col) {
      if (cf[col] >= row)
        printf("X");
      else
        printf(" ");
    }
    printf("\n");
  }

  for (col = 0; col < 38; ++col) {
    if (col >= 0 && col <= 9)
      printf("%d", col);
    else if (col == 10)
      printf("abcdefghijklmnopqrstuvwxyzSO");
  }
  printf("\n");

  return 0;
}
