#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024
#define N 4

void entab(char s[], char t[], int n, int end);
int getline(char s[], int lim);

int main(int argc, char* argv[])
{
  char s[MAXLINE * 4];
  char t[MAXLINE];

  int n = N;
  int start = 0, end = -1;
  while (argc-- > 1)
    switch (**++argv)
    {
      case '-':
        start = atoi(*argv);
        break;
      case '+':
        end = atoi(*argv);
        break;
      default:
        n = atoi(*argv);
        break;
    }

  while (getline(t, MAXLINE) != 0)
  {
    entab(s, t, n, (end == -1) ? strlen(t) : end);
    t[start] = '\0';
    printf("%s%s", t, s);
  }

  return 0;
}

void entab(char s[], char t[], int n, int end)
{
  int sc = 0;
  do
    if (*t == ' ' && end > 0)
      ++sc;
    else
    {
      while (end > 0 && sc >= n)
        *s++ = '\t', sc -= n;
      if (sc < n && sc > 0 && end > 0)
        do
          *s++ = ' ';
        while (--sc);
      *s++ = *t;
    }
  while (--end, *t++);
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