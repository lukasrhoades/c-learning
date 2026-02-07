#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

unsigned long int htoi(char string[]);
int ishexnum(char c);
int get_line(char line[], int linelim);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    printf("%lu\n", htoi(line));

  return 0;
}

unsigned long int htoi(char s[]) {
  int i;
  unsigned long int n = 0;

  for (i=0; ishexnum(s[i]); ++i) {
    if (i == 0 && s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
      ++i;
    else {
      if (isdigit(s[i]))
        n = 16 * n + (s[i] - '0');
      else if (s[i] >= 'a' && s[i] <= 'f')
        n = 16 * n + (s[i] - 'a') + 10;
      else if (s[i] >= 'A' && s[i] <= 'F')
        n = 16 * n + (s[i] - 'A') + 10;
    }
  }

  return n;
}

int ishexnum(char c) {
  return isdigit(c) || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F' || c == 'x' || c == 'X';
}

int get_line(char s[], int lim) {
  int c, i;

  i = 0;
  while (i < MAXLINE-1 && (c = getchar()) != EOF && c!='\n') {
    s[i] = c;
    ++i;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
