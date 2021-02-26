#include <stdio.h>
#include "check.h"

#define isupper(c) ((c) >= 'A' && (c) <= 'Z')

int main(void)
{
  printf("%c | c:a | output:%d\n", istrue(!isupper('a')), isupper('a'));
  printf("%c | c:B | output:%d\n", istrue( isupper('B')), isupper('B'));
  printf("%c | c:Z | output:%d\n", istrue( isupper('Z')), isupper('Z'));
  printf("%c | c:h | output:%d\n", istrue(!isupper('h')), isupper('h'));
  printf("%c | c:( | output:%d\n", istrue(!isupper('(')), isupper('('));

  return 0;
}