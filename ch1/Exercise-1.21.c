#include <stdio.h>

#define COL_LENGTH 8
#define MAXLINE 1000

int entab_line(char line[], int col_length, int line_lim);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = entab_line(line, COL_LENGTH, MAXLINE)) > 0)
    printf("%s", line);

  return 0;
}

int entab_line(char s[], int col_len, int lim) {
  int c, i, j, nb, tmp;

  i = j = nb = 0;
  while (i < lim-1 && (c = getchar()) != EOF && c!='\n') {
    if (c == ' ')
      if (j == col_len-1) {
        s[i] = '\t';
        ++i;
        nb = 0;
        j = 0;
      }
      else {
        ++nb;
        ++j;
      }
    else {
      if (c == '\t') {
        s[i] = c;
        nb = 0;
        j = 0;
        ++i;
      }
      else {
        if (j < col_len-1) {
          tmp = i+nb;
          while (nb > 0) {
            s[i+nb-1] = ' ';
            --nb;
          }
          i = tmp;
        }
        s[i] = c;
        ++i;
        ++j;
      }
    }
  }
  tmp = i+nb;
  while (nb > 0) {
    s[i+nb-1] = ' ';
    --nb;
  }
  i = tmp;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
