#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
  // x: 0001 0000
  //         p
  printf("x:16 p:3 n:2 output:%u\n", invert(16, 3, 2));
  // x: 0001 0001
  //          p
  printf("x:17 p:2 n:1 output:%u\n", invert(17, 2, 1));
  // x: 0010 0000
  //      p
  printf("x:32 p:5 n:3 output:%u\n", invert(32, 5, 3));

  return 0;
}

unsigned invert(unsigned x, int p, int n)
{
  return x ^ (~(~0 << n) << (p + 1 - n));
}