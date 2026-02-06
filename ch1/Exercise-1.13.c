#include <stdio.h>

#define IN  0
#define OUT 1

int main() {
  int c, wcc, state;  
  int wl[20];  
  int i, row, col, max;

  for (i = 0; i < 20; ++i)
    wl[i] = 0;

  wcc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        ++wl[wcc]; 
        wcc = 0;
      }
      state = OUT;
    }
    else {
      if (state == OUT)
        state = IN;
      ++wcc;
    }
  }

  max = 0;
  for (i = 0; i < 20; ++i)
    if (wl[i] > max)
      max = wl[i];

  for (row = max; row > 0; --row) {
    for (col = 0; col < 20; ++col)
      if (wl[col] >= row)
        printf("X");
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
