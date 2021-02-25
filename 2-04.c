#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
  char s1[] = "hello";
  squeeze(s1, "hlo");
  printf("s1:hello s2:hlo output:%s\n", s1);
  char s2[] = " world!";
  squeeze(s2, " wr");
  printf("s1: world! s2: wr output:%s\n", s2);
}

void squeeze(char s1[], char s2[])
{
  int j = 0;
  for (int i = 0; s1[i] != '\0'; ++i)
  {
    int has = 0;
    for (int k = 0; s2[k] != '\0'; ++k)
      if (s1[i] == s2[k])
      {
        has = 1;
        break;
      }
    if (!has)
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}