#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
  int fd, length, i;
  char *ptr;

  fd = shm_open(argv[1], O_RDWR|O_CREAT, S_IWUSR|S_IRUSR);
  length = atoi(argv[2]);

  ftruncate(fd, length);

  ptr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

  for(i = 0; i < length; i++)
    {
      *ptr++ = i;
    }


  printf("%u", ptr);

  return 0;
}
