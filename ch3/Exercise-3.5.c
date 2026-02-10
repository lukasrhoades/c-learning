#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void itob(int n, char string[], int base);
int charmap(int n);
void reverse(char string[], int string_length);

int main() {
  char s[MAXLINE];

  itob(287, s, 12); // 1BB
  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int b) {
  int sign, i=0;

  if ((sign = n) < 0) {
    if (sign == INT_MAX) {
      s[i++] = -charmap(n%b);
      n /= b;
    }
    n = -n;
  }

  do {
    s[i++] = charmap(n%b);
  } while ((n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';

  reverse(s, i);
}

int charmap(int n) {
  // 0-9 ... A-Z
  int gap = 'A' - ('9'+1);

  if (n > 9)
    n += gap;
  return n + '0';
}

void reverse(char s[], int len) {
  int i, j, tmp;

  for (i=0, j=len-1; i<j; i++, j--)
    tmp = s[i], s[i] = s[j], s[j] = tmp;
}
