#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void reverse(char s[]);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) > 0)
  {
    reverse(s);
    printf("%s", s);
  }

  return 0;
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

void reverse(char s[])
{
  int len = 0;
  while (s[len] != '\0')
    ++len;

  for (int i = 0; i < len; ++i, --len)
  {
    char tmp = s[i];
    s[i] = s[len];
    s[len] = tmp;
  }
}