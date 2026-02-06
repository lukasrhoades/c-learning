#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int linelim);
void rm_trailing(char line[], int length);
int get_length(char line[]);  // for testing purposes

int main() {
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    printf("Length before removing trailing whitespace: %d\n", get_length(line));
    rm_trailing(line, len);
    printf("Length after removing trailing whitespace: %d\n", get_length(line));
    printf("%s", line);
  }

  return 0;
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

void rm_trailing(char s[], int length) {
  int i;

  for (i = length-2; i>=0 && (s[i] == 32 || s[i] == 9); --i)  // ' ' or '\t'
    ;
  if (i>=0) {
    s[i+1] = '\n';
    s[i+2] = '\0';
  }
  else // entirely blank line
    s[0] = '\0';
}

int get_length(char s[]) {
  int i;

  for (i=0; s[i] != '\0'; ++i)
    ;

  return i;
}
