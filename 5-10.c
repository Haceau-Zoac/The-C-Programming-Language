#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 1024
#define NUMBER '0'
#define ERROR_OK 0
#define ERROR_DIV_ZERO 1
#define ERROR_UNKNOWN_OPERATOR 2

double stack[MAXSTACK];
int stackp = 0;

int calc(double* val, char op, double left, double right);
char getop(char* op, double* val);
int push(double val);
int pop(double* val);

int main(int argc, char* argv[])
{
  if (argc < 2)
    printf("\tUsage: %s argv", *argv);
  else
  {
    while (++argv)
    {
      double val = 0;
      char op = getop(argv, &val);
      if (op != NUMBER)
      {
        double rights, lefts;
        if (!pop(&rights) || !pop(&lefts))
        {
          printf("[ERROR] 操作数过少。\n");
          return 0.0;
        }
        double val;
        int ret = calc(&val, op, lefts, rights);
        switch (ret)
        {
          case ERROR_DIV_ZERO:
            printf("[ERROR] 除数不可为0。\n");
            return 0;
          case ERROR_UNKNOWN_OPERATOR:
            printf("[ERROR] 未知的运算符 %c。\n", op);
            return 0;
        }
        if (!push(val))
        {
          printf("[ERROR] 表达式过于复杂。\n");
          return 0;
        }
      }
      else if (!push(val))
      {
        printf("[ERROR] 表达式过于复杂。\n");
        return 0;
      }
    }
    double val;
    pop(&val);
    printf("%lf\n", val);
  }
  return 0;
}


int calc(double* val, char op, double left, double right)
{
  switch (op)
  {
  case '+':
    *val = left + right;
    return ERROR_OK;
  case '-':
    *val = left - right;
    return ERROR_OK;
  case '*':
    *val = left * right;
    return ERROR_OK;
  case '/':
    if (right == 0)
      return ERROR_DIV_ZERO;
    *val = left / right;
    return ERROR_OK;
  default:
    return ERROR_UNKNOWN_OPERATOR;
  }
}

char getop(char* op, double* val)
{
  if (op == NULL)
    return EOF;
  int len = strlen(op);
  if (len < 0)
    return EOF;
  if (!isdigit(*op))
    return *op;
  *val = atof(op);
  return NUMBER;
}

int push(double val)
{
  if (stackp >= MAXSTACK) return 0;
  stack[stackp++] = val;
  return 1;
}

int pop(double* val)
{
  if (stackp <= 0) return 0;
  *val = stack[--stackp];
  return 1;
}