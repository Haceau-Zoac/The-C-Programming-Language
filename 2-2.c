#include <stdio.h>

int main(void)
{
  int i = 0;
  int c = 0;

  // i < lim-1 && (c = getchar()) != '\n' && c != EOF
  if (i < lim - 1)
    if ((c = getchar()) != '\n')
      if (c != EOF)
        ;

  return 0;
}