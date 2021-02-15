#include <stdio.h>

#define MAXLINE 1024
#define N 4

void replace_tab(char s[], int n, int maxsize);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) != 0)
  {
    replace_tab(s, N, MAXLINE);
    printf("%s", s);
  }

  return 0;
}

void replace_tab(char s[], int n, int maxsize)
{
  int size = 0;
  while (s[size] != '\0')
    ++size;
  for (int i = 0; i < size; ++i)
  {
    if (s[i] == '\t')
    {
      int j1;
      for (j1 = i; j1 + n * 2 < maxsize && s[j1] != '\0'; ++j1)
        s[j1 + n * 2] = s[j1 + 1];
      int j;
      for (j = i; j < i + n * 2; ++j)
        s[j] = ' ';
      j1 = j1 + n * 2;
      if (j > size || j1 > size)
      {
        size = j > j1 ? j : j1;
        s[size] = '\0';
      }
    }
  }
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