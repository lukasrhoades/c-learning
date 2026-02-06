#include <stdio.h>

/* print Fahrenheit-celsius table
    for Fahr = 0, 20, ..., 300; floating-point version */
int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;    /* lower limit of temperature scale */
  upper = 300;  /* upper limit */
  step = 20;    /* step size */

  printf("Temperatures\n");
  printf("Cels  Fahr\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius*(9.0/5.0) + 32.0;
    printf("%4.0f %5.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  
  return 0;
}
