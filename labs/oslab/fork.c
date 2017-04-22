#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
  int temp;
  temp = fork();
  if(temp==0)
    {
      printf("\t I am child");
      printf("\t Child's Parent ID: %d",getppid());
      printf("\t Child Own ID: %d",getpid());
    }
  else
    {
      printf("\t I am Parent");
      printf("\t Parent's ID: %d",getpid());
      printf("\t Parent's Child ID: %d\n\n",temp);
    }
printf("\n");
}

