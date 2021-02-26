#ifndef _7_4_GETCH_H
#define _7_4_GETCH_H

#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

static char buf[BUFSIZE];
static int bufp = 0;

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
#endif // _7_4_GETCH_H