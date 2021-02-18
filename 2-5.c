#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
  printf("s1:hello s2:l output:%d\n", any("hello", "l"));
  printf("s1:testing s2:ok output:%d\n", any("testing", "ok"));
  printf("s1:666 s2:6.7 output:%d\n", any("666", "6.7"));

  return 0;
}

int any(char s1[], char s2[])
{
  for (int i = 0; s1[i] != '\0'; ++i)
  {
    int has = 0;
    for (int j = 0; s2[j] != '\0'; ++j)
      if (s2[j] == s1[i])
      {
        has = 1;
        break;
      }
    if (has)
      return i;
  }
  return -1;
}