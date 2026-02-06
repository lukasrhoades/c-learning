#include <stdio.h>

int main()
{
  /* press Ctrl+D to get 0 */
  printf("Value of expression is %d\n", getchar() != EOF);
}