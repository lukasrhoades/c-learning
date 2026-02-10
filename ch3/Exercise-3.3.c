#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

void expand(char string1[], char string2[]);
void getstring(char string[], int delim, int stringlim);
int is_conti_alnum(int c1, int c2);

int main() {
  char s1[MAXLINE], s2[MAXLINE];

  getstring(s1, '\n', MAXLINE);
  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

void expand(char s1[], char s2[]) {
  int i, j, k;

  for (i=0, j=0; s1[i] != '\0'; i++) {
    if (s1[i] == '-') {
      if (is_conti_alnum(s1[i-1], s1[i+1])) {
        for (k=1; s1[i-1]+k != s1[i+1]; k++)
          s2[j-1+k] = s1[i-1]+k;
        s2[j-1+k] = s1[i+1];
        j += k;
        i++;
      }
      else
        s2[j++] = '-';
    }
    else
      s2[j++] = s1[i];
  }
  s2[j] = '\0';
}

void getstring(char s[], int delim, int lim) {
  int c, i;

  i = 0;
  while (i<lim && (c = getchar()) != delim)
    s[i++] = c;
  s[i] = '\0';
}

int is_conti_alnum(int c1, int c2) {
  return
    ((c1 >= '0' && c1 <= '9') && (c2 >= '0' && c2 <= '9'))
    || ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z'))
    || ((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'A' && c2 <= 'Z'));
}
