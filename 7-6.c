#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int comparefile(char* file1, char* file2, char** file1line, char** file2line);

int main(int argc, char* argv[])
{
  if (--argc < 2)
  {
    printf("\tUsage: %s <file1> <file2>\n", *argv);
    return 0;
  }
  else
  {
    ++argv;
    char* l1, * l2;
    int i = comparefile(argv[0], argv[1], &l1, &l2);
    if (i < 0)
      printf("file is equals\n");
    else
      printf("%s\n%s\n(max 1000 characters)\n", l1, l2);
  }

  return 0;
}

int comparefile(char* file1, char* file2, char** file1line, char** file2line)
{
  FILE* file1p = fopen(file1, "r");
  if (file1p == NULL)
    return -1;
  FILE* file2p = fopen(file2, "r");
  if (file2p == NULL)
  {
    fclose(file1p);
    return -1;
  }
  char buf1[MAXLINE];
  char buf2[MAXLINE];
  for (int i = 0;
       fgets(buf1, MAXLINE, file1p) != NULL &&
       fgets(buf2, MAXLINE, file2p) != NULL;
       ++i)
  {
    if (strcmp(buf1, buf2) != 0)
    {
      *file1line = buf1;
      *file2line = buf2;
      fclose(file1p);
      fclose(file2p);
      return i;
    }
    if (buf1[strlen(buf1) - 1] != '\n' ||
        buf2[strlen(buf2) - 1] != '\n')
      --i;
  }
  fclose(file1p);
  fclose(file2p);
  return -1;
}