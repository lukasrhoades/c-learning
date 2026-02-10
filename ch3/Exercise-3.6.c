#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itoa(int min_field_w, int n, char string[]);
void reverse(char string[], int stringlength);

int main() {
  char s[MAXLINE];

  itoa(5, 234, s);
  printf("%s\n", s);

  return 0;
}

void itoa(int w, int n, char s[]) {
  int i = 0, sign;

  if ((sign = n) < 0) {
    if (sign == INT_MIN) {
      s[i++] = -(n%10) + '0';
      n /= 10;
    }
    n = -n;
  }

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  while (i < w) {
    s[i++] = ' ';
  }
  s[i] = '\0';

  reverse(s, i);
}

void reverse(char s[], int len) {
  int i, j, tmp;

  for (i=0, j=len-1; i<j; i++, j--)
    tmp = s[i], s[i] = s[j], s[j] = tmp;
}
