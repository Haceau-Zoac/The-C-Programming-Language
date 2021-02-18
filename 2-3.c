#include <ctype.h>
#include <stdio.h>

int htoi(char s[]);

int main(void)
{
  printf("0x1 = %d\n", htoi("0x1"));
  printf("0x01 = %d\n", htoi("0x01"));
  printf("0x11 = %d\n", htoi("0x11"));
  printf("0x31B = %d\n", htoi("0x31B"));
  printf("0X154 = %d\n", htoi("0X154"));
  printf("0x9A = %d\n", htoi("0x9A"));

  return 0;
}

int htoi(char s[])
{
  if (s[0] != '0' || (tolower(s[1]) != 'x'))
    return 0;
  
  int ret = 0;
  for (int i = 2; s[i] != '\0'; ++i)
      ret = (ret * 16) + (isdigit(s[i])
              ? (s[i] - '0')
              : (tolower(s[i]) - 'a' + 10));

  return ret;
}