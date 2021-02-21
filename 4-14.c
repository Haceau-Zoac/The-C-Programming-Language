#include <stdio.h>

#define swap(t, x, y) \
  t __tmp = x;        \
  x = y;              \
  y = __tmp;          \

int main(void)
{
  int a = 12, b = 23;
  swap(int, a, b);

  printf("a:12 b:23 output/a:%d output/b:%d\n", a, b);

  return 0;
}