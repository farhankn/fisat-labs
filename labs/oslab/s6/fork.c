#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void main()
{
  int temp;
  temp = fork();
  if(temp==0)
    {
      printf("\n\t\t I am child");
      printf("\n\t\t Child's Parent ID: %d",getppid());
      printf("\n\t\t Child Own ID: %d",getpid());
    }
  else
    {
      printf("\n\t\t I am Parent");
      printf("\n\t\t Parent's ID: %d",getpid());
      printf("\n\t\t Parent's Child ID: %d\n\n",temp);
    }
  wait(NULL);
}

