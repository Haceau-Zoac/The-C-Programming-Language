#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main(void)
{
  printf("s:hello t:ll output:%d\n", strindex("hello", "ll"));
  printf("s:what's this? t:'s output:%d\n", strindex("what's this?", "'s"));
  printf("s:morning t:or output:%d\n", strindex("morning", "or"));
  printf("s:not found t:ddd output:%d\n", strindex("not found", "ddd"));

  return 0;
}

int strindex(char s[], char t[])
{
  int tlen = strlen(t) - 1;
  for (int i = strlen(s) - 1, pos = 0; i >= 0; --i, ++pos)
  {
    int k = tlen;
    for (; k >= 0 && s[i] == t[k]; --i, --k, ++pos)
      ;
    if (k < 0)
      return pos;
  }

  return -1;
}