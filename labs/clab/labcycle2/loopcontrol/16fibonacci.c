//program to find the Fibonacci series 
#include<stdio.h>
main()
{
  int c,a=0,b=1,n,i;
  printf("\nEnter a number");
  scanf("%d",&n);
  printf("\n%d, %d,",a,b);
  for(i=1;i<=n-2;i++)
   {
     c=a+b;
     printf("%d,",c);
     a=b;
     b=c;
   }
}