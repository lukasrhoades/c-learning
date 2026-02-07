#include <stdio.h>

#define MAXLINE 1000

int any(char string1[], char string2[]);
void getstring(char string[], char delim, int stringlim);

int main() {
  char s1[MAXLINE];
  char s2[MAXLINE];

  getstring(s1, ' ', MAXLINE);
  getstring(s2, '\n', MAXLINE);

  printf("%d\n", any(s1, s2));

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i=0; s1[i] != '\0'; i++) {
    for (j=0; s2[j] != s1[i] && s2[j] != '\0'; j++)
      ;
    if (s2[j] == s1[i])
      return i;
  }

  return -1;
}

void getstring(char s[], char delim, int lim) {
  int c;
  int i = 0;

  while (i<lim && (c = getchar()) != delim)
    s[i++] = c;
  s[i] = '\0';
}
