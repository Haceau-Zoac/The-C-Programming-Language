#include <stdio.h>

int main(void)
{
  // warning: unknown escape sequence '\c' [-Wunknown-escape-sequence]
  printf("hello,\c world\n");
  // printf("hello,c world\n");
}

/* 
  Output: 
  hello,c world
*/