#include <stdio.h>

int strend(char* s, char* t);

int main(void)
{
  printf("s:hello t:llo output:%d\n", strend("hello", "llo"));
  printf("s:giao  t:ao output:%d\n", strend("giao ", "ao"));
  printf("s:qwq t:qw output:%d\n", strend("qwq", "qw"));
  printf("s:qwq t:wq output:%d\n", strend("qwq", "wq"));
  printf("s:nb t:nb output:%d\n", strend("nb", "nb"));

  return 0;
}

int strend(char* s, char* t)
{
  while (*s)
    while (*s++ == *t && *t++)
      if (!*s)
        return 1;
  return 0;
}