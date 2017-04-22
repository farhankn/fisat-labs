#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
  int fd, length, i;
  char *ptr, c;
  struct stat sb;

  printf("%s",(argv[0]));
  printf("%s",(argv[1]));
  printf("%s",(argv[2]));

  fd = shm_open(argv[1], O_RDONLY, S_IWUSR|S_IRUSR);

  fstat(fd, &sb);

  ptr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

  for(i = 0; i < sb.st_size; i++)
    {
      c = *ptr;
      printf("\n%d", (int)c);
      ptr++;
    }



  return 0;
}
