#include <stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned rotate(unsigned x);

int main() {
  printf("%u\n", rightrot(21, 5));

  return 0;
}

unsigned rightrot(unsigned x, int n) {
  while (n > 0) {
    x = rotate(x);
    n--;
  }

  return x;
}

unsigned rotate(unsigned x) {
  if (x & 1) {
    x = x>>1 | ~0u^(~0u>>1);
  }
  else {
    x = x >> 1;
  }

  return x;
}
