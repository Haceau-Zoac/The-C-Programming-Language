#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getfloat(float* n);
int getch(void);
void ungetch(int c);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
  float n = 0;
  while (getfloat(&n) != EOF)
    printf("%f", n);

  return 0;
}

int getfloat(float* n)
{
  int c;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
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
  for (*n = 0.0; isdigit(c); c = getch())
    *n = 10.0 * *n + (c - '0');
  if (c == '.')
  {
    c = getch();
    if (!isdigit(c))
    {
      ungetch('.');
      ungetch(c);
    }
    else
    {
      int power = 1;
      for (; isdigit(c); c = getch())
      {
        *n = 10.0 * *n + (c - '0');
        power *= 10;
      }
      *n /= power;
    }
  }
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