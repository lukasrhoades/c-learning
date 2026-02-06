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
  printf("Fahr Celsius\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%4.0f %7.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  
  return 0;
}
