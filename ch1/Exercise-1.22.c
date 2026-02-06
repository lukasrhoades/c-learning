#include <stdio.h>

#define COL_LENGTH 50
#define MAXLINE 1000

int line_splitter(char line[], int col_length, int line_lim);
int get_word(char word[], int col_length, int col_index);
void dump_blanks(char line[], int num_blanks, int line_index);
int dump_word(char line[], int line_index, char word[], int word_length, int max_copy, int col_length);
void copy(char from[], char to[], int from_idx, int to_idx);
int mod(int dividend, int divisor);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = line_splitter(line, COL_LENGTH, MAXLINE)) > 0)
    printf("%s", line);

  return 0;
}

int line_splitter(char s[], int col_len, int lim) {
  int i, j, len, nb, diff;
  char word[MAXLINE];

  i = j = nb = diff = 0;
  len = get_word(word, col_len, j);
  if (len == -2)
    return 0;
  while (len > -1 && i < lim-1) {
    if (len == 0) {
      ++nb;
      ++j;
    }
    else {
      if (j+len > col_len) {
        dump_blanks(s, nb, i);
        i = i + nb;
        nb = 0;
        s[i] = '\n';
        ++i;
        i = i + dump_word(s, i, word, len, col_len, col_len);
        j = len;
      }
      else {
        dump_blanks(s, nb, i);
        i = i + nb;
        nb = 0;
        diff = dump_word(s, i, word, len, col_len-j, col_len);
        i = i + diff;
        if (len < col_len-j)
          j = j + len;
        else
          j = mod(j+diff, col_len);
      }
    }
    if (len > 0) {
      ++nb;
      ++j;
    }

    len = get_word(word, col_len, j);
  }
  if (len == -1) {
    int true_len;

    true_len = 0;
    while (word[true_len] != '\0')
      ++true_len;
    dump_blanks(s, nb, i);
    i = i + nb;
    i = i + dump_word(s, i, word, true_len, col_len-j, col_len);
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}

int get_word(char s[], int len, int j) {
  int c, i;

  i = 0;
  while ((c = getchar()) != ' ' && c != '\n' && c != EOF) {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  if (c == '\n') {
    i = -1;
  }
  if (c == EOF) {
    i = -2;
  }

  return i;
}

void dump_blanks(char s[], int nb, int i) {
  while (nb > 0) {
    s[i+nb-1] = ' ';
    --nb;
  }
}

int dump_word(char line[], int i, char word[], int wl, int mc, int col_len) {
  int j;
  char new_word[MAXLINE];

  j = 0;
  while (j < wl && j < mc) {
    line[i+j] = word[j];
    ++j;
  }
  wl = wl - mc;
  if (wl >= 0) {
    line[i+j] = '\n';
    ++j;
    copy(word, new_word, j-1, j-1+wl);
    j = j + dump_word(line, i+j, new_word, wl, col_len, col_len);
  }

  return j;
}

void copy(char from[], char to[], int i, int j) {
  int k;

  k = 0;
  while (i <= j) {
    to[k] = from[i];
    ++i;
    ++k;
  }
}

int mod(int a, int b) {
  int c;

  c = a - b;
  while (c >= b) {
    c = c - b;
  }

  return c;
}
