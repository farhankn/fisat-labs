//program to find the factorial of a number
#include<stdio.h>
main()
{
  int a,i,fact=1;
  printf("\nEnter a number");
  scanf("%d",&a);
  if(a==0)
    printf("\nFactorial is %d",fact);
  for(i=1;i<=a;i++)
    fact*=i;
  printf("\nThe factorial of %d is %d",a,fact);
}
