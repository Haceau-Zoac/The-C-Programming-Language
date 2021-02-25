#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
  printf("x:00000011 output:%d\n", bitcount(3));
  printf("x:10010100 output:%d\n", bitcount(148));
}

int bitcount(unsigned x)
{
  int count = 0;
  for (; x != 0; ++count)
    x &= (x - 1);
  return count;
}