// doesn't work because making n positive will cause overflow since 
// two's complement means integers range from -2^(wordsize-1) to 2^(wordsize-1) - 1

#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000
#define ADDONE 1

void itoa(int n, char string[]);
void reverse(char string[], int stringlen);

int main() {
  char s[MAXLINE];

  itoa(INT_MIN, s);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[]) {
  int i = 0, sign, hlnn = 0;

  if ((sign = n) < 0) {
    if (n == INT_MIN) {
      s[i++] = -(n % 10) + '0';
      n /= 10;
    }
    n = -n;
  }
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s, i);
}

void reverse(char s[], int len) {
  int i, j, tmp;

  for (i=0, j=len-1; i<j; i++, j--)
    tmp = s[i], s[i] = s[j], s[j] = tmp; 
}
