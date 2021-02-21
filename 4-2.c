#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main(void)
{
  printf("s:3.21 output:%lf\n", atof("3.21"));
  printf("s:76.54E-2 output:%lf\n", atof("76.54E-2"));
  printf("s:.32e+6 output:%lf\n", atof(".32e+6"));

  return 0;
}

double atof(char s[])
{
  int i = 0;
  while (isspace(s[i]))
    ++i;
  int sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    ++i;
  double val = 0.0;
  while (isdigit(s[i]))
    val = 10.0 * val + (s[i++] - '0');
  if (s[i] == '.')
    ++i;
  double power = 1.0;
  while (isdigit(s[i]))
  {
    val = 10.0 * val + (s[i++] - '0');
    power /= 10;
  }
  if (tolower(s[i]) == 'e')
  {
    int enumber = 0;
    ++i;
    int esign = s[i] == '-';
    if (s[i] == '-' || s[i] == '+')
      ++i;
    while (isdigit(s[i]))
      enumber = enumber * 10 + (s[i++] - '0');
    while (enumber-- > 0)
      power *= esign ? 0.1 : 10;
  }
  return sign * val * (power == 0 ? 1 : power);
}