#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main(void)
{
  // x:0100   y:0011
  //     ^
  //     p
  printf("x:4 p:1 n:2 y:3 output:%u\n", setbits(4, 1, 2, 3));
  // x:0101   y:1001
  //   ^
  //   p
  printf("x:5 p:3 n:4 y:9 output:%u\n", setbits(5, 3, 4, 9));
  // x:0001 0000   y: 1001
  //        ^
  //        p
  printf("x:16 p:3 n:4 y:9 output:%u\n", setbits(16, 3, 4, 9));
  // x:0001 0001   y: 1011
  //         ^
  //         p
  printf("x:17 p:2 n:1 y:11 output:%u\n", setbits(17, 2, 1, 11));

  return 0;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
  return (x & ((~0 << (p + 1)) | ~(~0 << (p + 1 - n))))
    | ((y & ~(~0 << n)) << (p + 1 - n));
}