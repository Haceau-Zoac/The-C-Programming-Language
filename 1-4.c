#include <stdio.h>

int main(void)
{
  puts("Celsius-Fahrenheit table");

  float fahr, celsius;
  float lower, step, upper;

  lower = 0;
  step = 1;
  upper = 150;

  celsius = lower;
  while (celsius <= upper)
  {
    fahr = celsius / (5.0 / 9.0) + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}