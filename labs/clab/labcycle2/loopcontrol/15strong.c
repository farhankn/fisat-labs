//program to find the factorial of a number
#include<stdio.h>
main()
{
  int n,i,fact=1,r,s=0;
  printf("\nEnter a number");
  scanf("%d",&n);
  for(i=n;i>0;i/10)
   {
    r=i%10;
    for(i=1;i<=r;i++)
     fact*=i;
    s+=fact;
   }
  if(s==n)
   printf("%d is a strong number",n);
  else
   printf("%d is not a strong number",n);
}
