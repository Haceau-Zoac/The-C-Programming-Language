#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define BUFSIZE 100
#define NUMBER '0'

#define TEST(type, func, param, format, print, true)  \
  type ## ret = func(param);                          \
  printf("[" # func "] %c "format, (type ## ret == true) ? 'V' : 'X', print)

#define TEST2(type, func, param1, param2, format, print, true)  \
  type ## ret = func(param1, param2);                           \
  printf("[" # func "] %c "format, (type ## ret == true) ? 'V' : 'X', print)

#pragma clang diagnostic push // disable warning "incompatible-library-redeclaration"(clang)
#pragma clang diagnostic ignored"-Wincompatible-library-redeclaration"
int getline(char* line, int maxline);
int htoi(char* s);
void itoa(int n, char* s);
void itob(int n, char* s, int b);
int atoi_(char* s); // dublicate name with library function
double atof(char* s);
void reverse(char* s);
int strindex(char* s, char* t);
int getop(char* s);
#pragma clang diagnostic pop  // END disable warning "incompatible-library-redeclaration"(clang)

int main(void)
{
  int iret;
  TEST(i, htoi, "0x1", "0x1 = %d\n", iret, 0x1);
  TEST(i, htoi, "0x01", "0x01 = %d\n", iret, 0x01);
  TEST(i, htoi, "0x11", "0x11 = %d\n", iret, 0x11);
  TEST(i, htoi, "0x31B", "0x31B = %d\n", iret, 0x31B);
  TEST(i, htoi, "0X154", "0X154 = %d\n", iret, 0X154);
  TEST(i, htoi, "0x9A", "0x9A = %d\n\n", iret, 0x9A);

  char getlines[MAXLINE];
  iret = getline(getlines, MAXLINE);
  printf("[getline] ? s:%s lim:1000 output:%d\n\n", getlines, iret);

  char itoas[32];
  
  itoa(INT_MIN, itoas);
  printf("[itoa] %c n:%d s:%s\n", strcmp(itoas, "-2147483648") == 0 ? 'V' : 'F', INT_MIN, itoas);
  itoa(3456, itoas);
  printf("[itoa] %c n:%d s:%s\n\n", strcmp(itoas, "3456") == 0 ? 'V' : 'F', 3456, itoas);

  char itobs[64];
  itob(100, itobs, 10);
  printf("[itob] %c n:100 s:%s b:10\n", strcmp(itobs, "100") == 0 ? 'V' : 'F', itobs);
  itob(100, itobs, 16);
  printf("[itob] %c n:100 s:%s b:16\n", strcmp(itobs, "64") == 0 ? 'V' : 'F', itobs);
  itob(512, itobs, 32);
  printf("[itob] %c n:512 s:%s b:32\n", strcmp(itobs, "g0") == 0 ? 'V' : 'F', itobs);
  itob(328, itobs, 13);
  printf("[itob] %c n:328 s:%s b:13\n\n", strcmp(itobs, "1c3") == 0 ? 'V' : 'F', itobs);

  printf("[atof] ? s:3.21 output:%lf\n", atof("3.21"));
  printf("[atof] ? s:76.54E-2 output:%lf\n", atof("76.54E-2"));
  printf("[atof] ? s:.32e+6 output:%lf\n\n", atof(".32e+6"));

  TEST(i, atoi_, "+3", "s:+3 output:%d\n", iret, +3);
  TEST(i, atoi_, "-76", "s:-76 output:%d\n", iret, -76);
  TEST(i, atoi_, "114514", "s:114514 output:%d\n", iret, 114514);

  TEST2(i, strindex, "hello", "ll", "s:hello t:ll output:%d\n", iret, 3);
  TEST2(i, strindex, "what's this?", "'s", "s:what's this? t:'s output:%d\n", iret, 8);
  TEST2(i, strindex, "morning", "or", "s:morning t:or output:%d\n", iret, 6);
  TEST2(i, strindex, "not found", "ddd", "s:not found t:ddd output:%d\n", iret, -1);

  char reverses[] = "hello, world!";
  reverse(reverses);
  printf("[reverse] %c s:hello, world! output:%s\n\n", strcmp(reverses, "!dlrow ,olleh") == 0 ? 'V' : 'F', reverses);

  char getops[1000];
  char cret = getop(getops);
  printf("[getop] ? s:%s output:%c\n\n", getops, cret);
}

int getline(char* s, int lim)
{
  int i = 0;
  while (i++ < lim && (*s = getchar()) != EOF && *s++ != '\n')
    ;
  *s = '\0';
  
  return i;
}

int htoi(char* s)
{
  if (*s++ != '0' || (tolower(*s) != 'x'))
    return 0;
  
  int ret = 0;
  while (*++s)
    ret = (ret * 16) + (isdigit(*s)
            ? (*s - '0')
            : (tolower(*s) - 'a' + 10));

  return ret;
}

void itoa(int n, char* s)
{
  char* ds = s;
  int sign = n;
  if (n < 0)
  {
    n = -(n + 1);
    *s++ = n % 10 + '1';
    n /= 10;
  }
  do *s++ = n % 10 + '0';
  while ((n /= 10) > 0);
  if (sign < 0)
    *s++ = '-';
  *s = '\0';
  reverse(ds);
}

void itob(int n, char* s, int b)
{
  char* ds = s;
  int sign = n;
  if (n < 0)
  {
    n = -(n + 1);
    *s++ = "0123456789abcdefghijklmnopqrstuvwxyz"[n % b + 1];
    n /= b;
  }
  do *s++ = "0123456789abcdefghijklmnopqrstuvwxyz"[n % b];
  while ((n /= b) > 0);
  if (sign < 0)
    *s++ = '-';
  *s = '\0';
  reverse(ds);
}

int atoi_(char* s)
{
  while (isspace(*s++))
    ;
  int sign = (*--s == '-') ? -1 : 1;
  if (*s == '-' || *s == '+')
    ++s;
  int val = 0;
  while (isdigit(*s))
    val = val * 10 + (*s++ - '0');
  return sign * val;
}

double atof(char* s)
{
  while (isspace(*s++))
    ;
  int sign = (*--s == '-') ? -1 : 1;
  if (*s == '-' || *s == '+')
    ++s;
  double val = 0.0;
  while (isdigit(*s))
    val = 10.0 * val + (*s++ - '0');
  if (*s == '.')
    ++s;
  double power = 1.0;
  while (isdigit(*s))
  {
    val = 10.0 * val + (*s++ - '0');
    power /= 10;
  }
  if (tolower(*s) == 'e')
  {
    int enumber = 0;
    ++s;
    int esign = *s == '-';
    if (*s == '-' || *s == '+')
      ++s;
    while (isdigit(*s))
      enumber = enumber * 10 + (*s++ - '0');
    while (enumber-- > 0)
      power *= esign ? 0.1 : 10;
  }
  return sign * val * (power == 0 ? 1 : power);
}

void reverse(char* s)
{
  char* es = s;
  while (*++es)
    ;

  // printf("DEBUG: es - s = %d, s: %s\n", es - s, s);
  while (es - s > 0)
  {
    char tmp = *s;
    *s++ = *--es;
    *es = tmp;
    // printf("DEBUG: es - s = %d, s: %s\n", es - s, s);
  }
}

int strindex(char* s, char* t)
{
  int sl = 0;
  while (*++s)
    ++sl;
  while (*++t)
    ;

  for (int pos = 0; sl > 0; --sl, ++pos)
  {
    char* tt = t;
    while (*--s == *--tt && *tt)
      ++pos;
    if (!*tt)
      return pos;
  }

  return -1;
}

int getop(char* s)
{
  int c;
  static char buf[BUFSIZE];
  static int bufp = 0;
  while ((*s++ = c = (bufp > 0 ? buf[--bufp] : getchar())) == ' ' || c == '\t')
    ;
  *s = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  if (isdigit(c))
    while (isdigit(*s++ = c = (bufp > 0 ? buf[--bufp] : getchar())))
      ;
  if (c == '.')
    while (isdigit(*s++ = c = (bufp > 0 ? buf[--bufp] : getchar())))
      ;
  *s = '\0';
  if (c != EOF)
    buf[bufp++] = c;
  return NUMBER;
}