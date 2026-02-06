#include <stdio.h>

#define MAXLINE 1000
#define IN_COMMENT 1
#define OUT_COMMENT 0

int get_line(char line[], int maxline);
int strip_comments(char line[], int status);
int not_empty(char line[]);

int main() {
  int len, status;
  char line[MAXLINE];

  status = OUT_COMMENT;
  while ((len = get_line(line, MAXLINE)) > 0) {
    status = strip_comments(line, status);
    if (not_empty(line))
      printf("%s", line);
  }
}

int get_line(char s[], int lim) {
  int c, i;

  i = 0;
  while (i < lim-1 && (c = getchar()) != EOF && c!='\n') {
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

int strip_comments(char s[], int status) {
  int i;

  for (i=0; s[i] != '\n'; ++i) {
    if (status == OUT_COMMENT && s[i] == '/') {
      ++i;
      if (s[i] == '*') {
        status = IN_COMMENT;
        s[i-1] = ' ';
        s[i] = ' ';
      }
    }
    if (status == IN_COMMENT && s[i] == '*') {
      ++i;
      if (s[i] == '/') {
        status = OUT_COMMENT;
        s[i-1] = ' ';
        s[i] = ' ';
      }
    }
    if (status == IN_COMMENT)
      s[i] = ' ';
  }

  return status;
}

int not_empty(char s[]) {
  int i, nc;

  i = nc = 0;
  while (s[i] != '\n') {
    if (s[i] != ' ')
      ++nc;
    ++i;
  }

  return nc;
}
