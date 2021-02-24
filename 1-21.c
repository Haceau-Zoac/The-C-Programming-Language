#include <stdio.h>

#define MAXLINE 1024
#define N 4

void entab(char s[], int n);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) != 0)
  {
    entab(s, N);
    printf("%s", s);
  }

  return 0;
}

void entab(char s[], int n)
{
  for (int i = 0, sn = 0; s[i] != '\0'; ++i)
  {
    if (s[i] == ' ') ++sn;
    else sn = 0;
    if (sn == n)
    {
      s[i - n + 1] = '\t';
      for (int j = i - n + 2; s[j + n - 1] != '\0'; ++j)
        s[j] = s[j + n - 1];
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