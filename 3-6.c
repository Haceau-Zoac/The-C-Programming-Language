#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[], int l);
void reverse(char s[]);

int main(void)
{
  char s[32];
  itoa(INT_MIN, s, 32);
  printf("n:%d s:%s l:32\n", INT_MIN, s);

  itoa(3456, s, 2);
  printf("n:%d s:%s l:2\n", 3456, s);

  return 0;
}

void itoa(int n, char s[], int l)
{
  int sign = n, i = 0;
  if (n < 0)
  {
    n = -(n + 1);
    s[i++] = n % 10 + '1';
    n /= 10;
  }
  do s[i++] = n % 10 + '0';
  while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  for (; i < l; ++i)
    s[i] = ' ';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
{
  int len = 0;
  while (s[len + 1] != '\0')
    ++len;

  for (int i = 0; i < len; ++i, --len)
  {
    char tmp = s[i];
    s[i] = s[len];
    s[len] = tmp;
  }
}