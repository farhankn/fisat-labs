#include<stdio.h>
main()
{
  int n,i,count=0;
  printf("Enter Number ");
  scanf("%d",&n);
  for(i=0 ; n>0; i++)
   {
    n=n/10;
    count++;
   }
  printf("\n Number has %d digits\n",count);
}
