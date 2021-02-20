#include <stdio.h>

char lower(char c);

int main(void)
{
  printf("c:A output:%c\n", lower('A'));
  printf("c:w output:%c\n", lower('w'));
  printf("c:G output:%c\n", lower('G'));

  return 0;
}

char lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}