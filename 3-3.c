#include <ctype.h>
#include <stdio.h>

void expand(char s1[], char s2[]);
int sameclass(char ch1, char ch2);

int main(void)
{
  char si1[] = "0-9 是十进制数字。";
  char so1[128];
  expand(si1, so1);
  printf("s1:%s s2:%s\n", si1, so1);

  char si2[] = "a-zA-Z0-9";
  char so2[128];
  expand(si2, so2);
  printf("s1:%s s2:%s\n", si2, so2);

  char si3[] = "-a-z-A-Z-9-0-";
  char so3[128];
  expand(si3, so3);
  printf("s1:%s s2:%s\n", si3, so3);
  
  // 下面这个没力气改了(
  char si4[] = "-a-z-a-z-a-z-awa";
  char so4[128];
  expand(si4, so4);
  printf("s1:%s s2:%s\n", si4, so4);

  return 0;
}

void expand(char s1[], char s2[])
{
  int j = 0;
  for (int i = 0; s1[i] != '\0'; ++i)
  {
    if ((i > 0)
      && (s1[i + 1] != '\0')
      && (s1[i] == '-')
      && sameclass(s1[i - 1], s1[i + 1])
      && (i < 3 || s1[i - 2] != '-' || !sameclass(s1[i - 3], s1[i - 1])))
    {
      --j;
      int order = s1[i - 1] > s1[i + 1];
      for (int k = s1[i - 1];
            order ? (k > s1[i + 1]) : (k < s1[i + 1]); order ? --k : ++k)
        s2[j++] = k;
    }
    else
      s2[j++] = s1[i];
  }
  s2[j] = '\0';
}

int sameclass(char ch1, char ch2)
{
  return (isdigit(ch1) && isdigit(ch2))
      || (isupper(ch1) && isupper(ch2))
      || (islower(ch1) && islower(ch2));
}