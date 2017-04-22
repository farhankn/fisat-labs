#include<stdio.h>
main()
{
  int number,power,i,result=1;
  printf("Enter Number ");
  scanf("%d",&number);
  printf("Enter Power");
  scanf("%d",&power);
  for(i=1 ; i<=power; i++)
   {
     result=result*number;
   }
  printf("\n %d^%d is %d\n",number,power,result);
}
