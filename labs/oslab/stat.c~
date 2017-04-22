#include <stdio.h>
#include <fcntl.h>
#include <time.h>

int main()
{
  struct stat sb;
  char path[100];
  int ptr;
  printf("\nFilename: ");
  scanf("%s",&path);
  
  ptr = open(path, O_RDONLY);

  fstat(ptr, &sb);

  printf("\n Details of File : %s", path);
  printf("\n Size : %d", sb.st_size);
  printf("\n Block Size : %d", sb.st_blksize);
  printf("\n Access Time : %s", ctime(&sb.st_atime));
  printf("\n Modification Time : %s", ctime(&sb.st_mtime));
  printf("\n Status Changed Time : %s", ctime(&sb.st_ctime));

  return 0;
}
