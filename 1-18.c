#include <stdio.h>
#define MAXLINE 1000

int full_space(char s[]);
void remove_end_space(char s[]);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) > 0)
  {
    if (!full_space(s))
    {
      remove_end_space(s);
      printf("%s", s);
    }
  }

  return 0;
}

int full_space(char s[])
{
  int i;
  for (i = 0; s[i] == ' ' || s[i] == '\t'; ++i)
    ;
  return s[i] == '\0';
}

void remove_end_space(char s[])
{
  int len = 0;
  while (s[len] != '\0')
    ++len;
  while (len --> 0 && (s[len] == ' ' || s[len] == '\t'))
    s[len] = '\0';
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