#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
  struct stat sb;
  char path[100];
  int ptr;

  
  strcpy(path, argv[1]);
  ptr = open(path, O_RDONLY);

  fstat(ptr, &sb);

  printf("\n User ID : %d", sb.st_uid);
  printf("\n Size : %d", sb.st_size);
  printf("\n Block Size : %d", sb.st_blksize);
  printf("\n Access Time : %s", ctime(&sb.st_atime));
  printf("\n Modification Time : %s", ctime(&sb.st_mtime));
  printf("\n Status Changed Time : %s", ctime(&sb.st_ctime));

  return 0;
}
