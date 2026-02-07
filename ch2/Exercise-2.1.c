#include <limits.h>
#include <stdio.h>
#include <math.h>

int main() {
  printf("Size of char in bits: %d\n", CHAR_BIT);
  printf("Max value of char: %d = %.0f\n", CHAR_MAX, pow(2, CHAR_BIT-1)-1);
  printf("Min value of char: %d = %.0f\n", CHAR_MIN, -pow(2, CHAR_BIT-1));

  printf("Max value of unsigned char: %d = %.0f\n", UCHAR_MAX, pow(2, CHAR_BIT)-1);

  printf("Max value of signed short: %d = %.0f\n", SHRT_MAX, pow(2, sizeof(short)*8 - 1)-1);
  printf("Min value of signed short: %d = %.0f\n", SHRT_MIN, -pow(2, sizeof(short)*8 - 1));

  printf("Max value of int: %d = %.0f\n", INT_MAX, pow(2, sizeof(int)*8 - 1)-1);
  printf("Min value of int: %d = %.0f\n", INT_MIN, -pow(2, sizeof(int)*8 - 1));

  printf("Max value of unsigned int: %u = %.0f\n", UINT_MAX, pow(2, sizeof(int)*8));

  printf("Max value of unsigned long: %lu = %.0f\n", ULONG_MAX, pow(2, sizeof(long)*8));

  return 0;
}

