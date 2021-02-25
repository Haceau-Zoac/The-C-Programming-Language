#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5-13-alloc.h"

#define MAXLINES 1000
#define MAXLEN   1000
#define N        10

int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
int getline(char s[], int lim);

int main(int argc, char* argv[])
{
  char* lineptr[MAXLINES];
  int n = (argc > 1) ? atoi(*++argv) : N;
  if (n <= 0)
    return 0;
  
  int nlines = 0;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    int lines = nlines - (n > nlines ? 0 : n);
    writelines(lineptr + lines, (n > nlines ? nlines : n));
  }
  else
  {
    printf("inptr too big\n");
    return 1;
  }

  return 0;
}

int readlines(char* lineptr[], int maxlines)
{
  int len, nlines = 0;
  char* p, line[MAXLEN];

  while ((len = getline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else
    {
      line[len - 1] = '\0';
#pragma clang diagnostic push // disable warning "deprecated-declarations"(clang)
#pragma clang diagnostic ignored"-Wdeprecated-declarations"
      strcpy(p, line);
#pragma clang diagnostic push // END disable warning "deprecated-declarations"(clang)
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char* lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

int getline(char s[], int lim)
{
  int i, c;
  for (i = 0;
       i < lim - 1 && (c = getchar()) != EOF && c != '\n';
       ++i)
      s[i] = c;

  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  
  return i;
}