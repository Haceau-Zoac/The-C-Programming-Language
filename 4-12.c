#include <stdio.h>

int itoa(char s[], int i);

int main(void)
{
  char s[64];
  int ret = itoa(s, 12);
  printf("s:%s i:12 output:%d\n", s, ret);
  ret = itoa(s, -642);
  printf("s:%s i:-642 output:%d\n", s, ret);
  return 0;
}

int itoa(char s[], int i)
{ 
  // 无法处理 INT_MIN
  int ix = 0;
  if (i < 0)
  {
    s[ix++] = '-';
    i = -i;
  }
  if (i / 10)
    ix += itoa(s + ix, i / 10);
  s[ix++] = i % 10 + '0';
  s[ix] = '\0';
  return ix;
}