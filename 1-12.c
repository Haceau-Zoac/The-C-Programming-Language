#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
  int c, state = OUT;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (state != OUT)
        putchar('\n');
      state = OUT;
    }
    else
    {
      putchar(c);
      if (state == OUT)
        state = IN;
    }
  }

  return 0;
}