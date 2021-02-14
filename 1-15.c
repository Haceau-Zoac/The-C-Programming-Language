#include <stdio.h>

double fahr_to_celsius(double fahr);

int main(void)
{
  // puts("Fahrenheit-Celsius table");
  printf("Fahrenheit-Celsius table\n");

  float fahr;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
    fahr = fahr + step;
  }
}

double fahr_to_celsius(double fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}