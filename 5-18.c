#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "5-18-getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXTOKEN];

int main(void)
{
  while (gettoken() != EOF)
  {
    strcpy(datatype, token);

    // https://github.com/Heatwave/The-C-Programming-Language-2nd-Edition/blob/master/chapter-5-pointers-and-arrays/43.dcl-error-handle.c
    if（tokentype != NAME)
    {
      printf("%d is not a valid datatype\n", tokentype);
      continue;
    }
    out[0] = '\0';
    dcl();
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }

  return 0;
}

void dcl(void)
{
  int ns = 0;

  while (gettoken() == '*')
    ++ns;
  dirdcl();
  while (ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void)
{
  int type;

  if (tokentype == '(')
  {
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  }
  else if (tokentype == NAME)
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");
  while ((type = gettoken()) == PARENS || type == BRACKETS)
  {
    if (type == PARENS)
      strcat(out, " function returning");
    else
    {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
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
