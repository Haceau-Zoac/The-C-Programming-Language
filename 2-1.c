#include <stdio.h>
#include <limits.h>

void print_limits(void);
void print_calculate_limits(void);

int main(void)
{
  print_limits();
  puts("----------------------------------------------");
  print_calculate_limits();

  return 0;
}

void print_limits(void)
{
  printf("signed char: %d ~ %d\n", CHAR_MIN, CHAR_MAX);
  printf("unsigned char: %d ~ %u\n", 0, UCHAR_MAX);
  printf("signed short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short: %d ~ %u\n", 0, USHRT_MAX);
  printf("signed int: %d ~ %d\n", INT_MIN, INT_MAX);
  printf("unsigned int: %d ~ %u\n", 0, UINT_MAX);
  printf("signed long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long: %d ~ %lu\n", 0, ULONG_MAX);
}

void print_calculate_limits(void)
{
  signed char sc = 0;
  signed short ss = 0;
  signed int si = 0;
  signed long sl = 0;
  for (; sc >= 0; ++sc);
  for (; ss >= 0; ++ss);
  for (; si >= 0; ++si);
  for (; sl >= 0; ++sl);

  printf("signed char: %d ~ %d\n", sc, (signed char)(sc - 1));
  printf("unsigned char: %d ~ %u\n", 0, (unsigned char)0 - 1);
  printf("signed short: %d ~ %d\n", ss, (signed short)(ss - 1));
  printf("unsigned short: %d ~ %u\n", 0, (unsigned short)0 - 1);
  printf("signed int: %d ~ %d\n", si, si - 1);
  printf("unsigned int: %d ~ %u\n", 0, (unsigned int)0 - 1);
  printf("signed long: %ld ~ %ld\n", sl, sl - 1);
  printf("unsigned long: %d ~ %lu\n", 0, (unsigned long)0 - 1);
}