#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF)
  {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }

  printf("%d %d %d\n", nl, nw, nc);
}

/*
  你准备如何测试单词计数程序？
    脸滚键盘（雾）
  如果程序中存在某种错误，那么什么样的输入最可能发现这类错误呢？
    边界输入（比如罕见的 Unicode 字符）
*/