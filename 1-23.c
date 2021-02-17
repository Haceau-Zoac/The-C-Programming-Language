#include <stdio.h>

#define MAXLINE 1024
#define OUT_REMARK 1
#define IN_REMARK  2
#define OUT_STRING 4
#define IN_STRING  8

void remove_remark(char s[]);
int getline(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (getline(s, MAXLINE) != 0)
  {
    remove_remark(s);
    printf("%s", s);
  }

  return 0;
}

void remove_remark(char s[])
{
  int flag = OUT_REMARK | OUT_STRING;
  for (int i = 0; s[i] != '\0'; ++i)
  {
    if (s[i] == '"' && !(flag & IN_REMARK))
    {
      if (flag & OUT_STRING)
      {
        flag ^= OUT_STRING;
        flag |= IN_STRING;
      }
      else
      {
        flag ^= IN_STRING;
        flag |= OUT_STRING;
      }
    }
    if (flag & OUT_REMARK && !(flag & IN_STRING) && i >= 1 && (s[i] == '*' && s[i - 1] == '/'))
    {
      flag ^= OUT_REMARK;
      flag |= IN_REMARK;
      s[i] = ' ';
      s[i - 1] = ' ';
    }
    else if (flag & IN_REMARK)
    {
      if (s[i] == '*' && s[i + 1] == '/')
      {
        flag ^= IN_REMARK;
        flag |= OUT_REMARK;
        s[i] = ' ';
        s[i + 1] = ' ';
      }
      else
        s[i] = ' ';
    }
  }
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