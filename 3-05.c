#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
  char s[64];
  itob(100, s, 10);
  printf("n:100 s:%s b:10\n", s);
  
  itob(100, s, 16);
  printf("n:100 s:%s b:16\n", s);

  itob(512, s, 32);
  printf("n:512 s:%s b:32\n", s);

  itob(328, s, 13);
  printf("n:328 s:%s b:13\n", s);

  return 0;
}

void itob(int n, char s[], int b)
{
  int sign = n, i = 0;
  if (n < 0)
  {
    n = -(n + 1);
    s[i++] = "0123456789abcdefghijklmnopqrstuvwxyz"[n % b + 1];
    n /= b;
  }
  do s[i++] = "0123456789abcdefghijklmnopqrstuvwxyz"[n % b];
  while ((n /= b) > 0);
  if (sign < 0)
    s[i++] = '-';
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