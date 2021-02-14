#include <stdio.h>
#define CRITICAL 80

int main(void)
{
  int c, i = 0;
  char s[82];

  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
      i = 0;
    if (i <= CRITICAL)
      s[i++] = c;
    else if (i == CRITICAL + 1)
    {
      s[i++] = '\0';
      printf("%s", s);
    }
    else
      putchar(c);
  }

  return 0;
}