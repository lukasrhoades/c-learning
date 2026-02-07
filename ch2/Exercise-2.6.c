#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned getbits(unsigned x, int p, int n);

int main() {
  unsigned x = 024;     // 10100
  unsigned y = 05;      // 00101

  // the x bits in Q        010
  // getbits y              101 
  // xor x and y bits in Q  111
  // pad RHS with 0         1110
  // xor the xor with x    11010 

  printf("%d\n", setbits(x, 3, 3, y)); // 26

  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned xbiq, ybiq, fxor, pad;
  xbiq = getbits(x, p, n);
  ybiq = y & ~(~0 << n);
  fxor = xbiq ^ ybiq;
  pad = (fxor << (p+1-n));
  return x ^ pad;
}

unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p+1-n)) & ~(~0 << n);
}
