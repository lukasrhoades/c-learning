#include <stdio.h>

#define MAXLINE 1000

void reverse(char line[], int length);
int get_line(char line[], int linelim);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
}

void reverse(char s[], int len) {
  int i, tmp;

  for (i=0; i < len-i-2; i++) {
    tmp = s[i];
    s[i] = s[len-i-2];
    s[len-i-2] = tmp;
  }
}

int get_line(char s[], int lim) {
  int c, i;

  for (i=0; i < lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
