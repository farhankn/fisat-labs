#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char path[50], pattern[50], str[1000], temp[100];
  char *res;
  struct stat sb;
  int ptr, i, k;

  strcpy(pattern, argv[1]);
  strcpy(path, argv[2]);

  ptr = open(path, O_RDONLY);

  fstat(ptr,&sb);
  
  read(ptr, str, sb.st_size);

  //printf("%s", str);

 for(i = 0; i < strlen(str); i++)
    {
      k=0;
      while(str[i] != '\n')
	{
	  temp[k] = str[i];
	  i++;
	  k++;
	}
      temp[k] = '\0';

      //printf("%s\n", temp);
      res = strstr(temp, pattern);
      
      if(res)
	printf("\n%s", temp);


    }

 printf("\n\n");
 

  return 0;
}
