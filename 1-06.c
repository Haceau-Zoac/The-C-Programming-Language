#include <stdio.h>

int main(void)
{
  int i;
  while (1)
    printf("%d", (i = getchar()) != EOF);
}