#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);

int main() {
  unsigned x = 032; // 11010

  printf("%d\n", invert(x, 3, 2)); // 10110 = 22

  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned xbiq, ibiq, fxor, pad;
  xbiq = getbits(x, p, n);
  ibiq = getbits(~x, p, n);
  fxor = ibiq ^ xbiq;
  pad = fxor << (p+1-n);
  return x ^ pad;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}
