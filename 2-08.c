#include <stdio.h>
#include <limits.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
  printf("x:0011 n:2 output:%d\n", rightrot(3, 2));
  printf("x:0101 n:1 output:%d\n", rightrot(5, 1));

  return 0;
}

unsigned rightrot(unsigned x, int n)
{
  return (x << n) | (x >> (CHAR_BIT * sizeof(unsigned) - n));
}