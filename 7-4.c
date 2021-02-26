#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "7-4-getch.h"

void minscanf(char* fmt, ...);

void minscanf(char* fmt, ...)
{
  va_list ap;
  char buf[1024];
  char* p, * bufp = buf;
  
  va_start(ap, fmt);
  for (p = fmt; *p; ++p)
  {
    if (*p != '%')
    {
      if (getchar() != *p)
        break;
      continue;
    }
    switch (*++p)
    {
    case 'd':
      while (isdigit(*bufp++ = getch()))
        ;
      ungetch(*bufp);
      *bufp = '\0';
      *va_arg(ap, int*) = atoi(bufp);
      bufp = buf;
      break;
    case 'f':
      while (isdigit(*bufp++ = getchar()))
        ;
      if (*bufp == '.')
        while (isdigit(*++bufp = getchar()))
          ;
      ungetch(*bufp);
      *bufp = '\0';
      *va_arg(ap, double*) = atof(bufp);
      bufp = buf;
      break;
    case 's':
      bufp = va_arg(ap, char*);
      while (!isspace(*bufp++ = getchar()))
        ;
      ungetch(*bufp);
      *bufp = '\0';
      bufp = buf;
      break;
    }
  }
  va_end(ap);
}