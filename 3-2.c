#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
  char t[] = "hello\twor\nld!";
  char s[32];
  char t2[32];
  escape(s, t);
  printf("s:%s t:%s\n\n", t, s);
  unescape(t2, s);
  printf("s:%s t:%s\n\n", s, t2);

  return 0;
}

void escape(char s[], char t[])
{
  int j = 0;
  for (int i = 0; t[i] != '\0'; ++i, ++j)
  {
    switch (t[i])
    {
      case '\n':
        s[j++] = '\\';
        s[j] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j] = 't';
        break;
      default:
        s[j] = t[i];
        break;
    }
  }
  s[j] = '\0';
}

void unescape(char s[], char t[])
{
  int j = 0;
  for (int i = 0; t[i] != '\0'; ++i, ++j)
  {
    switch (t[i])
    {
      case '\\':
        if (t[i + 1] == 'n')
        {
          s[j] = '\n';
          ++i;
          break;
        }
        else if (t[i + 1] == 't')
        {
          s[j] = '\t';
          ++i;
          break;
        }
        // break;
      default:
        s[j] = t[i];
        break;
    }
  }
  s[j] = '\0';
}