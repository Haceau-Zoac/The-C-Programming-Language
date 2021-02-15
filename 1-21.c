#include <stdio.h>

#define MAXLINE 1024
#define N 4

void replace_spaces_to_tab(char s[], int n);
void replace_spaces(char s[], int n);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) != 0)
  {
    replace_spaces(s, N);
    printf("%s", s);
  }

  return 0;
}

void replace_spaces_to_tab(char s[], int n)
{
  s[0] = '\t';
  for (int i = 1; s[n + i - 1] != '\0'; ++i)
    s[i] = s[n + i - 1];
}

void replace_spaces(char s[], int n)
{
  for (int i = 0; s[i] != '\0'; ++i)
    if (s[i] == ' ')
    {
      int count;
      for (count = 0; s[i] == ' ' && ++count; ++i)
        if (count % n == 0)
          replace_spaces_to_tab(s + i - n + 1, n);
      i = i - count + 1;
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