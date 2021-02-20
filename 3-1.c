#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void)
{
  int v[] = { 3, 4, 6, 8, 10 };
  printf("find 3 at %d\n", binsearch(3, v, 5));
  printf("find 7 at %d\n", binsearch(7, v, 5));
  printf("find 6 at %d\n", binsearch(6, v, 5));

  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low < high)
  {
    mid = (low + high) / 2;
    if (x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }
  // QAQ我原本是 return (x == v[mid]) ? mid : -1; 来着
  // 下行来自 https://github.com/ccpalettes/the-c-programming-language-second-edition-solutions/blob/master/Chapter3/Exercise%203-01/binsearch.c
  return (x == v[low]) ? low : -1;
}