#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024
#define N 4

void entab(char s[], char t[], int n);
int getline(char s[], int lim);

int main(int argc, char* argv[])
{
  char s[MAXLINE * 4];
  char t[MAXLINE];

  int n = (argc > 1) ? atoi(*++argv) : N;

  while (getline(t, MAXLINE) != 0)
  {
    entab(s, t, n);
    printf("%s", s);
  }

  return 0;
}

void entab(char s[], char t[], int n)
{
  int sc = 0;
  do
    if (*t == ' ')
      ++sc;
    else
    {
      while (sc >= n)
        *s++ = '\t', sc -= n;
      if (sc < n && sc > 0)
        do
          *s++ = ' ';
        while (--sc);
      *s++ = *t;
    }
  while (*t++);
  *++s = '\0';
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