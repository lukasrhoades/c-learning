#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    printf("%d\n", c != EOF); // prints 1s 
  }
  printf("%d\n", c != EOF); // send Ctrl+D to get EOF "0"
  
  return 0;
}
