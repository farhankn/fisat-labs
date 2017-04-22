#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
  char src[100];
  DIR *ptr;
  struct dirent *test;

  scanf("%s", src);

  printf("debug");

  printf("%s", src);

  printf("hello");

  ptr = opendir(src);

  while(test = readdir(ptr))
    printf("%s\t%s\n", test->d_name, test->d_reclen);
  
  return 0;
}
