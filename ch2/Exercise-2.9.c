#include <stdio.h>

// x-1 turns the rightmost 1-bit into 0 and turns any remaining 0's into 1's
// taking the and of x and x-1 means the new 0 stays 0 and all remaining 1's to its right become 0's
// the result is thus x with its rightmost 1-bit turned into 0

int bitcount(unsigned x);

int main() {
  unsigned test = 0131;  // 1011001

  printf("%d\n", bitcount(test));  // 4

  return 0;
}

int bitcount(unsigned x) {
  int b = 0;

  while (x > 0) {
    x &= (x-1);
    b++;
  }

  return b;
}
