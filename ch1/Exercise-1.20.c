#include <stdio.h>

#define COL_LENGTH 8
#define MAXLINE 1000

int detab_line(char line[], int col_length, int maxline);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = detab_line(line, COL_LENGTH, MAXLINE)) > 0)
    printf("%s", line);

  return 0;
}

int detab_line(char s[], int col_len, int lim) {
  int c, i, j;

  i = j = 0;
  while (i < lim-1 && (c = getchar()) != EOF && c!='\n') {
    if (c == '\t') {
      while (j < col_len) {
        s[i] = ' ';
        ++i;
        ++j;
      }
      j = 0;
    }
    else {
      s[i] = c;
      ++i;
      ++j;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
