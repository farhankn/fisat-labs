#include<stdio.h>
main()
{
  int i,r,j;
  printf("Enter an integer to find Multiplication Table ");
  scanf("%d",&i);
  printf("Enter the Range");
  scanf("%d",&r);
  for(j=1 ; j<=r; j++)
   {
    printf("%d * %d = %d \n",i,j,i*r);
   }
}