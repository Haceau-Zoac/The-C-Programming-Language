#include <stdio.h>

int main(void)
{
  int c, space = 0, tab = 0, new_line = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      ++space;
    else if (c == '\t')
      ++tab;
    else if (c == '\n')
      ++new_line;
  }

  printf("space: %d\ntab: %d\newLine: %d\n", space, tab, new_line);
}