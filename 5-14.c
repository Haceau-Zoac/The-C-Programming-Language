#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5-14-alloc.h"

#define MAXLINES 1000
#define MAXLEN   1000

void qsort_(void* v[], int left, int right,
  int (*comp)(void*, void*), int reverse);
int readlines(char* lineptr[], int maxlines);
void writelines(char* lineptr[], int nlines);
int numcmp(char* s1, char* s2);
void swap(void* v[], int i, int j);
int getline(char s[], int lim);

int main(int argc, char* argv[])
{
  char* lineptr[MAXLINES];
  int nlines = 0;
  int numeric = 0, reverse = 0;
  
  while (argc-- > 1 && **++argv == '-')
    while (*++*argv)
      switch (**argv)
      {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        default:
          printf("[WARNING] unknown arguments -%c\n", **argv);
          break;
      }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
  {
    qsort_((void**)lineptr, 0, nlines - 1, numeric
      ? (int (*)(void*, void*))numcmp
      : (int (*)(void*, void*))strcmp, reverse);
    writelines(lineptr, nlines);
    return 0;
  }
  printf("inptr too big\n");
  return 1;
}

void qsort_(void* v[], int left, int right,
  int (*comp)(void*, void*), int reverse)
{
  int i, last;

  if (left >= right)
    return;
  last = left;
  for (i = left + 1; i <= right; ++i)
  {
    int c = (*comp)(v[i], v[left]);
    if (!reverse && c < 0)
      swap(v, ++last, i);
    else if (reverse && c >= 0)
      swap(v, ++last, i);
  }
  swap(v, left, last);
  qsort_(v, left, last - 1, comp, reverse);
  qsort_(v, last + 1, right, comp, reverse);
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

int numcmp(char* s1, char* s2)
{
  double v1 = atof(s1);
  double v2 = atof(s2);
  return v1 - v2;
}

void swap(void* v[], int i, int j)
{
  void* t = v[j];
  v[j] = v[i];
  v[i] = t;
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