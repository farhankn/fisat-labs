#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char src[100], dest[100], str[500]="testtestteast", ctrl[100] = "chmod 777 ";
  int ptr1, ptr2;
  struct stat sb;


  //printf("\n%s", argv[1]);
  //printf("\n%s", argv[2]);


  strcpy(src, argv[1]);
  strcpy(dest, argv[2]);

  printf("\n%s", src);
  printf("\n%s", dest);

  
  ptr1 = open(src, O_RDONLY);
  ptr2 = open(dest, O_RDWR|O_CREAT);

  fstat(ptr1, &sb);

  read(ptr1, str, sb.st_size);
  write(ptr2, str, sb.st_size);

  //strcat(ctrl,dest);
  //printf("%s", ctrl);

  return 0;
}
