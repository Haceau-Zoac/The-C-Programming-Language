#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "5-18-getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXTOKEN];

int main(void)
{
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF)
  {
    strcpy(out, token);
    while ((type = gettoken()) != '\n')
      // https://github.com/Heatwave/The-C-Programming-Language-2nd-Edition/blob/master/chapter-5-pointers-and-arrays/44.undcl.c
      if (type == PARENS)
      {
        if (out[0] == '*')
        {
          sprintf(temp, "(%s)", out);
          strcpy(out, temp);
        }
        strcat(out, token);
      }
      else if (type == BRACKETS)
      {
        if (out[0] == '*' || strstr(out, "()") != NULL)
        {
          sprintf(temp, "(%s)", out);
          strcpy(out, temp);
        }
        strcat(out, token);
      }
      else if (type == '*')
      {
        sprintf(temp, "*%s", out);
        strcpy(out, temp);
      }
      else if (type == NAME)
      {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      }
      else
        printf("invalid input at %s\n", token);
    printf("%s\n", out);
  }

  return 0;
}

int gettoken(void)
{
  int c;
  char* p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(')
  {
    if ((c = getch()) == ')')
    {
      strcpy(token, "()");
      return tokentype = PARENS;
    }
    else
    {
      ungetch(c);
      return tokentype = '(';
    }
  }
  else if (c == '[')
  {
    for (*p++ = c; (*p++ = getch()) != ']';)
      ;
    return tokentype = BRACKETS;
  }
  else if (isalpha(c))
  {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  }
  else
    return tokentype = c;
}
