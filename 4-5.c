#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> // atof

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define SIN 's'
#define EXP 'e'
#define POW 'p'

int getop(char s[]);
void push(double f);
double pop(void);
int getch(void);
void ungetch(int c);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
  int type;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
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

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;
  int i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
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

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}