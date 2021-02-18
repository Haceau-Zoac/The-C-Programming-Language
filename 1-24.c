#include <stdio.h>

#define MAXLINE 1024
#define ERR_PT  1 // Parentheses ()
#define ERR_BT  2 // Bracket     []
#define ERR_B   4 // Brace       {}
#define ERR_STR 8 // String      ""
#define ERR_CH 16 // Character   ''
#define IN_STR  1
#define IN_CH   3

void print_errors(int err);
int check(char s[]);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) != 0)
    print_errors(check(s));

  return 0;
}

void print_errors(int err)
{
  if (err & ERR_PT)
    puts("Parentheses Error.");
  if (err & ERR_BT)
    puts("Bracket Error.");
  if (err & ERR_B)
    puts("Brace Error.");
  if (err & ERR_STR)
    puts("String Error.");
  if (err & ERR_CH)
    puts("Character Error.");
}

int check(char s[])
{
  int err = 0;
  char stack[MAXLINE];
  int pos = 0;
  int in_str_ch = 0;
  for (int i = 0; s[i] != '\0'; ++i)
  {
    switch (s[i])
    {
      case '\'':
        if (in_str_ch == IN_CH)
        {
          if (stack[--pos] != '\'')
            err |= ERR_CH;
          in_str_ch = 0;
        }
        else if (in_str_ch != IN_STR)
        {
          stack[pos++] = '\'';
          in_str_ch = IN_CH;
        }
        break;
      case '"':
        if (in_str_ch == IN_STR)
        {
          if (stack[--pos] != '"')
            err |= ERR_STR;
          in_str_ch = 0;
        }
        else if (in_str_ch != IN_CH)
        {
          stack[pos++] = '"';
          in_str_ch = IN_STR;
        }
        break;
      case '(':
        stack[pos++] = '(';
        break;
      case '[':
        stack[pos++] = '[';
        break;
      case '{':
        stack[pos++] = '{';
        break;
      case ')':
        if (stack[--pos] != '(')
          err |= ERR_PT;
        break;
      case ']':
        if (stack[--pos] != '[')
          err |= ERR_BT;
        break;
      case '}':
        if (stack[--pos] != '{')
          err |= ERR_B;
        break;
      default:
        break;
    }
  }
  for (int i = pos - 1; i >= 0; --i)
  {
    switch (stack[i])
    {
      case '\'':
        err |= ERR_CH;
        break;
      case '"':
        err |= ERR_STR;
        break;
      case '(':
        err |= ERR_PT;
        break;
      case '[':
        err |= ERR_BT;
        break;
      case '{':
        err |= ERR_B;
        break;
    }
  }
  return err;
}

int getline(char s[], int lim)
{
  int i, c;

  for (i = 0;
       i < lim - 1 && (c = getchar()) != EOF && c != '\n';
       ++i)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  
  return i;
}