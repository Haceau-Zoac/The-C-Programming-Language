#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int up = isupper(argv[0][2]);
  int c = 0;

  while ((c = getchar()) != EOF)
    putchar(up ? toupper(c) : tolower(c));
  return 0;
}
