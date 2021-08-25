#include <time.h>
#include <stdio.h>
#include <string.h>
#include "5-07-alloc.h"

#define MAXLINES 5000
#define MAXLEN   1000

char* lineptr[MAXLINES];

int readlines(char* lineptr[], int maxlines);
int readlines_after(void);
int getline(char* s, int lim);

int main(void)
{
  readlines(lineptr, MAXLINES); // 热身
  readlines_after();            // 热身
  clock_t t = clock();
  readlines(lineptr, MAXLINES);
  t = clock() - t;
  printf("time: %ldms", t);
  t = clock();
  readlines_after();
  t = clock() - t;
  printf("time: %ldms", t);

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

int readlines_after(void)
{
  int len, nlines = 0;
  char* p, line[MAXLEN];

  while ((len = getline(line, MAXLEN)) > 0)
  {
    if (nlines >= MAXLINES || (p = alloc(len)) == NULL)
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

int getline(char* s, int lim)
{
  int i = 0;
  while (i++ < lim && (*s = getchar()) != EOF && *s++ != '\n')
    ;
  *s = '\0';
  
  return i - 1;
}