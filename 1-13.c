#include <stdio.h>

int main(void)
{
  int c, nwhite = 0, nother = 0, ndigit[10] = { 0 };

  while ((c = getchar()) != EOF)
  {
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }

  for (int i = 0; i < 10; ++i)
  {
    printf("%d          ", i);
    for (int j = 0; j < ndigit[i]; ++j)
      putchar('-');
    putchar('\n');
  }
  printf("white space ");
  for (int i = 0; i < nwhite; ++i)
    putchar('-');
  putchar('\n');
  printf("other       ");
  for (int i = 0; i < nother; ++i)
    putchar('-');
  putchar('\n');

  return 0;
}