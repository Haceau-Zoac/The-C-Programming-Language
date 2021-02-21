#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_(char s[], int i, int j);

int main(void)
{
  char s[] = "hello, world!";
  reverse(s);
  printf("s:hello, world! output:%s", s);
  return 0;
}

void reverse(char s[])
{
  reverse_(s, 0, strlen(s) - 1);
}

void reverse_(char s[], int i, int j)
{
  if (i >= j)
    return;
  char t = s[i];
  s[i] = s[j];
  s[j] = t;
  reverse_(s, i + 1, j - 1);
}