#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
  DIR *ptr;
  struct dirent *test;
  struct stat sb;
  char dir[100];

  scanf("%s", dir);
  printf("%s", dir);

  ptr = opendir(dir);

  while(test = readdir(ptr))
    {
      printf("%s\t%d\n", test->d_name, test->d_reclen);
    }

  return 0;
}
