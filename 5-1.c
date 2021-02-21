#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getint(int* n);
int getch(void);
void ungetch(int c);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
  int n = 0;
  while (getint(&n) != EOF)
    printf("%d", n);

  return 0;
}

int getint(int* n)
{
  int c;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
  {
    ungetch(c);
    return 0;
  }
  int sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c))
  {
    ungetch((sign == -1) ? '-' : '+');
    ungetch(c);
    return 0;
  }
  for (*n = 0; isdigit(c); c = getch())
    *n = 10 * *n + (c - '0');
  *n *= sign;
  ungetch(c);
  return c;
}

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else if (c != EOF)
    buf[bufp++] = c;
}