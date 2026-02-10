#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void escape_rev(char s[], char t[]);
void getstring(char string[], int delim, int stringlim);

int main() {
  int len;
  char s[MAXLINE], t1[MAXLINE], t2[MAXLINE];

  getstring(t1, '\n', MAXLINE);
  getstring(t2, EOF, MAXLINE);

  escape(s, t1);
  printf("%s\n", s);

  escape_rev(s, t2);
  printf("%s\n", s);

  return 0;
}

void escape(char s[], char t[]) {
  int i = 0, j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j] = 't';
        break;
      default:
        s[j] = t[i];
        break;
    }
    i++;
    j++;
  }
  s[j] = '\0';
}

void escape_rev(char s[], char t[]) {
  int i = 0, j = 0;

  while (t[i] != '\0') {
    switch (t[i]) {
      case '\\':
        switch (t[i+1]) {
          case 'n':
            s[j] = '\n';
            i++;
            break;
          case 't':
            s[j] = '\t';
            i++;
            break;
          default:
            s[j] = '\\';
            break;
        }
        break;
      default:
        s[j] = t[i];
        break;
    }
    i++;
    j++;
  }
}

void getstring(char s[], int delim, int lim) {
  int c, i = 0;

  while (i<lim && (c = getchar()) != delim)
    s[i++] = c;
  s[i] = '\0';
}
