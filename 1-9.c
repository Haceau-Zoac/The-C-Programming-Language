#include <stdio.h>

int main(void)
{
  int c = 0;

  while (c != EOF)
  {
    if ((c != ' ' && (c = getchar()) != EOF) ||
        (c == ' ' && (c = getchar()) != ' ' && c != EOF))
      putchar(c);
  }
}