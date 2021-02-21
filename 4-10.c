#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> // atof

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define VAR 'v'
#define SIN 's'
#define EXP 'e'
#define POW 'p'
#define GETV 'g'

int getop(char s[]);
void push(double f);
double pop(void);
double setvar(double val, char var);
double getvar(char var);
int getline(char s[], int lim);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
double vars[26];
double last = 0;

int main(void)
{
  int type;
  char s[MAXOP];

  while (getline(buf, BUFSIZE) != EOF &&
        (type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
    {
      double op2 = pop();
      push(pop() - op2);
    }
      break;
    case '/':
    {
      double op2 = pop();
      if (op2 == 0)
        printf("error: zero divisor\n");
      else
        push(pop() / op2);
    }
      break;
    case '%':
    {
      int op2 = pop();
      if (op2 == 0)
        printf("error: zero mod\n");
      else
        push((int)pop() % op2);
    }
      break;
    case '=':
      push(setvar(pop(), pop()));
      break;
    case GETV:
      push(getvar(pop()));
      break;
    case SIN:
      push(sin(pop()));
      break;
    case EXP:
      push(exp(pop()));
      break;
    case POW:
    {
      double op2 = pop();
      push(pow(pop(), op2));
    }
      break;
    case VAR:
      push((double)s[0]);
      break;
    case '\n':
      printf("\t%.8lf\n", pop());
      break;
    default:
      printf("error: unknown command %s", s);
      break;
    }
  }

  return 0;
}

int getop(char s[])
{
  int c;

  while ((s[0] = c = buf[bufp++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return (isupper(c) ? VAR : c);
  int i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = buf[bufp++]))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = buf[bufp++]))
      ;
  s[i] = '\0';
  if (c != EOF)
    buf[--bufp] = c;
  return NUMBER;
}

void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %lf\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  printf("error: stack empty\n");
  return 0.0;
}

double setvar(double val, char var)
{
  if (isupper(var))
    return vars[var - 'A'] = val;
  printf("setvar: unknown variable %c", var);
  return 0.0;
}

double getvar(char var)
{
  if (isupper(var))
    return vars[var - 'A'];
  printf("getvar: unknown variable %c", var);
  return 0.0;
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