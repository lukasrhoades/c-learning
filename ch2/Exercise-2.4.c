#include <stdio.h>

#define MAXLINE 1000

void squeeze(char string1[], char string2[]);
void getstring(char string[], char delim, int stringlim);

int main() {
  char s1[MAXLINE];
  char s2[MAXLINE];

  getstring(s1, ' ', MAXLINE);
  getstring(s2, '\n', MAXLINE);

  printf("String 1 before squeeze: %s\n", s1);
  squeeze(s1, s2);
  printf("String 1 after squeeze: %s\n", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j, k;

  for (i = j = 0; s1[i] != '\0'; i++) {
    for (k=0; s2[k] != s1[i] && s2[k] != '\0'; k++)
      ;
    if (s2[k] == '\0')
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}

void getstring(char s[], char delim, int lim) {
  int c;
  int i = 0;

  while (i<lim && (c = getchar()) != delim)
    s[i++] = c;
  s[i] = '\0';
}
