#include <stdio.h>

#define MAXLINE 1024
#define N 30

void breaks(char s[], int n);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) > 0)
  {
    breaks(s, N);
    printf("%s", s);
  }

  return 0;
}

void breaks(char s[], int n)
{
  for (int i = 0; s[i] != '\0'; ++i)
  {
    if (i % n + 1 == n)
    {
      for (int j = i; j > 0; --j)
      {
        if ((s[j] != ' ' && s[j] != '\t') &&
            (s[j + 1] == ' ' || s[j + 1] == '\t'))
        {
          int k;
          for (k = j + 2; k == ' ' || k == '\t'; ++k)
            ;
          s[k - 1] = '\n';
          break;
        }
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