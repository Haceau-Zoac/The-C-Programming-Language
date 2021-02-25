#include <stdio.h>

#pragma clang diagnostic push // disable warning "incompatible-library-redeclaration"
#pragma clang diagnostic ignored"-Wincompatible-library-redeclaration"
void strcat(char* s, char* t);
#pragma clang diagnostic pop  // END disable warning "incompatible-library-redeclaration"

int main(void)
{
  char t1[64] = "world!";
  char s1[64] = "hello, ";
  strcat(s1, t1);
  printf("s:hello,  t:world! output/s:%s\n", s1);

  char t2[64] = "abc";
  char s2[64] = "def";
  strcat(s2, t2);
  printf("s:def t:abc output/s:%s\n", s2);

  char t3[64] = "owo";
  char s3[64] = "qwq ";
  strcat(s3, t3);
  printf("s:qwq  t:owo output/s:%s\n", s3);
}

void strcat(char* s, char* t)
{
  while (*s)
    ++s;
/*
  while (*s++ = *t++)
    ;
  WARNING "parentheses"(clang)
*/
  while ((*s++ = *t++) != '\0')
    ;
}