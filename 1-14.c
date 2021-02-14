#include <stdio.h>

int main(void)
{
  int nchar[52] = { 0 }, c;

  while ((c = getchar()) != EOF)
  {
    if (c >= 'a' && c <= 'z')
      ++nchar[c - 'a'];
    else if (c >= 'A' && c <= 'Z')
      ++nchar[c - 'A' + 26];
  }

  for (int i = 0; i < 52; ++i)
  {
    if (i < 26)
      putchar('a' + i);
    else
      putchar('A' + i - 26);
    putchar(' ');
    for (int j = 0; j < nchar[i]; ++j)
      putchar('-');
    putchar('\n');
  }

  return 0;
}