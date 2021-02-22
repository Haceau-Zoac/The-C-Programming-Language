#include <stdio.h>

#pragma clang diagnostic push // disable warning "incompatible-library-redeclaration"(clang)
#pragma clang diagnostic ignored"-Wincompatible-library-redeclaration"
char* strncpy(char* s, int ct, char* n);
char* strncat(char* s, int ct, char* n);
int strncmp(char* s, int ct, char* n);
#pragma clang diagnostic pop  // END disable warning "incompatible-library-redeclaration"(clang)

int main(void)
{
  char cpys[64] = "qwq";
  strncpy(cpys, 3, "hello");
  printf("[strncpy] s:qwq ct:3 n:hello output/s:%s\n", cpys);

  char cats[64] = "qwq";
  strncat(cats, 3, "hello");
  printf("[strncat] s:qwq ct:3 n:hello output/s:%s\n", cats);

  char cmps[64] = "qwq";
  printf("[strncmp] s:qwq ct:3 n:hello output:%d\n", strncmp(cmps, 3, "hello"));

  return 0;
}

char* strncpy(char* s, int ct, char* n)
{
  while (ct-- && (*s++ = *n++) != '\0')
    ;
  return n;
}

char* strncat(char* s, int ct, char* n)
{
  while (*s)
    ++s;
  while (ct-- && (*s++ = *n++) != '\0')
    ;
  return n;
}

int strncmp(char* s, int ct, char* n)
{
  while (!(ct--) || *s++ == *n++)
    if (!*s)
      return 0;
  return *s - *n;
}