/*Menu driven program to generate Fibonacci series and factorial*/
#include<stdio.h>
void fact();
void fibo();
main()
{
  int n;
  do
    {
        printf("Choose a number to do the following: (3 to stop)\n1:To find fibonacci\n2:To find factorial\n");
	scanf("%d",&n);
	switch(n)
	  {
	  case 1:
	    fibo(); 
	    break;
          case 2:
	    fact(); 
	    break;
          default: printf("Invalid number\n");
	  }
           
    }while(n!=3);
  printf("exiting\n");
}
 
 
void fact()
{
  int i,j,n,f;
  printf("Enter the number ");
  scanf("%d",&n);
  f=1;
  for(i=1;i<=n;i++)
    f=f*i;
  printf("Factorial of %d is %d\n",n,f);
}

void fibo()
{
  int a=0,b=1,i,n,c;
  printf("Enter the number of terms ");
  scanf("%d",&n);
  printf("%d\t%d\t",a,b);
  for(i=2;i<n;i++)
    {
      c=a+b;
      a=b;
      b=c;
      printf("%d\t",c);
    }
  printf("\n");
}

             
  
